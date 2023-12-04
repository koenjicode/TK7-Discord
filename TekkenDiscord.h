#pragma once
#include "Mod/Mod.h"
#include <tekken_discord_manager.h>
#include <ObjectProxy.h>

class TekkenDiscord : public Mod
{
public:

	//Basic Mod Info
	TekkenDiscord()
	{
		ModName = "TekkenDiscord"; // Mod Name -- If Using BP ModActor, Should Be The Same Name As Your Pak
		ModVersion = "1.0.1"; // Mod Version
		ModDescription = "Adds Discord Support to Tekken"; // Mod Description
		ModAuthors = "Koenji"; // Mod Author
		ModLoaderVersion = "2.2.1";

		// Dont Touch The Internal Stuff
		ModRef = this;
		CompleteModCreation();
	}

	//Called When Internal Mod Setup is finished
	virtual void InitializeMod() override;

	//InitGameState Call
	virtual void InitGameState() override;

	//Beginplay Hook of Every Actor
	virtual void BeginPlay(UE4::AActor* Actor) override;

	//PostBeginPlay of EVERY Blueprint ModActor
	virtual void PostBeginPlay(std::wstring ModActorName, UE4::AActor* Actor) override;

	//DX11 hook for when an image will be presented to the screen
	virtual void DX11Present(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, ID3D11RenderTargetView* pRenderTargetView) override;

	virtual void FetchAndUpdateDiscordStatus();

	void CheckIfLobbyValid(uintptr_t baseAddress);

	void UpdateInGame(uintptr_t baseAddress);

	void UpdateOutGame(uintptr_t baseAddress);

	void UpdateStageSelect(uintptr_t baseAddress);

	void UpdateCharacterSelect(uintptr_t baseAddress, TekkenOverlayCommon::DataAccess::ObjectProxy<int> character_select_p1, TekkenOverlayCommon::DataAccess::ObjectProxy<int> character_select_p2);

	void UpdateFallback();

	virtual void OnModMenuButtonPressed() override;

	virtual bool IsInMatch();

	virtual bool IsMultiplePlayerGameMode();

	//Call ImGui Here (CALLED EVERY FRAME ON DX HOOK)
	virtual void DrawImGui() override;

private:
	// If you have a BP Mod Actor, This is a straight refrence to it
	UE4::AActor* ModActor;
};