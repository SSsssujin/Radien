// API_FrameWork.cpp : 애플리케이션에 대한 진입점을 정의합니다.

#include"framework.h"
#include"Brandnew_Radien.h"
#include"mainGame.h"
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")

HINSTANCE m_hInstance;
HWND m_hWnd;
POINT m_ptMouse = { 0,0 };

//메인게임
mainGame mg;

LPTSTR m_lpszClass = TEXT("Radien 1.5");
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	m_hInstance = hInstance;
	MSG message;
	WNDCLASS wndClass;

	//1.윈도우 창 생성
	wndClass.cbClsExtra			= 0;
	wndClass.cbWndExtra			= 0;
	wndClass.hbrBackground		= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon				= LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance			= hInstance;
	wndClass.lpfnWndProc		= (WNDPROC)WndProc;
	wndClass.lpszClassName		= m_lpszClass;
	wndClass.lpszMenuName		= NULL;
	wndClass.style				= CS_HREDRAW | CS_VREDRAW;

	//2.등록
	RegisterClass(&wndClass);

	//3.설정
	m_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,
		WINSTARTX,
		WINSTARTY,
		WINSIZEX,
		WINSIZEY,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	//4.활성화
	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
	ShowWindow(m_hWnd, nCmdShow);

	//메인게임 초기화 실패하면 종료
	if (FAILED(mg.init()))
	{
		return 0;
	}


	//5.메시지 처리
	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{

			if (message.message == WM_QUIT)break;
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		else
		{
			mg.update();
			mg.render();
		}
	}

	//메시지 루프를 다돌면 해제하자.
	mg.release();

	return message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//switch (iMessage)
	//{
	//case WM_CREATE:
	//	PlaySoundA((LPCSTR)"images/sail", NULL, SND_FILENAME | SND_ASYNC);
	//	//PlaySoundA((LPCSTR)"images/정의", NULL, SND_FILENAME | SND_ASYNC);
	//	//PlaySoundA((LPCSTR)"images/music", NULL, SND_FILENAME | SND_ASYNC);

	//	break;
	//}
	return mg.MainProc(hWnd, iMessage, wParam, lParam);
}


//위도우 크기조정 
void setWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	//위 RECT정보로 윈도우 사이즈 셋팅
	SetWindowPos(m_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}