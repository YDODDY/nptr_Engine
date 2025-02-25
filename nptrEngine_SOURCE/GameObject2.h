#pragma once
#include "CommonInclude.h"

namespace nptr
{
	class GameObject2
	{
	public:
		GameObject2();
		~GameObject2();

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

		bool GetMovingDir() { return isMovingLeft; }
		bool isMovingLeft;

	private:
		float mX;
		float mY;
	};
}

