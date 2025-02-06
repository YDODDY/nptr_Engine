#include "GameObject2.h"
#include "Input.h"

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
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}
		//  if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}
		//  if (GetAsyncKeyState(VK_UP) & 0x8000)
		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}
		//  if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		if (Input::GetKey(eKeyCode::S))
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