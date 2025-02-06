#pragma once
#include "CommonInclude.h"

namespace nptr
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return deltaTime; }

	private:
		// unsigned long + long �ؼ� 8����Ʈ 
		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER prevFrequency;
		static LARGE_INTEGER currentFrequency;
		static float deltaTime;
	};
}
