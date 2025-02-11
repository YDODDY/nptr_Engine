#pragma once
#include "Scene.h"

namespace nptr
{
	class SceneManager
	{
	public:

		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name,scene));
			return scene;
		}

		// Scene 바꾸기
		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<std::wstring, Scene*>::iterator iter 
				= mScene.find(name);
			// iter 가 아무것도 없으면 -> end 뱉음 (nullptr)
			if (iter == mScene.end())
				return nullptr;

			activeScene = iter->second;

			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
	//	static std::vector<Scene*> mScene;
		// 트리(맵)으로 확인 -> 이름 + 씬
		static std::map<std::wstring, Scene*> mScene;
		static Scene* activeScene;
	};
}
