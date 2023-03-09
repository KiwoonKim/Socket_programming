// WorkerThreadCreate.cpp : 콘솔 으용 프로그램에 대한 진입점을 정의

#include "stdafx.h"
#include <Windows.h>

// _tmain() 함수와 별도로 작동하는 작업자 스레드 함수

DWORD WINAPI ThreadFunction(LPVOID pParam)
{
	puts("*** Begin Thread ***");

	for (int i = 0; i < 5; i++) {
		printf("[Worker Thread] %d\n", i);
	}

	puts("*** End Thread ***");
	return 0;
}

int _tamin(int argc, _TCHAR**  argv) 
{
	DWORD dwThreadID = 0;

	HANDLE hThread = ::CreateThread(
		NULL, // 보안속성 상속
		0,    // 스택 메모리는 기본 크기
		ThreadFunction, // 스레드로 실행할 함수
		NULL, // 함수에 전달할 매개변수.
		0,    // 생성 플래그는 기본값 사용.
		&dwThreadID);   // 생성된 스레드 ID 저장.

	for (int i = 0; i < 10; ++i)
		printf("[Main thread] %d\n", i);

	::CloseHandle(hThread);
	::Sleep(10);

	return 0;
}