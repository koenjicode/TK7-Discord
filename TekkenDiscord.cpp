#include "TekkenDiscord.h"
#include "Utilities/MinHook.h"
#include "discord.h"
#include <TekkenEntities.h>
#include <chrono>

discord::Core* core{};
tekkendiscord::TekkenStatus status{};
constexpr static int64_t applicationID = 1178519907953021148;
static std::map<int, std::string> tekkenStages;
static std::map<int, std::string> tekkenGameModes;
static std::map<int, std::string> tekkenGameStates;
static std::map<int, std::string> tekkenGameMenus;
static std::string const tekkenCharacters[] = {
	"Paul",
	"Law",
	"King",
	"Yoshimitsu",
	"Hwoarang",
	"Xiaoyu",
	"Jin",
	"Bryan",
	"Heihachi",
	"Kazyua",
	"Steve",
	"Jack-7",
	"Asuka",
	"Devil Jin",
	"Feng",
	"Lili",
	"Dragunov",
	"Leo",
	"Lars",
	"Alisa",
	"Claudio",
	"Katarina",
	"Lucky Chloe",
	"Shaheen",
	"Josie",
	"Gigas",
	"Kazumi",
	"Devil Kazumi",
	"Nina",
	"Master Raven",
	"Lee",
	"Bob",
	"Akuma",
	"Kuma",
	"Panda",
	"Eddy",
	"Eliza",
	"Miguel",
	"Tekken Force Grunt",
	"Young Kazuya",
	"Jack-4",
	"Young Heihachi",
	"Dummy",
	"Geese",
	"Noctis",
	"Anna",
	"Lei",
	"Armor King",
	"Marduk",
	"Julia",
	"Negan",
	"Zafina",
	"Ganryu",
	"Leroy",
	"Fahkumram",
	"Kunimitsu",
	"Lidia",
};

std::string versionNumber = "v2.2.0";

bool runDiscordPlugin;

