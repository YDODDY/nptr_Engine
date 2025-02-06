#include "Time.h"

namespace nptr
{
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currentFrequency = {};
	float Time::deltaTime = 0.0f;

	void Time::Initialize()
	{
		// cpu ���� ������ ����
		QueryPerformanceFrequency(&cpuFrequency);

		// ���α׷��� ���� �Ǿ��� ���� ���� ������ ����
		QueryPerformanceCounter(&prevFrequency);
	}
	void Time::Update()
	{
		// ���� ������ 
		QueryPerformanceCounter(&currentFrequency);

		float differenceFrequency
			= static_cast<float>(currentFrequency.QuadPart - prevFrequency.QuadPart);
			// float �� 4����Ʈ�ϱ� cast        	// 8����Ʈ ����

		deltaTime = differenceFrequency / static_cast<float>(cpuFrequency.QuadPart);

		// ���� �������� ���� �������� �ٽ� ����
		prevFrequency.QuadPart = currentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += deltaTime;
		float fps = 1.0f / deltaTime;

		// 2����Ʈ ���� -> wchar �ʱ�ȭ�� �տ� L ����
		wchar_t str[50] = L""; 

		// �ð� ���
		//swprintf_s(str,50, :"TIME : %f, time); 
		// �ð��� ������ ���

		swprintf_s(str, 50, L"TIME : %d",(int)fps);
		int len = wcsnlen_s(str,50);


		TextOut(hdc, 0, 0, str, len);
	}
}