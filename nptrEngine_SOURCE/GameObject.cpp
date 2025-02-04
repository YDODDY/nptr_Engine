#include "GameObject.h"
#include "input.h"

namespace nptr
{
	GameObject::GameObject()
	{

	}
	GameObject::~GameObject()
	{

	}
	void GameObject::Update()
	{
     //   if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        if(Input::GetKey(eKeyCode::Left))
        {
            mX -= 0.01f;
        }
     //  if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        if (Input::GetKey(eKeyCode::Right))
        {
            mX += 0.01f;
        }
     //  if (GetAsyncKeyState(VK_UP) & 0x8000)
        if (Input::GetKey(eKeyCode::Up))
        {
            mY -= 0.01f;
        }
     //  if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        if (Input::GetKey(eKeyCode::Down))
        {
            mY += 0.01f;
        }
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
        Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
        (HBRUSH)SelectObject(hdc, oldBrush);
        DeleteObject(brush);
	}
}