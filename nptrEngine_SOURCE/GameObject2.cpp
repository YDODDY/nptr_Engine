#include "GameObject2.h"

namespace nptr
{
	GameObject2::GameObject2()
	{

	}
	GameObject2::~GameObject2()
	{

	}
	void GameObject2::Update()
	{
		// WASD
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void GameObject2::LateUpdate()
	{

	}
	void GameObject2::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
		Ellipse(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
}