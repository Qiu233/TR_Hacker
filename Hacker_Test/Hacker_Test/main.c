#include "Func.h"

int main()
{
    DWORD pid=GetGameID("Terraria.exe");
    HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS,0,pid);
    int base=getPlayerBase(hProcess);
    printf("PID:%d\n",pid);
    printf("HANDLE:%d\n",hProcess);
    printf("BASE:%x\n",base);
    //while(1)
    {
        char *str="8B 95 34 B3 FF FF 3B 82 FC 00 00 00 0F 8C";
        int path=aobscan(hProcess,str,0);
        printf("%x",path);
    }
    CloseHandle(hProcess);
    return 0;
}
