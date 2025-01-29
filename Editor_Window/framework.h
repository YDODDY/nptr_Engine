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


// ���� ���̺귯�� (Static Library)  = nptrEngine_Window
// Editor_Window, nptrEngine_Window �Ӽ����� C++14 -> C++20 ���� ����

// ���� 
// �ý��� ȯ���� ���ص� ���ø����̼ǿ� �ƹ��� ���� X
// �����Ͻ� �ʿ��� ���̺귯���� �����ϱ� ������ �̽ļ��� ����
// ��Ÿ�ӽ� �ܺθ� ������ �ʿ䰡 ���� ������ �ӵ��� ������

// ����
// ���� �ڵ带 ���� ���α׷��� ����� ��찡 �ִٸ�, �ڵ尡 �ߺ��� �� ������ �׸�ŭ �޸𸮰� �����
// ���̺귯���� ����Ǹ� ����� ���̺귯���� ������ϸ� �Ǵ°� �ƴ϶�, �ٽ� ��� �������ؼ� ����� �ؾ���

// ���� ���̺귯�� (Dynamic Library)

// ����
// �޸� ����
// ���� ���� ���׷��̵� �ؼ� ���� ����
// ���� �ٸ� ���α׷����� ������ �Լ��� ȣ�� ����
// ���α׷� ����� ���̺귯���� ������ϸ� �Ǵϱ� ���������� ����

// ����
// �ܺ� �������� ���� ������ �̽ļ��� ����
// ���� ���̺귯���� �޸𸮿� �÷�����, �ش� ���̺귯���� ã�Ƽ� �����ؾ� �Ǳ� ������ �ӵ��� ����
