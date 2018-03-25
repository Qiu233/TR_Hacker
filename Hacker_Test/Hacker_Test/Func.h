#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <wchar.h>
#include <locale.h>
#include <psapi.h>

typedef struct
{
    byte* HOOK_CODE;
    DWORD HOOK_CODE_LENGTH;
    void* HOOK_PATH;
    void* ASM_PATH;
} HOOK_INFO,*PHOOK_INFO;


int base;
HANDLE hProcess;
int search_only(char *src)
{
    int addrs=aobscan(hProcess,src,0);
    return addrs;
}

int getPlayerBaseAddr__A(HANDLE hProcess)
{
    int r;
    int path=search_only("8B8240030000");
    printf("A:%x\n",path);
    /*char *cr=(char*)malloc(20);
    itoa(path,cr,16);
    MessageBoxA(NULL,cr,cr,MB_OK);*/
    if(path<=0)
    {
        return 0;
    }
    byte ASM_CODE[]= {0x89,0x15,0x00,0x00,0x00,0x00,
                      0x8B,0x82,0x40,0x03,0x00,0x00,
                     };

    //
    PWSTR pData=(PWSTR)VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    /*char *c=(char*)malloc(20);
    itoa(pData,c,16);
    MessageBoxA(NULL,c,c,MB_OK);*/
    *(DWORD*)&ASM_CODE[2]=(DWORD)pData;
    HOOK_INFO hi;
    inline_hook(hProcess,(void*)path,6,ASM_CODE,sizeof(ASM_CODE),&hi);
    Sleep(50);
    ReadProcessMemory(hProcess,(void*)pData,&r,4,NULL);

    un_inline_hook(hProcess,&hi);
    VirtualFreeEx(hProcess,(void*)pData,0,MEM_RELEASE);
    return r;
}
int getPlayerBaseAddr__B(HANDLE hProcess)
{
    int r;
    int path=search_only("8BBE40030000");
    printf("B:%x\n",path);
    if(path<=0)
    {
        return 0;
    }
    byte ASM_CODE[]= {0x89,0x35,0x00,0x00,0x00,0x00,
                      0x8B,0xBE,0x40,0x03,0x00,0x00,
                     };

    //
    PWSTR pData=(PWSTR)VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    *(DWORD*)&ASM_CODE[2]=(DWORD)pData;
    HOOK_INFO hi;
    inline_hook(hProcess,(void*)path,6,ASM_CODE,sizeof(ASM_CODE),&hi);
    ReadProcessMemory(hProcess,(void*)pData,&r,4,NULL);
    un_inline_hook(hProcess,&hi);
    VirtualFreeEx(hProcess,(void*)pData,0,MEM_RELEASE);
    return r;
}


__declspec(dllexport)
int getPlayerBase(HANDLE hP)
{
    base=0;
    hProcess=hP;
    base=getPlayerBaseAddr__A(hProcess);
    if(base<=0)
    {
        base=getPlayerBaseAddr__B(hProcess);
    }
    /*if((rst=getPlayerBaseAddr_A(hProcess))!=0)
    {
        base=rst;
    }
    else if((rst=getPlayerBaseAddr_B(hProcess))!=0)
    {
        base=rst;
    }
    else if((rst=getPlayerBaseAddr_C(hProcess))!=0)
    {
        base=rst;
    }*/
    return base;
}

