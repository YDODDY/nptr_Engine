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


	// 초기화
	void Input::Initialize()
	{					    // typedef unsigned int UINT;
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// 키가 눌렸는지 
			//if(GetAsyncKeyState('W') & 0x8000)
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed;  // 키가 눌려있는데 계속 눌림
				else                                      
					mKeys[i].state = eKeyState::Down;     // 키가 안눌렸다가 눌림

				mKeys[i].bPressed = true;
			}
			// 키가 안눌렸다
			else
			{
				if (mKeys[i].bPressed == true)			   
					mKeys[i].state = eKeyState::Up;        // 키가 눌려있었는데 떼짐
				else                                      
					mKeys[i].state = eKeyState::None;	   // 키가 눌려있지 않았음

				mKeys[i].bPressed = false;
			}

		}
	}
}