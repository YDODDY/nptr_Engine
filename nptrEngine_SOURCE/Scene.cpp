#include "Scene.h"

namespace nptr
{
	Scene::Scene()
		: mGameObjects{}
	{

	}
	Scene::~Scene()
	{

	}
	void Scene::Initialize()
	{
	}
	void Scene::Update()
	{
		// ������� for ��
		for (GameObject* gameobj : mGameObjects)
		{
			gameobj->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			gameobj->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameobj : mGameObjects)
		{
			gameobj->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}