#include "GameObject.h"
#include "BulletObject.h"
#include "input.h"
#include "Time.h"

namespace nptr
{
	GameObject::GameObject()
        : mX(0)
        , mY(0)
	{

	}
	GameObject::~GameObject()
	{

	}
	void GameObject::Update()
	{
        const int speed = 100.0f;

     //   if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        if(Input::GetKey(eKeyCode::Left))
        {
            mX -= speed * Time::DeltaTime();
        }
     //  if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        if (Input::GetKey(eKeyCode::Right))
        {
            mX += speed * Time::DeltaTime();
        }
     //  if (GetAsyncKeyState(VK_UP) & 0x8000)
        if (Input::GetKey(eKeyCode::Up))
        {
            mY -= speed * Time::DeltaTime();
        }
     //  if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        if (Input::GetKey(eKeyCode::Down))
        {
            mY += speed * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::SpaceBar))
        {
            bullet->SetPosition(GetPositionX(), GetPositionY());
            bullet->isPlayerShot = true;
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