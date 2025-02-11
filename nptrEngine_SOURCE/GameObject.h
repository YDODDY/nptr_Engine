#pragma once
#include "CommonInclude.h"
#include "BulletObject.h"

namespace nptr
{
	// Actor

	class BulletObject;

	class GameObject
	{

	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX()	{  return mX;  }
		float GetPositionY()  {  return mY;  }

//		BulletObject* bullet;

	private:

		// ���� ������Ʈ�� ��ǥ
		float mX;
		float mY;
	};
}
