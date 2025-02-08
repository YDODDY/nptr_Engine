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

		// �ٲٰ� �׸��� �ϴ� �������� selectObject �Լ��� �� �� ������ ȿ���� �������ϱ�
		// HDC �� �ϳ� �� ���� ������ �������� ������
		HDC mBackHdc;
		// ��Ʈ��(��ȭ��): ���� �Ǿ����� ���� �׸�����
		// ��Ʈ�� sturct(char R,G,B : 3 byte) �ϳ��� ���� �ִ� 2���� �迭 (ex.[1920][1080])
		HBITMAP mBackBuffer;

		// �ػ� 
		UINT mWidth;
		UINT mHeight;

		// �÷��̾�� �ʿ��� ���� ? ���� ��
//		float mX;
//		float mY;
		GameObject mPlayer;
		GameObject2 mPlayer2;
	};
}
