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
		// �θ� �Լ� ȣ��
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