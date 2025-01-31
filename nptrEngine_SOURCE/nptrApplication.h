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

		// 플레이어에게 필요한 변수 ? 같은 것
//		float mX;
//		float mY;
		GameObject mPlayer;
		GameObject2 mPlayer2;
	};
}
