#include "Time.h"

namespace nptr
{
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currentFrequency = {};
	float Time::deltaTime = 0.0f;

	void Time::Initialize()
	{
		// cpu 고유 진동수 저장
		QueryPerformanceFrequency(&cpuFrequency);

		// 프로그램이 시작 되었을 때의 현재 진동수 저장
		QueryPerformanceCounter(&prevFrequency);
	}
	void Time::Update()
	{
		// 앞전 진동수 
		QueryPerformanceCounter(&currentFrequency);

		float differenceFrequency
			= static_cast<float>(currentFrequency.QuadPart - prevFrequency.QuadPart);
			// float 은 4바이트니까 cast        	// 8바이트 정수

		deltaTime = differenceFrequency / static_cast<float>(cpuFrequency.QuadPart);

		// 앞전 진동수를 현재 진동수로 다시 갱신
		prevFrequency.QuadPart = currentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += deltaTime;
		float fps = 1.0f / deltaTime;

		// 2바이트 문자 -> wchar 초기화시 앞에 L 붙임
		wchar_t str[50] = L""; 

		// 시간 출력
		//swprintf_s(str,50, :"TIME : %f, time); 
		// 시간당 프레임 출력

		swprintf_s(str, 50, L"TIME : %d",(int)fps);
		int len = wcsnlen_s(str,50);


		TextOut(hdc, 0, 0, str, len);
	}
}