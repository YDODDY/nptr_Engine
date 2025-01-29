// Editor_Window.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Editor_Window.h"
#include "CommonInclude.h"

// �������̺귯�� ���� �� ����
// Editor_Window ���� �߰� -> ������Ʈ, nptrEngine_SOURCE
// nptrEngine_Window �����߰� -> ���� ������Ʈ, Editor_Window
#include "..\\nptrEngine_SOURCE\\nptrApplication.h"

Application app;

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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,  // ���α׷� �ν��Ͻ� �ڵ� : ���α׷��� �����ϴ� �޸𸮿� ������ �� �ִ� ��(�ٸ� �޸𸮿� �������� �ʵ��� ��)
                     _In_opt_ HINSTANCE hPrevInstance,  // �ٷ� �տ� ����� ���� ���α׷��� �ν��Ͻ� �ڵ�, ���� ��쿡�� NULL �̴�.
                     _In_ LPWSTR    lpCmdLine,   // ��������� �Էµ� ���α׷� �μ�(Visual Studio ����� �μ�)
                     _In_ int       nCmdShow)    // ���α׷��� ����� ����, ���� ������� ���� ���޵�
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    app.test();

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);           // Editor_Window �̸� ����
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);  // Editor_Window �̸� ����(���μ���)
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;

    // GetMessage(&msg, nullptr, 0, 0)
    // ���μ������� �߻��� �޼����� �޼��� ť���� �������� �Լ�
    // �޼���ť�� �ƹ��͵� ���ٸ� -> �ƹ� �޼����� �������� �ʰԵȴ�.
    // �޼���ť�� �ƹ��͵� ���� : �Է�

    // PeekMessage : �޼���ť�� �޼��� ������ ������� �Լ��� ���ϵȴ�.
    //               ���ϰ��� true�� ��� �޼����� �ְ�, false�� ��� �޼����� ���ٰ� �������ش�.

    while (true)
    {
                    // MSG  // �ڵ�         // �޼����� ������ ���� ó�� -> ����
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            // �޼����� �����°� QUIT (����) ���, �״�� ���� ��Ű���� (while ���� ������������) break;
            if (msg.message == WM_QUIT)
                break;

            // �� �� �޼���
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                // �����ؼ�
                TranslateMessage(&msg);
                // ������
                DispatchMessage(&msg);
            }
        }
        // �޼����� ���� : false
        else
        {
            // ���� ����
        }
    }



    // ���α׷��� "�� �� ����" ����Ǹ� �ȵǱ� ������, ����ؼ� ����ڷ� ������ �Է� ������ ���� �޼����� ó���� ���α׷��� ���ư����� ��
    // return ���� 0 �̶�� (���� main �� �� ��ȯ��), ���α׷��� �����ȴ�.
    // WindClass ���� (������ ����� �Ǵ� Ŭ���� ����) -> CreateWindow (�޸𸮻� �����츦 ����) -> ShowWindow (�����츦 ȭ�鿡 ǥ��) -> �޼��� ���� (����ڷ� ������ �޼��� ó��)
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


// ������ â ����� ���� ==================================================================================================================
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
                                              // ������ â �ȿ��� �����Ǵ� Ŀ���� ����� �ٲ�
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
                                                     // ������ ����(â, �˾� .. )
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,                       // Editor_Window ��� �̸����� ������ â �����
      // â ��ġ         // â ũ�� 
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   // ��ȯ�ڷ� HWND(�ڵ�) : ������ ������ â�� �޸𸮿� ������ �� �ִ� �ڵ� ��ȯ!

   // �ΰ� ����� ������â�� �ΰ� ����! 
 //  HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,                    
  //     CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

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

// �� �����Ӹ��� ȣ��Ǵ� �� - SoEn ���� ������ �޼���ť ���� �� �� ���� (�˻�)
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    // ���ø����̼� �޴� ó��
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

    // Ű�Է¿� ���� �׸���
 //   case WM_KEYDOWN:
 //  {

 //  }
 //  break;
    // �� â �׸���
    case WM_PAINT:
        {
            PAINTSTRUCT ps;

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
            HDC hdc = BeginPaint(hWnd, &ps);

            // ������Ʈ ��� ����
            // ���� ����� - RGB �������ڰ�, �޸𸮸� �߰��� �Ҵ��Ŵ(���� �����Ҵ�!)
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
            // ���� �Ķ��� �귯�� DC �� �����ϰ�, ��� �귯�� ��ȯ�ؼ� �ӽú����� ����
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

            // ������â�� �׸� �׸��� -> 0,0(������ܺ���) ���� ���� �������ڷ� ����. //////// �Ķ���
            Rectangle(hdc, 100,100,200,200);

            // ���� DC �� ��� �귯�� ����
            (HBRUSH)SelectObject(hdc, oldBrush);
            // �����Ҵ� ���Ѽ� ���� �Ķ� �귯�� �޸� ���� (�߿� !!!!!!!!!!!!!!!!!!!) =============================================
            DeleteObject(brush);

            // ������Ʈ �� ���� + ��Ÿ��
            HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
            // ���� ���� ���� �� ���� �� ���� ����Ʈ ���� ��ȯ 
            HPEN oldPen = (HPEN)SelectObject(hdc, redPen);


            // �� �׸��� -> �׸�׸��⿡�� �׸� �ȿ� ���� �׷�����.                    //////// �Ͼ��
            Ellipse(hdc, 200, 200, 300, 300); 

            // ���� ����Ʈ ������ �ٽ� ����
            SelectObject(hdc, oldPen);      
            // �����Ҵ� ���Ѽ� ���� ���� �� �޸� ���� (�߿� !!!!!!!!!!!!!!!!!!!) =============================================
            DeleteObject(redPen);
            

            // ���� ������Ʈ(Stock Object) : �⺻���� ���� ���Ǵ� GDI ������Ʈ���� �̸� DC �ȿ� ������� �ִ�. 
            // GetStckObject();
            HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
            oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);

            Rectangle(hdc, 400, 400, 500, 500);
            // ���� ������Ʈ�� ����ص�, ���� ����Ʈ ������Ʈ�� DC �� �ǵ��� ���� ���� �ùٸ� API �����̴�.
            SelectObject(hdc, oldBrush);
            

            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    // ������ â�� ����� �� ȣ��Ǵ� �޼���
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
