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
		// 핸들, DC 받아두기 - 계속 생성하지 않고 받아서 사용
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

        // 내가 오른쪽 키를 입력 받았다면 x 좌표 + 
        // 좌 x 좌표 -
        // 위아래는 y 좌표 -+

        float x = mPlayer.GetPositionX();
        float y = mPlayer.GetPositionY();
        // 키 상태 체크하는 함수 
        // 좌                         Microsoft : 0x8000 넣으라고 해서 넣는 것 
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            x -= 0.01f;
        }  
        // 우
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            x += 0.01f;
        }    
        // WINDOW 좌표계에서 위는 y--, 아래는 y++
        // 위
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            y -= 0.01f;
        }    
        // 아래
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            y += 0.01f;
        }
        mPlayer.SetPosition(x, y);
*/
        // GameObject

        // 키입력 받고 플레이어 로직 돌리기
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
        // HPEN newPen, oldPen  :  핸들 만들기(선언)
        // -> newPen = CreatePen(...)  :  GDI 오브젝트 만들기(힙에 동적으로 할당됨)
        // -> oldPen = SelectObject(DC, newPen)  :  DC 에 선택하되 이때 이전 핸들을 반드시 저장(디폴트 핸들)
        // -> Rectangle, Ellipse, ..             :  선택한 선 혹은 색상 사용
        // -> SelectObject(DC, oldPen)           :  선택 해제(기존 디폴트 선 or 색상으로 초기화)
        // -> DeleteObject(newPen)               :  만들었던 선 or 색상 삭제 (힙에 동적 할당한 메모리 해제)

        // DC (Device Context) : 화면 출력에 필요한 모든 정보를 가지는 데이터 구조체
        // GDI 모듈에 의해서 관리됨 
        // 폰트, 선의 굵기, 색상 등.. 
        // 화면 출력에 필요한 모든 경우는 WINAPI 에서는 DC 를 통해서 작업을 진행함.

        // 오브젝트 배경 색상
        // 색상 만들기 - RGB 전달인자값, 메모리를 추가로 할당시킴(힙에 동적할당!)
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
        // 만든 파랑색 브러쉬 DC 로 선택하고, 흰색 브러쉬 반환해서 임시변수에 저장
        HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);

        // 오브젝트 선 색상 + 스타일
        //HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
        // 새로 만든 빨간 선 선택 및 기존 디폴트 선값 반환 
        //HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

        // 원 그리기 -> 네모그리기에서 네모 안에 원이 그려진다.                    //////// 하얀색
        //Ellipse(mHdc, 200, 200, 300, 300);

        // 기존 디폴트 선으로 다시 선택
        //SelectObject(mHdc, oldPen);

        float x = mPlayer.GetPositionX();
        float y = mPlayer.GetPositionY();
        // 윈도우창에 네모 그리기 -> 0,0(좌측상단부터) 기준 값이 전달인자로 들어간다. //////// 파랑색
        Rectangle(mHdc, 100 + x, 100 + y, 200 + x, 200 + y);

        // 기존 DC 인 흰색 브러쉬 선택
        (HBRUSH)SelectObject(mHdc, oldBrush);
        // 동적할당 시켜서 만든 파랑 브러쉬 메모리 해제 (중요 !!!!!!!!!!!!!!!!!!!) =============================================
        DeleteObject(brush);

        // 동적할당 시켜서 만든 빨간 선 메모리 해제 (중요 !!!!!!!!!!!!!!!!!!!) =============================================
       // DeleteObject(redPen);


        // 스톡 오브젝트(Stock Object) : 기본으로 자주 사용되는 GDI 오브젝트들은 미리 DC 안에 만들어져 있다. 
        // GetStckObject();
        //HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
        //oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);

//        Rectangle(mHdc, 400, 400, 500, 500);
        // 스톡 오브젝트를 사용해도, 기존 디폴트 오브젝트로 DC 를 되돌려 놓는 것이 올바른 API 사용법이다.
//       SelectObject(mHdc, oldBrush);


//		Rectangle(mHdc, 500, 500, 600, 600);
        */
	}
}
