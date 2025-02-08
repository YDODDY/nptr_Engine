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

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		// 바꾸고 그리고 하는 과정에서 selectObject 함수로 할 수 있지만 효율이 떨어지니까
		// HDC 를 하나 더 만들어서 덮어씌우는 형식으로 가보기
		HDC mBackHdc;
		// 비트맵(도화지): 압축 되어있지 않은 그림파일
		// 비트당 sturct(char R,G,B : 3 byte) 하나를 갖고 있는 2차원 배열 (ex.[1920][1080])
		HBITMAP mBackBuffer;

		// 해상도 
		UINT mWidth;
		UINT mHeight;

		// 플레이어에게 필요한 변수 ? 같은 것
//		float mX;
//		float mY;
		GameObject mPlayer;
		GameObject2 mPlayer2;
	};
}
