#include "nptrApplication.h"
#include "GameObject.h"
#include "Input.h"

namespace nptr
{   
    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mSpeed(0)
    {

    }
    Application::~Application()
    {

    }

	void Application::Initialize(HWND hwnd)
	{
		// �ڵ�, DC �޾Ƶα� - ��� �������� �ʰ� �޾Ƽ� ���
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
        mPlayer.SetPosition(0, 0);
        mPlayer2.SetPosition(300, 300);

        Input::Initialize();
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

        mPlayer.Update();
        mPlayer2.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
        // GameObject
        mPlayer.Render(mHdc);
        mPlayer2.Render(mHdc);
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
	}
}
