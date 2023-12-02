#include "tekken_discord_manager.h"

tekkendiscord::TekkenStatus tekkendiscord::FetchTekkenStatus()
{
	tekkendiscord::TekkenStatus tekkenStatus{};

	// TODO: Is in game.
	if (true)
	{
		tekkenStatus.state = "Game Mode"; // Should be the game mode.
		tekkenStatus.details = "Match State"; // Should be the state of the game.

		tekkenStatus.character = 0; // Character ID based on global side variable.
		tekkenStatus.stage = 0; // Stage should be filtered correctly.
	}

	 //TODO: Is game paused.
	if (false)
	{
		tekkenStatus.details = "Game Paused";
	}

	return tekkenStatus;
}



std::map<int, std::string> tekkendiscord::InitGameModes()
{
	std::map<int, std::string> gameModes;

	gameModes[0] = "Training Mode";
	gameModes[1] = "Arcade Mode";
	gameModes[2] = "Attract Mode";
	gameModes[5] = "Story Mode";
	gameModes[4] = "Online Match";
	gameModes[6] = "Versus Mode";
	gameModes[7] = "Customization Mode";
	gameModes[8] = "Character Story";
	gameModes[11] = "Treasure Battle";
	gameModes[15] = "Online Training Mode";
	gameModes[17] = "Ultimate Tekken Bowl";


	return gameModes;
}


std::map<int, std::string> tekkendiscord::InitGameStates()
{
	std::map<int, std::string> gameStates;

	gameStates[0] = "Introduction"; // For Player 1
	gameStates[1] = "Introduction"; // For Player 2
	gameStates[3] = "Round Start";
	gameStates[4] = "In-Battle";
	gameStates[5] = "Round End";
	gameStates[8] = "Match End";
	gameStates[21] = "In Training";
	gameStates[22] = "In Demonstration";


	return gameStates;
}

std::map<int, std::string> tekkendiscord::InitStageMap()
{
	std::map<int, std::string> stages;

	stages[0] = "Mishima Dojo";
	stages[1] = "Forgotten Realm";
	stages[2] = "Jungle Outpost";
	stages[3] = "Arctic Snowfall";
	stages[4] = "Twilight Conflict";
	stages[5] = "Dragon's Nest";
	stages[6] = "Souq";
	stages[7] = "Devil's Pit";
	stages[8] = "Mishima Building";
	stages[9] = "Abandoned Temple";
	stages[30] = "Duomo Di Sirio";
	stages[31] = "Arena";
	stages[32] = "G-Corp Helipad";
	stages[33] = "G-Corp Helipad (Night)";
	stages[35] = "Brimstone And Fire";
	stages[36] = "Precipice Of Fate";
	stages[37] = "Violet System";
	stages[39] = "Kinder Gym";
	stages[40] = "Infinite Azure";
	stages[41] = "Geometric Plane";
	stages[51] = "Howard Estate";
	stages[52] = "Hammerhead";
	stages[53] = "Jungle Outpost 2";
	stages[54] = "Twilight Conflict 2";
	stages[55] = "Infinite Azure 2";
	stages[56] = "Last Day On Earth";
	stages[57] = "Cave Of Enlightenment";
	stages[58] = "Vermilion Gates";
	stages[59] = "Island Paradise";

	return stages;
}
