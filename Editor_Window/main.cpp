// Editor_Window.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Editor_Window.h"
#include "CommonInclude.h"

// 정적라이브러리 생성 후 연결
// Editor_Window 참조 추가 -> 프로젝트, nptrEngine_SOURCE
// nptrEngine_Window 참조추가 -> 공유 프로젝트, Editor_Window
#include "..\\nptrEngine_SOURCE\\nptrApplication.h"
#include "..\\nptrEngine_Window\\LoadScene.h"


// namespace nptr
nptr::Application app;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance); 
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,  // 프로그램 인스턴스 핸들 : 프로그램이 차지하는 메모리에 접근할 수 있는 것(다른 메모리에 접근하지 않도록 함)
                     _In_opt_ HINSTANCE hPrevInstance,  // 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들, 없을 경우에는 NULL 이다.
                     _In_ LPWSTR    lpCmdLine,   // 명령행으로 입력된 프로그램 인수(Visual Studio 명령행 인수)
                     _In_ int       nCmdShow)    // 프로그램이 실행될 형태, 보통 모양정보 등이 전달됨
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);           // Editor_Window 이름 저장
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);  // Editor_Window 이름 저장(프로세스)
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;

    // GetMessage(&msg, nullptr, 0, 0)
    // 프로세스에서 발생한 메세지를 메세지 큐에서 가져오는 함수
    // 메세지큐에 아무것도 없다면 -> 아무 메세지도 가져오지 않게된다.
    // 메세지큐에 아무것도 없다 : 입력

    // PeekMessage : 메세지큐에 메세지 유무에 상관없이 함수가 리턴된다.
    //               리턴값이 true인 경우 메세지가 있고, false인 경우 메세지가 없다고 가르켜준다.

    while (true)
    {
                    // MSG  // 핸들         // 메세지를 가져온 이후 처리 -> 삭제
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            // 메세지를 가져온게 QUIT (종료) 라면, 그대로 종료 시키도록 (while 문을 빠져나오도록) break;
            if (msg.message == WM_QUIT)
                break;

            // 그 외 메세지
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                // 번역해서
                TranslateMessage(&msg);
                // 보내기
                DispatchMessage(&msg);
            }
        }
        // 메세지가 없다 : false
        else
        {
            // LOOP 
            app.Run();
        }
    }



    // 프로그램을 "끌 때 까지" 종료되면 안되기 때문에, 계속해서 사용자로 부터의 입력 등으로 오는 메세지를 처리해 프로그램이 돌아가도록 함
    // return 값이 0 이라면 (보통 main 의 끝 반환값), 프로그램이 정지된다.
    // WindClass 정의 (윈도우 기반이 되는 클래스 정의) -> CreateWindow (메모리상에 윈도우를 만듦) -> ShowWindow (윈도우를 화면에 표시) -> 메세지 루프 (사용자로 부터의 메세지 처리)
    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


// 윈도우 창 만드는 정보 ==================================================================================================================
//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
                                              // 윈도우 창 안에서 감지되는 커서의 모양이 바뀜
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//=======================================================================================================================================

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable
   
   const UINT width = 1600;
   const UINT height = 900;

   // 윈도우 종류(창, 팝업 .. )
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,                       // Editor_Window 라는 이름으로 윈도우 창 만들기
      // 창 위치         // 창 크기 
      CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);
   // 반환자료 HWND(핸들) : 생성한 윈도우 창의 메모리에 접근할 수 있는 핸들 반환!
   
   app.Initialize(hWnd, width, height);

   // 두개 만들면 윈도우창이 두개 생김! 
 //  HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,                    
  //     CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);


   // LOAD SCENES
   nptr::LoadScenes();

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

// 매 프레임마다 호출되는 중 - SoEn 에서 윈도우 메세지큐 종류 볼 수 있음 (검색)
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    // 어플리케이션 메뉴 처리
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

    // 키입력에 따른 그리기
 //   case WM_KEYDOWN:
 //  {

 //  }
 //  break;
    // 주 창 그리기
    case WM_PAINT:
        {
            PAINTSTRUCT ps;

            HDC hdc = BeginPaint(hWnd, &ps);

            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    // 윈도우 창이 종료될 때 호출되는 메세지
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
