// WinShareMemRead.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;

#define BUF_SIZE 1025
//char szName[] = "ShareMemory";
char szName[] = "FeatureData";

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		BUF_SIZE,
		szName);

	char *pBuf = (char*)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);

	while (1)
	{
		cout << "press any button to receive data .." << endl;
		getchar();
		cout << pBuf << endl;
	}

	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);
	return 0;
}

