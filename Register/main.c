#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void PassWord(char *name,char *cpuid)
{
    int k=0;
    for(int i=0; i<strlen(name); i++)
    {
        k+=name[i];
    }
    int m=0;
    sscanf(cpuid,"%x",&m);
    m=m%64;
    char *rst=(char*)malloc(1024);
    strcpy(rst,"");
    for(int i=0; i<10; i++)
    {
        if(i<strlen(name))
        {
            int v=(name[i]*strlen(name)+37)*k*m;
            char c[100]="";
            sprintf(c,"%x",v);
            strcat(rst,c);
        }
        else
        {
            int v=(name[i-strlen(name)]*strlen(name)+37)*(k%20)*m;
            char c[100]="";
            sprintf(c,"%x",v);
            strcat(rst,c);
        }
    }
    printf("%s\n",rst);
    free(rst);
}

int main()
{
    while(1)
    {
        char a[256]="";
        char b[256]="";
        scanf("%s",a);
        scanf("%s",b);
        PassWord(a,b);
    }
    system("pause");
    return 0;
}
