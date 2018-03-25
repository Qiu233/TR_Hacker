#include "../CheatLibrary/stdafx.h"
#include "../CheatLibrary/CheatLibrary.h"

DWORD GetGameID(LPCTSTR pName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot)
	{
		return 0;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	BOOL fOk;
	for (fOk = Process32First(hSnapshot, &pe); fOk; fOk = Process32Next(hSnapshot, &pe))
	{
		if (!_tcscmp(pe.szExeFile, pName))
		{
			CloseHandle(hSnapshot);
			return pe.th32ProcessID;
		}
	}
	CloseHandle(hSnapshot);
	return 0;
}

int main()
{
	InitCL(GetGameID(_T("Terraria.exe")), TRUE, _T("Terraria.exe"));
	void *addr = (void*)malloc(4);
	SearchFunctionByName(_T("Terraria.Item::NewItem"), &addr, 1);
	printf("Terraria.Item::NewItem\t->%x\n", addr);
	system("pause");
	return 0;
}