void inline_hook(HANDLE hProcess,void*path,int dstlen,byte *code,int codelen,PHOOK_INFO hi)
{
    //
    byte *ASM_CODE=(byte*)malloc(codelen+5);
    memcpy(ASM_CODE,code,codelen);
    ASM_CODE[codelen]=0xe9;
    DWORD*retjmp=(DWORD *)&ASM_CODE[codelen+1];
    PWSTR pCode=(PWSTR)VirtualAllocEx(hProcess, NULL, sizeof(codelen+5), MEM_COMMIT, PAGE_EXECUTE);
    *retjmp=(DWORD)path+dstlen-((DWORD)pCode+codelen+5);
    WriteProcessMemory(hProcess,(void*)pCode,(void*)&ASM_CODE[0],codelen+5,NULL);
    //
    byte HookCode[5]= {0xE9};
    DWORD*jmp=(DWORD*)&HookCode[1];
    *jmp=(DWORD)pCode-(DWORD)path-5;
    hi->HOOK_CODE=malloc(dstlen);
    hi->HOOK_CODE_LENGTH=dstlen;
    ReadProcessMemory(hProcess,path,hi->HOOK_CODE,dstlen,NULL);
    WriteProcessMemory(hProcess,path,HookCode,5,NULL);
    //
    hi->HOOK_PATH=path;
    hi->ASM_PATH=pCode;
    Sleep(200);
}

void un_inline_hook(HANDLE hProcess,PHOOK_INFO hi)
{
    WriteProcessMemory(hProcess,hi->HOOK_PATH,hi->HOOK_CODE,hi->HOOK_CODE_LENGTH,NULL);
    VirtualFreeEx(hProcess,hi->ASM_PATH,0,MEM_RELEASE);
}

DWORD GetGameID(LPCTSTR pName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnapshot)
    {
        return 0;
    }
    PROCESSENTRY32 pe = {sizeof(pe)};
    BOOL fOk;
    for (fOk = Process32First(hSnapshot, &pe); fOk; fOk = Process32Next(hSnapshot, &pe))
    {
        if (!_tcscmp(pe.szExeFile, pName))
        {
            CloseHandle(hSnapshot);
            return pe.th32ProcessID;
        }
    }
    return 0;
}

int memmem(char * a, int alen, char * b, int blen)
{
    int i,j;
    for(i=0; i<alen-blen; ++i)
    {
        for(j=0; j<blen; ++j)
        {
            if(a[i+j]!=b[j])
            {
                break;
            }
        }
        if(j>=blen)
        {
            return i;
        }
    }
    return -1;
}

int ctoh(char hex)
{
    if (hex >= '0' && hex <= '9') return hex - '0';
    if (hex >= 'A' && hex <= 'F') return hex - 'A' + 10;
    if (hex >= 'a' && hex <= 'f') return hex - 'a' + 10;
    return 0;
}

int getHexCode(const char *str,byte *res)
{
    char tmp[2]="";
    int j=0;
    int k=0;
    for(unsigned i=0; i<strlen(str); i++)
    {
        char c=str[i];
        if((c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z'))
        {
            if(j%2==1)
            {
                tmp[1]=str[i];
                int v=0x10*ctoh(tmp[0])+ctoh(tmp[1]);
                res[k]=v;
                k++;
            }
            else if(j%2==0)
            {
                tmp[0]=str[i];
            }
            j++;
        }
    }
    return k;
}

int aobscan(HANDLE hProcess,char *aob,int beginaddr)
{
    byte b[256];
    int len=getHexCode(aob,b);
    MEMORY_BASIC_INFORMATION mbi;
    int i=beginaddr;
    while(i<0x7FFFFFFF)
    {
        VirtualQueryEx(hProcess,(void*)i,&mbi,28);
        //printf("%d",mbi.RegionSize);
        if((int)mbi.RegionSize<=0)
        {
            break;
        }
        if(mbi.Protect!=64||mbi.State!=MEM_COMMIT)
        {
            int ti=(int)i;
            i+=mbi.RegionSize;
            if(i<=ti)
            {
                break;
            }
            continue;
        }
        //int j;
        //for(j=0; j<(int)mbi.RegionSize/4096; j++)
        //
        char *mem=(char*)malloc((int)mbi.RegionSize);
        ReadProcessMemory(hProcess,(void*)i,mem,(int)mbi.RegionSize,0);
        int r=memmem(mem,(int)mbi.RegionSize,(char*)b,len);
        if(r>=0)
        {
            return i+r;
        }
        int ti=(int)i;
        i+=mbi.RegionSize;
        if(i<=ti)
        {
            break;
        }
        //}
    }
    return -1;
}
