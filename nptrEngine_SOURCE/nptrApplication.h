#pragma once
#include "CommonInclude.h" 
#include "GameObject.h"
#include "GameObject2.h"

namespace nptr
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd); 
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;

		// �÷��̾�� �ʿ��� ���� ? ���� ��
//		float mX;
//		float mY;
		GameObject mPlayer;
		GameObject2 mPlayer2;
	};
}
