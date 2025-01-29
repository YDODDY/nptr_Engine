// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// 정적 라이브러리 (Static Library)  = nptrEngine_Window
// Editor_Window, nptrEngine_Window 속성에서 C++14 -> C++20 으로 변경

// 장점 
// 시스템 환경이 변해도 어플리케이션에 아무런 영향 X
// 컴파일시 필요한 라이브러리를 적재하기 때문에 이식성이 좋다
// 런타임시 외부를 참조할 필요가 없기 때문에 속도가 빠르다

// 단점
// 같은 코드를 가진 프로그램이 실행될 경우가 있다면, 코드가 중복될 수 있으니 그만큼 메모리가 낭비됨
// 라이브러리가 변경되면 변경된 라이브러리만 재배포하면 되는게 아니라, 다시 모두 컴파일해서 재배포 해야함

// 동적 라이브러리 (Dynamic Library)

// 장점
// 메모리 절약
// 보다 쉽게 업그레이드 해서 배포 가능
// 서로 다른 프로그램에서 동일한 함수를 호출 가능
// 프로그램 변경시 라이브러리만 재배포하면 되니까 유지보수가 쉬움

// 단점
// 외부 의존도가 높기 때문에 이식성이 낮음
// 공유 라이브러리를 메모리에 올려놓고, 해당 라이브러리를 찾아서 접근해야 되기 때문에 속도가 느림
