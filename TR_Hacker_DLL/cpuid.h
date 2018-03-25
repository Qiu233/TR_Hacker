
int getCPUIDH();
int getCPUIDL();

void getCPUID(char *str)
{
    int H=getCPUIDH();
    int L=getCPUIDL();
    sprintf(str,"%.8X%.8X",H,L);
}
