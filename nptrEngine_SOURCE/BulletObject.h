#pragma once
#include "CommonInclude.h"
#include "GameObject.h"

namespace nptr
{
	class GameObject;

	class BulletObject
	{
	public:
		BulletObject();
		~BulletObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x; 
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }
		
		GameObject* player;

		void Shot();
		bool isPlayerShot;

	private:
		float mX;
		float mY;
	};
}
