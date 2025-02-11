#include "PlayScene.h"
#include "GameObject.h"

namespace nptr
{
	PlayScene::PlayScene()
	{

	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{
		GameObject* objc = new GameObject();
		AddGameObject(objc);
	}
	void PlayScene::Update()
	{
		// 부모 함수 호출
		Scene::Update();

	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

	}
}