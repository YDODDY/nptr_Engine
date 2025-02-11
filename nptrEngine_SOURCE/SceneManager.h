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

		// Scene �ٲٱ�
		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<std::wstring, Scene*>::iterator iter 
				= mScene.find(name);
			// iter �� �ƹ��͵� ������ -> end ���� (nullptr)
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
		// Ʈ��(��)���� Ȯ�� -> �̸� + ��
		static std::map<std::wstring, Scene*> mScene;
		static Scene* activeScene;
	};
}
