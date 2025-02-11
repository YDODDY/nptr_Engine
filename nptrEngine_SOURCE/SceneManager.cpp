#include "SceneManager.h"

namespace nptr
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::activeScene = nullptr;

	void SceneManager::Initialize()
	{
		
	}
	void SceneManager::Update()
	{
		activeScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		activeScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		activeScene->Render(hdc);
	}
}