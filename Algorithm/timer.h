#ifndef TIMER_H
#define TIMER_H
/************************************************************************/
/*                             ��ʱģ��                                 */
/************************************************************************/

#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")

// ��������
void timer_time(void);											// ʹ��time()��ʱ�������λΪs
void timer_clock(void);											// ʹ��clock()��ʱ�������λΪms
void timer_timeGetTime(void);									// ʹ��timer_timeGetTime()��ʱ�������λΪms
void timer_GetTickCount(void);									// ʹ��GetTickCount()��ʱ�������λΪms
void timer_QueryPerformanceCounter(void);						// ʹ��timer_QueryPerformanceCounter()��ʱ�������λΪms
void genRand(int * arrNumber, int iMin, int iMax, int iSize);	// �����������������λ������[iMin, iMax]�ڵ�iSize�������
void genCatalan(int* arrNumber, int iSize);						// ��������������
void genFibonacci(int* arrFibonacci, int iArrLength);			// 쳲���������������

void timer_time(void) {
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);
	
	Sleep(1000);
	
	timeEnd = time(NULL);
	printf("��ʱ��%lld s\n", timeEnd - timeBegin);
}

void timer_clock(void) {
	clock_t  clockBegin, clockEnd;
	clockBegin = clock();
	
	Sleep(800);
	
	clockEnd = clock();
	printf("��ʱ��%d ms\n", clockEnd - clockBegin);
}

void timer_timeGetTime(void) {
	DWORD  dwBegin, dwEnd;
	dwBegin = timeGetTime();
	
	Sleep(800);
	
	dwEnd = timeGetTime();
	printf("��ʱ��%d ms\n", dwEnd - dwBegin);
}

void timer_GetTickCount(void) {
	DWORD  dwGTCBegin, dwGTCEnd;
	dwGTCBegin = GetTickCount();
	
	Sleep(800);
	
	dwGTCEnd = GetTickCount();
	printf("��ʱ��%d ms\n", dwGTCEnd - dwGTCBegin);
}

void timer_QueryPerformanceCounter(void) {
	LARGE_INTEGER li, freq;
	QueryPerformanceCounter(&li);
	long long f_start = li.QuadPart;
	QueryPerformanceFrequency(&freq);   //ȡ�õ�ǰ��(��)�̵�ʱ����Ƶ
	
	Sleep(800);
	
	QueryPerformanceCounter(&li);
	long long f_end = li.QuadPart;
	long long llTime = (f_end - f_start) * 1000000 / freq.QuadPart;
	printf("%lld ms\n", llTime / 1000);
}

#endif // !TIMER_H
