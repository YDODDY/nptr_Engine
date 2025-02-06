#include "nptrApplication.h"
#include "GameObject.h"
#include "Input.h"
#include "Time.h"

namespace nptr
{   
    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mWidth(0)
        , mHeight(0)
        , mBackHdc(NULL)
        , mBackBuffer(NULL)
    {

    }
    Application::~Application()
    {

    }

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		// �ڵ�, DC �޾Ƶα� - ��� �������� �ʰ� �޾Ƽ� ���
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
        mPlayer.SetPosition(0, 0);
    //    mPlayer2.SetPosition(300, 300);


        // ������ ��� ������ ��ũ�� �� ���� ���� �� ���� �۾� ������ �˾ƾ� �Ѵ�.
        RECT rect = {0,0,width, height};
        // ������ - ���� : ���α���
        mWidth = rect.right - rect.left;
        // �Ʒ� - �� : ���α���
        mHeight = rect.bottom - rect.top;

        // �۾����� ũ�⸦ width, height ������ ����
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
        ShowWindow(mHwnd, true);
        SetWindowPos(mHwnd, nullptr, 0, 0,
            mWidth, mHeight, 0);

        // HDC �� �̹��� ���� �� �����
        mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

        // �޸� �� ���� ���� ���̱� (�޸� ���̰� ���� �ø��� X)
        // ����� ����ų DC ����
        mBackHdc = CreateCompatibleDC(mHdc);

        // ����
        HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
        // ������ �����
        DeleteObject(oldBitmap);

        Input::Initialize();
        Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
  //      mSpeed += 0.01f;
/*

        // ���� ������ Ű�� �Է� �޾Ҵٸ� x ��ǥ + 
        // �� x ��ǥ -
        // ���Ʒ��� y ��ǥ -+

        float x = mPlayer.GetPositionX();
        float y = mPlayer.GetPositionY();
        // Ű ���� üũ�ϴ� �Լ� 
        // ��                         Microsoft : 0x8000 ������� �ؼ� �ִ� �� 
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            x -= 0.01f;
        }  
        // ��
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            x += 0.01f;
        }    
        // WINDOW ��ǥ�迡�� ���� y--, �Ʒ��� y++
        // ��
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            y -= 0.01f;
        }    
        // �Ʒ�
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            y += 0.01f;
        }
        mPlayer.SetPosition(x, y);
*/
        // GameObject

        // Ű�Է� �ް� �÷��̾� ���� ������
        Input::Update();
        Time::Update();

        mPlayer.Update();
  //      mPlayer2.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
        // ���� ���۸�
        // HDC �� �ΰ� ����Ͽ� �׸��� '����� ����' �� �����. 
        // �׸��� �ٲٰ� �׸��� �ٲٰ� 

        Rectangle(mBackHdc, 0, 0, 1600, 900);

        Time::Render(mBackHdc);

        // GameObject
        mPlayer.Render(mBackHdc);
  //      mPlayer2.Render(mHdc);
        /*
        // HPEN newPen, oldPen  :  �ڵ� �����(����)
        // -> newPen = CreatePen(...)  :  GDI ������Ʈ �����(���� �������� �Ҵ��)
        // -> oldPen = SelectObject(DC, newPen)  :  DC �� �����ϵ� �̶� ���� �ڵ��� �ݵ�� ����(����Ʈ �ڵ�)
        // -> Rectangle, Ellipse, ..             :  ������ �� Ȥ�� ���� ���
        // -> SelectObject(DC, oldPen)           :  ���� ����(���� ����Ʈ �� or �������� �ʱ�ȭ)
        // -> DeleteObject(newPen)               :  ������� �� or ���� ���� (���� ���� �Ҵ��� �޸� ����)

        // DC (Device Context) : ȭ�� ��¿� �ʿ��� ��� ������ ������ ������ ����ü
        // GDI ��⿡ ���ؼ� ������ 
        // ��Ʈ, ���� ����, ���� ��.. 
        // ȭ�� ��¿� �ʿ��� ��� ���� WINAPI ������ DC �� ���ؼ� �۾��� ������.

        // ������Ʈ ��� ����
        // ���� ����� - RGB �������ڰ�, �޸𸮸� �߰��� �Ҵ��Ŵ(���� �����Ҵ�!)
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
        // ���� �Ķ��� �귯�� DC �� �����ϰ�, ��� �귯�� ��ȯ�ؼ� �ӽú����� ����
        HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);

        // ������Ʈ �� ���� + ��Ÿ��
        //HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
        // ���� ���� ���� �� ���� �� ���� ����Ʈ ���� ��ȯ 
        //HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

        // �� �׸��� -> �׸�׸��⿡�� �׸� �ȿ� ���� �׷�����.                    //////// �Ͼ��
        //Ellipse(mHdc, 200, 200, 300, 300);

        // ���� ����Ʈ ������ �ٽ� ����
        //SelectObject(mHdc, oldPen);

        float x = mPlayer.GetPositionX();
        float y = mPlayer.GetPositionY();
        // ������â�� �׸� �׸��� -> 0,0(������ܺ���) ���� ���� �������ڷ� ����. //////// �Ķ���
        Rectangle(mHdc, 100 + x, 100 + y, 200 + x, 200 + y);

        // ���� DC �� ��� �귯�� ����
        (HBRUSH)SelectObject(mHdc, oldBrush);
        // �����Ҵ� ���Ѽ� ���� �Ķ� �귯�� �޸� ���� (�߿� !!!!!!!!!!!!!!!!!!!) =============================================
        DeleteObject(brush);

        // �����Ҵ� ���Ѽ� ���� ���� �� �޸� ���� (�߿� !!!!!!!!!!!!!!!!!!!) =============================================
       // DeleteObject(redPen);


        // ���� ������Ʈ(Stock Object) : �⺻���� ���� ���Ǵ� GDI ������Ʈ���� �̸� DC �ȿ� ������� �ִ�. 
        // GetStckObject();
        //HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
        //oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);

//        Rectangle(mHdc, 400, 400, 500, 500);
        // ���� ������Ʈ�� ����ص�, ���� ����Ʈ ������Ʈ�� DC �� �ǵ��� ���� ���� �ùٸ� API �����̴�.
//       SelectObject(mHdc, oldBrush);


//		Rectangle(mHdc, 500, 500, 600, 600);
        */

        // backBuffer �� �ִ°� ���� buffer �� ���� (�׸���)
        BitBlt(mHdc, 0,0,mWidth, mHeight, mBackHdc, 0,0, SRCCOPY);

	}
}
