#pragma once
#include "CommonInclude.h"


namespace nptr
{
	// 입력값 상태
	enum class eKeyState
	{
		Down, 
		Pressed,
		Up,
		None,
	};

	// 키
	enum class eKeyCode
	{
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M, 
		Left, Right, Down, Up, SpaceBar,
		End,
	};
	 
	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }


	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Input::Key& key);

	private:
		//eKeyState mState[] = eKeyState::Up;
		static std::vector<Key> mKeys;

	};
}
