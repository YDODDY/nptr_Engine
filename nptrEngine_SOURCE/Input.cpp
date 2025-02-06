#include "Input.h"

namespace nptr
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};


	// �ʱ�ȭ
	void Input::Initialize()
	{					    // typedef unsigned int UINT;
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
/*
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// Ű�� ���ȴ��� 
			//if(GetAsyncKeyState('W') & 0x8000)
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed;  // Ű�� �����ִµ� ��� ����
				else                                      
					mKeys[i].state = eKeyState::Down;     // Ű�� �ȴ��ȴٰ� ����

				mKeys[i].bPressed = true;
			}
			// Ű�� �ȴ��ȴ�
			else
			{
				if (mKeys[i].bPressed == true)			   
					mKeys[i].state = eKeyState::Up;        // Ű�� �����־��µ� ����
				else                                      
					mKeys[i].state = eKeyState::None;	   // Ű�� �������� �ʾ���

				mKeys[i].bPressed = false;
			}

		}
*/
	}
	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}
	void Input::updateKeys()
	{
		std::for_each(mKeys.begin(), mKeys.end(),
			[](Key& key)-> void
			{
				updateKey(key);
			});

	}
	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.keyCode))
		{
			updateKeyDown(key);
		}
		else
		{
			updateKeyUp(key);
		}
	}
	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}
	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;
		
		key.bPressed = false;
	}
}