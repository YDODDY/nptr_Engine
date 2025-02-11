#pragma once
#include "..\\nptrEngine_SOURCE\\SceneManager.h"
#include "PlayScene.h"

/*
#ifdef _DEBUG
#pragma comment(lib, "../../nptrEngine/nptrEngine_Window/x64/Debug/Debug.lib")
#else
#pragma comment(lib, "../../nptrEngine/nptrEngine_Window/x64/Debug/Debug.lib")
#endif
*/


namespace nptr
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}