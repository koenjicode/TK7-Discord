#pragma once
#include <string>
#include <map>

namespace tekkendiscord
{

	namespace offset 
	{
		constexpr uintptr_t player_offset = 0x34DF630;
		constexpr uintptr_t char_id = 0xD8;
		constexpr uintptr_t player_struct_size = 0x3670;

		constexpr uintptr_t local_player_side = 0x344788C;

		constexpr uintptr_t global2 = 0x34DF550;
		constexpr uintptr_t stage_id = 0x0;
		constexpr uintptr_t player_side = 0x4;
	}

	enum TekkenCharacter 
	{
		Paul,
		Law,
		King,
		Yoshimitsu,
		Hwoarang,
		Xiaoyu,
		Jin,
		Bryan,
		Heihachi,
		Kazyua,
		Steve,
		Jack7,
		Asuka,
		DevilJin,
		Feng,
		Lili,
		Dragunov,
		Leo,
		Lars,
		Alisa,
		Claudio,
		Katarina,
		LuckyChloe,
		Shaheen,
		Josie,
		Gigas,
		Kazumi,
		DevilKazumi,
		Nina,
		MasterRaven,
		Lee,
		Bob,
		Akuma,
		Kuma,
		Panda,
		Eddy,
		Eliza,
		Miguel,
		TekkenForceGrunt,
		YoungKazuya,
		Jack4,
		YoungHeihachi,
		Dummy,
		Geese,
		Noctis,
		Anna,
		Lei,
		ArmorKing,
		Marduk,
		Julia,
		Negan,
		Zafina,
		Ganryu,
		Leroy,
		Fahkumram,
		Kunimitsu,
		Lidia
	};

	enum TekkenGameMode
	{
		Training,
		Arcade,
		Attract,
		Online = 4,
		Story,
		Versus,
		Customization,
		CharacterStory,
		TreasureBattle = 11,
		OnlineTraining = 15,
		UltimateTekkenBowl = 17,
	};

	enum TekkenGameState
	{
		Player1Intro,
		Player2Intro,
		RoundStart = 3,
		InProgress,
		RoundEnd,
		MatchEnd = 8,
		InTraining = 21,
		InDemonStration
	};

	enum TekkenStage
	{
		MishimaDojo,
		ForgottenRealm,
		Jungle,
		Arctic,
		Twlight,
		DragonNest,
		Souq,
		DevilPit,
		MishimaBuilding,
		AbandonedTemple,
		DuomoDiSirio = 30,
		Arena,
		Helipad,
		HelipadNight,
		Brimstone = 35,
		Precipice,
		VioletSystem,
		KinderGym = 39,
		InfiniteAzure,
		GeometricPlane,
		HowardEstate = 51,
		HammerHead,
		Jungle2,
		Twilight2,
		InfiniteAzure2,
		LastDay,
		CaveOfEnlightenment,
		VermillionGates,
		IslandParadise
	};

	struct TekkenStatus
	{
		char const* details;
		char const* state;

		char const* largeText;
		char const* smallText;

		int gameMode;
		int currentGameState;
		int side_saved;

		int character;
		int opponentCharacter;
		int stage;

		bool isGameRunning;
		bool isTimedState;

		long startTime;
	};

	std::map<int, std::string> InitGameMenus();

	std::map<int, std::string> InitGameModes();

	std::map<int, std::string> InitGameStates();

	std::map<int, std::string> InitStageMap();
}