template<typename ... Args>
std::string string_format(const std::string& format, Args ... args)
{
	size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
	if (size <= 0) { throw std::runtime_error("Error during formatting."); }
	std::unique_ptr<char[]> buf(new char[size]);
	snprintf(buf.get(), size, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

BPFUNCTION(WriteToFile)
{
	std::cout << "WriteToFile" << std::endl;
	struct InputParams
	{
		UE4::FString NameTest;
	};
	auto Inputs = stack->GetInputParams<InputParams>();
	stack->SetOutput<UE4::FString>("OutPutString", L"KboyGang");
	stack->SetOutput<bool>("ReturnValue", true);
}

// Only Called Once, if you need to hook shit, declare some global non changing values
void TekkenDiscord::InitializeMod()
{
	UE4::InitSDK();
	SetupHooks();

	REGISTER_FUNCTION(WriteToFile);

	tekkenStages = tekkendiscord::InitStageMap();
	tekkenGameStates = tekkendiscord::InitGameStates();
	tekkenGameModes = tekkendiscord::InitGameModes();
	tekkenGameMenus = tekkendiscord::InitGameMenus();

	auto result = discord::Core::Create(applicationID, DiscordCreateFlags_Default, &core);
	if (result == discord::Result::Ok)
	{
		runDiscordPlugin = true;
	}

	//MinHook::Init(); //Uncomment if you plan to do hooks

	UseMenuButton = true; // Allows Mod Loader To Show Button
}

void TekkenDiscord::InitGameState()
{
}

void TekkenDiscord::BeginPlay(UE4::AActor* Actor)
{
}

void TekkenDiscord::PostBeginPlay(std::wstring ModActorName, UE4::AActor* Actor)
{
	// Filters Out All Mod Actors Not Related To Your Mod
	std::wstring TmpModName(ModName.begin(), ModName.end());
	if (ModActorName == TmpModName)
	{
		//Sets ModActor Ref
		ModActor = Actor;
	}
}

void TekkenDiscord::DX11Present(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, ID3D11RenderTargetView* pRenderTargetView)
{
	if (runDiscordPlugin)
	{
		if (core)
		{
			FetchAndUpdateDiscordStatus();
			discord::Activity activity{};

			activity.SetState(status.state);
			activity.SetDetails(status.details);

			activity.GetParty().GetSize().SetCurrentSize(status.partySize);
			activity.GetParty().GetSize().SetMaxSize(status.partyMax);

			if (status.character > -1)
			{
				std::string s;
				s.append("chr_");
				s.append(std::to_string(status.character));

				activity.GetAssets().SetSmallImage(s.c_str());
				activity.GetAssets().SetSmallText(tekkenCharacters[status.character].c_str());
			}

			if (status.stage > -1)
			{
				std::string s2;
				if (tekkenStages.count(status.stage))
				{
					s2.append("stg_");
					s2.append(std::to_string(status.stage));

					activity.GetAssets().SetLargeText(tekkenStages[status.stage].c_str());
				}
				else
				{
					s2 = "fallback2";
				}

				activity.GetAssets().SetLargeImage(s2.c_str());
			}
			else
			{
				activity.GetAssets().SetLargeImage("fallback2");

				std::string text = string_format("T7Discord %s", versionNumber);
				activity.GetAssets().SetLargeText(text.c_str());
			}
			
			activity.GetTimestamps().SetStart(status.startTime);
			activity.SetType(discord::ActivityType::Playing);

			core->ActivityManager().UpdateActivity(activity, [](discord::Result res)
				{
					if (res != discord::Result::Ok)
					{
						std::cout << "There was an issue updating Discord!\n";
					}
				});

			core->RunCallbacks();
		}
	}
}

void TekkenDiscord::FetchAndUpdateDiscordStatus()
{
	UpdateFallback();

	uintptr_t baseAddress = (uintptr_t)GetModuleHandleA(nullptr);
	UpdateLobbyInformation(baseAddress);

	TekkenOverlayCommon::DataAccess::ObjectProxy<int> game_mode{ baseAddress, 0x379B158, 0x8, 0x8, 0x0 , 0x470 , 0x10 };

	// Check if we're bowling fr fr
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> saved_tekken_bowl_char{ baseAddress, 0x034D55A0, 0x0, 0x0, 0x10 };
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> tekken_bowl_char_instance_id{ baseAddress, 0x034CDFA8, 0x48, 0xE0, 0x28, 0x10, 0xC8, 0x68  };
	if (!status.bowling_snapshot)
	{
		if (game_mode.IsValid() && game_mode == 16 && saved_tekken_bowl_char.IsValid() && tekken_bowl_char_instance_id.IsValid())
		{
			if (saved_tekken_bowl_char == tekken_bowl_char_instance_id)
			{
				UpdateTekkenBowling(baseAddress);
				return;
			}
		}

		status.bowling_snapshot = true;
	}

	// Check if one character is spawned to begin with, if so we can check a few things.
	
	int p1_offset = 0x34DF630;
	if (game_mode.IsValid() && game_mode == 7 && IsPlayerSpawned(baseAddress, p1_offset))
	{
		UpdateCustomization(baseAddress);
		return;
	}


	if (IsInMatch(baseAddress))
	{
		UpdateInGame(baseAddress);
	}
	else
	{
		
		UpdateOutGame(baseAddress);
	}
}

void TekkenDiscord::UpdateTekkenBowling(uintptr_t baseAddress)
{
	StartTimer();

	status.state = "Ultimate Tekken Bowling";

	TekkenOverlayCommon::DataAccess::ObjectProxy<int> p2_saved_tekken_bowl_char{ baseAddress, 0x034D55A0, 0x0, 0x8, 0x10 };
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> p2_char_instance_id{ baseAddress, 0x034CDFA8, 0x48, 0xE0, 0x28, 0x10, 0xC8, 0x70 };
	if (p2_saved_tekken_bowl_char.IsValid() && p2_char_instance_id.IsValid() && p2_char_instance_id == p2_saved_tekken_bowl_char)
	{
		status.details = "Bowling Together";
	}
	else
	{
		status.details = "Bowling Alone";

		TekkenOverlayCommon::DataAccess::ObjectProxy<int> p1_tekken_bowl_char{ baseAddress, 0x034D55A0, 0x0, 0x0, 0x10 };
		status.character = p1_tekken_bowl_char;
	}
}

void TekkenDiscord::UpdateCustomization(uintptr_t baseAddress)
{

	status.state = "Customization Mode";

	TekkenOverlayCommon::DataAccess::ObjectProxy<bool> is_char_visible{ baseAddress , 0x34DF630 , 0x8 };
	if (is_char_visible)
	{
		StartTimer();

		TekkenOverlayCommon::DataAccess::ObjectProxy<int> char_p1{ baseAddress , 0x34DF630 , 0xD8 };
		status.details = "Customizing Character";
		status.character = char_p1;
	}
	else
	{
		UpdateOutGameFallback();

		status.details = "Selecting Character";
	}
}

void TekkenDiscord::UpdateInGame(uintptr_t baseAddress)
{
	StartTimer();


	// Ensure that the game mode is valid.
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> game_mode{ baseAddress, 0x379B158, 0x8, 0x8, 0x0 , 0x470 , 0x10 };
	if (!game_mode.IsValid() || !tekkenGameModes.count(game_mode))
	{
		status.state = "Unknown Game Mode";
		return;
	}

	// If Watching Replay: Display the replay text instead of the game mode.
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> menu_selected{ baseAddress,  0x34D5B50 };
	if (menu_selected == 8)
	{
		status.state = "Watching Replay";
	}
	else
	{
		if (status.lobby_valid)
		{
			status.state = "Player Match";
		}
		else
		{
			status.state = tekkenGameModes[game_mode].c_str();
		}
		
	}

	// If Unknown Game Mode: Safe to assume that we're waiting for something. So we'll just say waiting.
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> game_state{ baseAddress + 0x34CD4F4 };
	if (!tekkenGameStates.count(game_state))
	{
		status.details = "Waiting";
	}
	else
	{
		
		// If the game mode is non-round important game mode we don't show the round.
		if (game_mode == 0 || game_mode == 5 || game_mode == 15)
		{
			if (game_mode == 5)
			{
				TekkenOverlayCommon::DataAccess::ObjectProxy<int> story_chapter_count{ baseAddress, 0x34D6C10 , 0x28 , 0x9A4 };
				std::string text = string_format("Chapter %s: %s", std::to_string(story_chapter_count), tekkenGameStates[game_state]);
				status.details = text.c_str();
			}
			else if (game_mode == 15)
			{
				status.details = "Searching For Opponent";
			}
			else
			{
				status.details = tekkenGameStates[game_state].c_str();
			}
		}
		else
		{
			// Don't show a round zero lol
			TekkenOverlayCommon::DataAccess::ObjectProxy<int> round_count{ baseAddress + 0x34CD6E0 };
			if (round_count > 0)
			{
				std::string text = string_format("Round %s: %s", std::to_string(round_count), tekkenGameStates[game_state]);
				status.details = text.c_str();
			}
			else
			{
				status.details = tekkenGameStates[game_state].c_str();
			}
		}

		// We only grab side information once to prevent issues, every single time waiting gets called we reset it.
		if (!status.side_snapshot_taken)
		{
			// Versus mode we don't need any of the specific character information.
			if (IsMultiplePlayerGameMode())
			{
				status.character = -1;
			}
			else
			{
				// Change Character Icon based on player side information.
				TekkenOverlayCommon::DataAccess::ObjectProxy<bool> are_sides_reversed_online{ baseAddress + 0x34DF554 };
				TekkenOverlayCommon::DataAccess::ObjectProxy<bool> is_player_right_side{ baseAddress + 0x344788C };
				TekkenOverlayCommon::DataAccess::ObjectProxy<int> char_p1{ baseAddress , 0x34DF630 , 0xD8 };
				TekkenOverlayCommon::DataAccess::ObjectProxy<int> char_p2{ baseAddress , 0x34DF628 , 0xD8 };
				int player_char;

				// If we're playing online we need to check if sides have been reversed.
				if (game_mode != 4)
				{
					player_char = !is_player_right_side ? char_p1 : char_p2;
				}
				else
				{
					if (are_sides_reversed_online)
					{
						player_char = !is_player_right_side ? char_p2 : char_p1;
					}
					else
					{
						player_char = !is_player_right_side ? char_p1 : char_p2;
					}

				}

				status.character = player_char;
			}

			status.character_saved = status.character;
			status.side_snapshot_taken = true;
		}
	}

	// Change Stage Icon based on stage information.
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> stage_id{ baseAddress + 0x34DF550 };
	status.stage = stage_id;
	status.currentGameState = game_state;
}

void TekkenDiscord::StartTimer()
{
	// Enable a timer as soon as we enter in a match.
	if (!status.timerEnabled)
	{
		status.startTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		status.timerEnabled = true;
	}
}

void TekkenDiscord::UpdateOutGame(uintptr_t baseAddress)
{
	// Update Fallback
	UpdateOutGameFallback();

	TekkenOverlayCommon::DataAccess::ObjectProxy<int> character_select_p1{ baseAddress,  0x034D65C0, 0x508 };

	TekkenOverlayCommon::DataAccess::ObjectProxy<int> character_select_p2{ baseAddress,  0x034D65C0, 0x948 };

	if (character_select_p1.IsValid() && character_select_p2.IsValid())
	{
		UpdateCharacterSelect(baseAddress, character_select_p1, character_select_p2);
	}
	else
	{
		UpdateStageSelect(baseAddress);
	}
}

void TekkenDiscord::UpdateCharacterSelect(uintptr_t baseAddress, TekkenOverlayCommon::DataAccess::ObjectProxy<int> character_select_p1, TekkenOverlayCommon::DataAccess::ObjectProxy<int> character_select_p2)
{
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> menu_selected{ baseAddress,  0x34D5B50 };

	if (status.lobby_valid)
	{
		status.state = "Player Match";
	}
	else
	{
		status.state = tekkenGameMenus[menu_selected].c_str();
	}

	

	// Check for special case game modes
	if (menu_selected == 5 || menu_selected == 28)
	{
		// Check if the game mode is bowling or versus
		if (menu_selected == 28)
		{
			status.details = "Character Select";

			// If they're bowling alone show the character they're selecting.
			if (character_select_p1 != 255 && character_select_p2 == 255)
			{
				status.details = "Character Select";
				status.character = character_select_p1;
				status.character_saved = status.character;
			}
		}
		else
		{
			status.details = "Character Select";
		}

		status.side_saved = -1;
	}
	else
	{

		// If both values are 255, then we're selecting a side.
		if (character_select_p1 == 255 && character_select_p2 == 255)
		{
			status.details = "Side Select";
			status.side_saved = -1;
		}
		else
		{
			// We save the player side the first time the player backs into the character select.
			// This is done to fix my P2 glitch in this code.
			if (status.side_saved < 0)
			{
				status.side_saved = character_select_p1 != 255 ? 0 : 1;
			}

			status.details = "Character Select";
			status.character = status.side_saved == 0 ? character_select_p1 : character_select_p2;

			// We save the character for any information that needs it.
			status.character_saved = status.character;
		}
	}
}

void TekkenDiscord::UpdateStageSelect(uintptr_t baseAddress)
{
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> menu_selected{ baseAddress,  0x34D5B50 };

	TekkenOverlayCommon::DataAccess::ObjectProxy<int> stage_select{ baseAddress,  0x034D6918, 0x188 };
	if (stage_select.IsValid())
	{
		status.details = "Stage Select";
		if (status.lobby_valid)
		{
			status.state = "Player Match";
		}
		else
		{
			status.state = tekkenGameMenus[menu_selected].c_str();
		}

		status.stage = stage_select;
		
		// Don't show a character if we're in versus mode.	
		if (menu_selected != 5)
		{
			status.character = status.character_saved;
		}
		else
		{
			status.character = -1;
		}
		
	}
}

void TekkenDiscord::UpdateFallback()
{
	// If we've taken a snapshot of the bowling state, don't bother updating this.
	if (status.bowling_snapshot)
	{
		return;
	}

	if (status.lobby_valid)
	{
		status.state = "Player Match";
	}
	else
	{
		status.state = "";
	}

	status.details = "Waiting";

	if (!status.side_snapshot_taken)
	{
		status.character = -1;
	}
	
	status.stage = -1;
	status.gameMode = -1;
}

void TekkenDiscord::UpdateOutGameFallback()
{
	status.timerEnabled = false;
	status.side_snapshot_taken = false;
	status.bowling_snapshot = false;
	status.startTime = 0;
}

void TekkenDiscord::UpdateLobbyInformation(uintptr_t baseAddress)
{
	int base_lobby_offset = 0x510;
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> lobby_size{ baseAddress,  0x034D6898, base_lobby_offset };
	if (lobby_size.IsValid())
	{
		int current_players_offset = base_lobby_offset - 0xC0;
		TekkenOverlayCommon::DataAccess::ObjectProxy<int> current_players{ baseAddress,  0x034D6898, current_players_offset };

		status.partySize = current_players;
		status.partyMax = lobby_size;

		status.lobby_valid = true;
	}
	else
	{
		status.partySize = 0;
		status.partyMax = 0;

		status.lobby_valid = false;
	}
}

void TekkenDiscord::OnModMenuButtonPressed()
{
	Log::Print("Printing Base Address");
	uintptr_t baseAddress = (uintptr_t)GetModuleHandleA(nullptr);
	Log::Print("%04x", baseAddress);

	Log::Print("Move Pointer Base Address");
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> move_pointer_p1{ baseAddress, 0x34DF630, 0x218, 0x0 };
	if (move_pointer_p1.IsValid())
	{
		Log::Print("%04x", move_pointer_p1);
		Log::Print(std::to_string(move_pointer_p1));
	}
	else
	{
		Log::Print("Pointer is not valid, will crash your game!");
	}

	Log::Print("Printing Epoch Time");
	Log::Print(std::to_string(status.startTime));

	TekkenOverlayCommon::DataAccess::ObjectProxy<int> round_count{ baseAddress + 0x34CD6E0 };
	Log::Print("Round Count");
	Log::Print(std::to_string(round_count));
	
	
	Log::Print("Printing Current Stage ID");
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> stage_id{ baseAddress + 0x34DF550 };
	Log::Print(std::to_string(stage_id));

	TekkenOverlayCommon::DataAccess::ObjectProxy<int> local_player_side{ baseAddress + 0x344788C };
	Log::Print("Local Player Side");
	Log::Print(std::to_string(local_player_side));

	TekkenOverlayCommon::DataAccess::ObjectProxy<int> player_char;
	if (local_player_side == 0)
	{
		player_char = { baseAddress , 0x34DF630 , 0xD8 };
	}
	else
	{
		player_char = { baseAddress , 0x34DF628 , 0xD8 };
	}
	
	Log::Print("Player Character With Offset");
	Log::Print(std::to_string(player_char));

	std::string s;
	s.append("chr_");
	s.append(std::to_string(status.character));
	Log::Print(s);

	std::string s2;
	s2.append("stg_");
	s2.append(std::to_string(status.stage));
	Log::Print(s2);



}

bool TekkenDiscord::IsPlayerSpawned(uintptr_t baseAddress, uintptr_t playerOffset)
{
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> move_pointer{ baseAddress, playerOffset, 0x218, 0x0 };
	if (!move_pointer.IsValid() || move_pointer == 0 || move_pointer == -1)
	{
		return false;
	}

	TekkenOverlayCommon::DataAccess::ObjectProxy<int> move_anim_pointer{ baseAddress, playerOffset, 0x218, 0x10, 0x0 };
	if (!move_anim_pointer.IsValid() || move_anim_pointer == 0 || move_anim_pointer == -1)
	{
		return false;
	}

	return true;
}

bool TekkenDiscord::IsInMatch(uintptr_t baseAddress)
{
	int playerOffset[2] = { 0x34DF630, 0x34DF628};
	if (!IsPlayerSpawned(baseAddress, playerOffset[0]))
	{
		return false;
	}

	if (!IsPlayerSpawned(baseAddress, playerOffset[1]))
	{
		return false;
	}

	return true;
}

bool TekkenDiscord::IsMultiplePlayerGameMode()
{
	uintptr_t baseAddress = (uintptr_t)GetModuleHandleA(nullptr);
	TekkenOverlayCommon::DataAccess::ObjectProxy<int> game_mode{ baseAddress, 0x379B158, 0x8, 0x8, 0x0 , 0x470 , 0x10 };
	return game_mode == 6 || game_mode == 2;
}


void TekkenDiscord::DrawImGui()
{
	
}