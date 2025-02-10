#include "BulletObject.h"
#include "GameObject.h"
#include "Time.h"

namespace nptr
{
	BulletObject::BulletObject()
	{

	}
	BulletObject::~BulletObject()
	{

	}
	void BulletObject::Update()
	{
		Shot();
	}

	void BulletObject::Shot()
	{
		if (isPlayerShot == true)
		{
			const float speed = 1;
			mY += speed + Time::DeltaTime();
			if (GetPositionY() > 500)
			{
				isPlayerShot = false;
			}
		}
		else
		{
			float x = player->GetPositionX();
			float y = player->GetPositionY();
			SetPosition(x, y);
		}
	}

	void BulletObject::LateUpdate()
	{

	}
	void BulletObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
		Ellipse(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
}