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

	enum TekkenDiscordTimerState { passive, enable, disable };

	struct TekkenStatus
	{
		char const* details;
		char const* state;

		char const* largeText;
		char const* smallText;

		int gameMode;
		int currentGameState;

		int character = -1;
		int stage = -1;

		bool isGameRunning;
		bool isTimedState;

		long startTime;
	};

	std::map<int, std::string> InitGameModes();

	std::map<int, std::string> InitGameStates();

	std::map<int, std::string> InitStageMap();



	TekkenStatus FetchTekkenStatus();
}
