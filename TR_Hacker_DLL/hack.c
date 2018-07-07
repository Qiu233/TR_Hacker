#include "Func.h"



void* playerarrbase,*dropeditembase,*npcarrbase;
void* tile,*netMode;
void* Terraria_Main_DrawInterface_Resources_Life,*Terraria_Item_SetDefaults,*Terraria_Item_Prefix,*Terraria_NPC_AddBuff,*Terraria_NPC_NewNPC,*Terraria_Player_AddBuff,*Terraria_NetMessage_SendData,*Terraria_Main_Update,*Terraria_WorldGen_SquareTileFrame,*Terraria_NetMessage_sendWater,*Terraria_Map_WorldMap_UpdateLighting;
void* Terraria_Main_AnglerQuestSwap;

HANDLE hProcess;
byte reg=1;
int itemArrOff=0xbc;

void* getPlayerBaseAddress(int player);

struct
{
    int sentry;
    int DD2Summon;
    int shopSpecialCurrency;
    int shopCustomPrice;
    int expert;
    int expertOnly;
    int instanced;
    int thrown;
    int questItem;
    int fishingPole;
    int bait;
    int hairDye;
    int makeNPC;
    int dye;
    int paint;
    int tileWand;
    int notAmmo;
    int netID;
    int prefix;
    int crit;
    int mech;
    int flame;
    int reuseDelay;
    int melee;
    int magic;
    int ranged;
    int summon;
    int placeStyle;
    int buffTime;
    int buffType;
    int mountType;
    int cartTrack;
    int material;
    int noWet;
    int vanity;
    int mana;
    int wet;
    int wetCount;
    int lavaWet;
    int channel;
    int manaIncrease;
    int release;
    int noMelee;
    int noUseGraphic;
    int lifeRegen;
    int shootSpeed;
    int active;
    int alpha;
    int ammo;
    int useAmmo;
    int autoReuse;
    int accessory;
    int axe;
    int healMana;
    int bodySlot;
    int legSlot;
    int headSlot;
    int potion;
    int color;
    int glowMask;
    int consumable;
    int createTile;
    int createWall;
    int damage;
    int defense;
    int hammer;
    int healLife;
    int holdStyle;
    int knockBack;
    int maxStack;
    int pick;
    int rare;
    int scale;
    int shoot;
    int stack;
    int ToolTip;
    int tileBoost;
    int useStyle;
    int UseSound;
    int useTime;
    int useAnimation;
    int value;
    int useTurn;
    int buy;
    int handOnSlot;
    int handOffSlot;
    int backSlot;
    int frontSlot;
    int shoeSlot;
    int waistSlot;
    int wingSlot;
    int shieldSlot;
    int neckSlot;
    int faceSlot;
    int balloonSlot;
    int uniqueStack;
    int favorited;
    int type;
} OFFSET_ITEM;

void SaveOffset()
{
    FILE *fp=fopen("offsets.txt","wb+");
    int *ptr=(int*)&OFFSET_ITEM;
    for(int i=0; i<sizeof(OFFSET_ITEM)/4; i++)
    {
        int data=ptr[i];
        char str[20];
        sprintf(str,"%x",data);
        fputs(str,fp);
        fputc('\n',fp);
    }
    fclose(fp);
}

void InitOffset()
{
    void* Terraria_Item_ResetStats;
    SearchFunctionByName(L"Terraria.Item::ResetStats",&Terraria_Item_ResetStats,1);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xb,&OFFSET_ITEM.sentry,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x12,&OFFSET_ITEM.DD2Summon,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x19,&OFFSET_ITEM.shopSpecialCurrency,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x23,&OFFSET_ITEM.shopCustomPrice,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x30,&OFFSET_ITEM.expert,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x37,&OFFSET_ITEM.expertOnly,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x3e,&OFFSET_ITEM.instanced,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x45,&OFFSET_ITEM.thrown,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x4c,&OFFSET_ITEM.questItem,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x55,&OFFSET_ITEM.fishingPole,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x58,&OFFSET_ITEM.bait,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x5c,&OFFSET_ITEM.hairDye,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x65,&OFFSET_ITEM.makeNPC,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x6b,&OFFSET_ITEM.dye,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x71,&OFFSET_ITEM.paint,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x77,&OFFSET_ITEM.tileWand,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x7e,&OFFSET_ITEM.notAmmo,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x84,&OFFSET_ITEM.netID,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x8a,&OFFSET_ITEM.prefix,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x90,&OFFSET_ITEM.crit,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x96,&OFFSET_ITEM.mech,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x9c,&OFFSET_ITEM.flame,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xa2,&OFFSET_ITEM.reuseDelay,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xa8,&OFFSET_ITEM.melee,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xae,&OFFSET_ITEM.magic,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xb4,&OFFSET_ITEM.ranged,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xba,&OFFSET_ITEM.summon,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xc0,&OFFSET_ITEM.placeStyle,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xc6,&OFFSET_ITEM.buffTime,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xcc,&OFFSET_ITEM.buffType,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xd2,&OFFSET_ITEM.mountType,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xdc,&OFFSET_ITEM.cartTrack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xe2,&OFFSET_ITEM.material,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xe8,&OFFSET_ITEM.noWet,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xee,&OFFSET_ITEM.vanity,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xf4,&OFFSET_ITEM.mana,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xfa,&OFFSET_ITEM.wet,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xfd,&OFFSET_ITEM.wetCount,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x100,&OFFSET_ITEM.lavaWet,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x103,&OFFSET_ITEM.channel,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x109,&OFFSET_ITEM.manaIncrease,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x10f,&OFFSET_ITEM.release,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x115,&OFFSET_ITEM.noMelee,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x11b,&OFFSET_ITEM.noUseGraphic,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x121,&OFFSET_ITEM.lifeRegen,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x129,&OFFSET_ITEM.shootSpeed,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x12f,&OFFSET_ITEM.active,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x133,&OFFSET_ITEM.alpha,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x13f,&OFFSET_ITEM.ammo,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x145,&OFFSET_ITEM.useAmmo,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x14b,&OFFSET_ITEM.autoReuse,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x152,&OFFSET_ITEM.accessory,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x15b,&OFFSET_ITEM.axe,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x161,&OFFSET_ITEM.healMana,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x167,&OFFSET_ITEM.bodySlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x171,&OFFSET_ITEM.legSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x17b,&OFFSET_ITEM.headSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x185,&OFFSET_ITEM.potion,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x18b,&OFFSET_ITEM.color,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x192,&OFFSET_ITEM.glowMask,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x19a,&OFFSET_ITEM.consumable,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1a0,&OFFSET_ITEM.createTile,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1aa,&OFFSET_ITEM.createWall,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1b4,&OFFSET_ITEM.damage,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1be,&OFFSET_ITEM.defense,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1c4,&OFFSET_ITEM.hammer,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1ca,&OFFSET_ITEM.healLife,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1d0,&OFFSET_ITEM.holdStyle,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1d5,&OFFSET_ITEM.knockBack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1db,&OFFSET_ITEM.maxStack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1e5,&OFFSET_ITEM.pick,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1eb,&OFFSET_ITEM.rare,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1f3,&OFFSET_ITEM.scale,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1f9,&OFFSET_ITEM.shoot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1ff,&OFFSET_ITEM.stack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x209,&OFFSET_ITEM.ToolTip,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x20c,&OFFSET_ITEM.tileBoost,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x212,&OFFSET_ITEM.useStyle,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x215,&OFFSET_ITEM.UseSound,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x218,&OFFSET_ITEM.useTime,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x21f,&OFFSET_ITEM.useAnimation,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x226,&OFFSET_ITEM.value,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x22c,&OFFSET_ITEM.useTurn,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x232,&OFFSET_ITEM.buy,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x238,&OFFSET_ITEM.handOnSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x23f,&OFFSET_ITEM.handOffSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x246,&OFFSET_ITEM.backSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x24d,&OFFSET_ITEM.frontSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x254,&OFFSET_ITEM.shoeSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x25b,&OFFSET_ITEM.waistSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x262,&OFFSET_ITEM.wingSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x269,&OFFSET_ITEM.shieldSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x270,&OFFSET_ITEM.neckSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x277,&OFFSET_ITEM.faceSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x27e,&OFFSET_ITEM.balloonSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x285,&OFFSET_ITEM.uniqueStack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x28b,&OFFSET_ITEM.favorited,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x291,&OFFSET_ITEM.type,1,NULL);
    //SaveOffset();
}


WCHAR* getPathShortName(WCHAR *full)
{
    int j=0;
    for(int i=lstrlenW(full);i>0;i--)
    {
        if(full[i]==L'\\')
        {
            j=i;
            break;
        }
    }
    if(j!=0)
    {
        return &full[j+1];
    }
    return NULL;
}

void* getModuleBaseAddress(DWORD PID,WCHAR *name)
{
	HANDLE hSnapShot;
	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, PID);
	MODULEENTRY32W ModuleEntry32;
	ModuleEntry32.dwSize = sizeof(ModuleEntry32);
	if (Module32FirstW(hSnapShot, &ModuleEntry32))
	{
		do
		{
			WCHAR szExt[5];
			lstrcpyW(szExt, ModuleEntry32.szExePath + lstrlenW(ModuleEntry32.szExePath) - 4);
            if(lstrcmpiW(getPathShortName(ModuleEntry32.szExePath),name)==0)
                return ModuleEntry32.modBaseAddr;
		} while (Module32NextW(hSnapShot, &ModuleEntry32));
	}
	CloseHandle(hSnapShot);
	return NULL;
}

int GetNetMode()
{
    int m;
    ReadProcessMemory(hProcess,netMode,&m,4,NULL);
    return m;
}

void DropLiquid(int X,int Y,byte header)
{
    if(reg)
    {
        byte b[500],raw_code[7];
        ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        int blen=getHexCode("83 3D 00000000 01\
                        0F 84 47000000\
                        FF 05 00000000\
                        51\
                        52\
                        50\
                        8B 0D 00000000\
                        B8 00000000\
                        BA 00000000\
                        0FAF 41 0C\
                        01 D0\
                        8B 44 81 18\
                        8B C8\
                        C7 41 0D 00000000\
                        C7 41 0E 00000000\
                        B9 00000000\
                        BA 00000000\
                        6A 01\
                        E8 00000000\
                        58\
                        5A\
                        59\
                        00 00 00000000 00\
                        E9 00 00 00 00",
                            b);
        void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        /*char str[20];
        sprintf(str,"%x",hookAddr);
        MessageBox(0,str,str,MB_OK);*/
        void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
        int *d_flag1=(int*)&b[2];
        int *d_flag2=(int*)&b[15];
        int *d_tile=(int*)&b[24];
        int *d_X1=(int*)&b[29];
        int *d_Y1=(int*)&b[34];
        int *d_liquid=(int*)&b[53];
        int *d_header=(int*)&b[60];
        int *d_X2=(int*)&b[65];
        int *d_Y2=(int*)&b[70];
        int *d_callSTF=(int*)&b[77];
        int *d_code=(int*)&b[84];
        int *d_jmpRet=(int*)&b[blen-4];
        *d_flag1=(int)flagAddr;
        *d_flag2=(int)flagAddr;
        *d_tile=(int)tile;
        *d_X1=X;
        *d_Y1=Y;
        *d_liquid=255;
        *d_header=header;
        *d_X2=X;
        *d_Y2=Y;
        *d_callSTF=Terraria_WorldGen_SquareTileFrame-(hookAddr+77)-4;
        memcpy(d_code,raw_code,7);
        *d_flag2=(int)flagAddr;
        *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
        byte jmpCode[5];
        jmpCode[0]=0xe9;
        *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
        WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
        while(1)
        {
            int flag=0;
            ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
            if(flag==1)
                break;
        }
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
        VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
    }
}

void SendNetWater(int X,int Y)
{
    if(reg)
    {
        byte b[500],raw_code[10];
        ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        int blen=getHexCode("83 3D 00000000 01\
                        0F 84 19000000\
                        FF 05 00000000\
                        51\
                        52\
                        B9 00000000\
                        BA 00000000\
                        E8 00000000\
                        5A\
                        59\
                        00 00 00000000 00\
                        E9 00 00 00 00",
                            b);
        void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        /*char str[20];
        sprintf(str,"%x",hookAddr);
        MessageBox(0,str,str,MB_OK);*/
        void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
        int *d_flag1=(int*)&b[2];
        int *d_flag2=(int*)&b[15];
        int *d_X=(int*)&b[22];
        int *d_Y=(int*)&b[27];
        int *d_callSW=(int*)&b[32];
        int *d_code=(int*)&b[38];
        int *d_jmpRet=(int*)&b[blen-4];
        *d_flag1=(int)flagAddr;
        *d_flag2=(int)flagAddr;
        *d_X=X;
        *d_Y=Y;
        *d_callSW=Terraria_NetMessage_sendWater-(hookAddr+32)-4;
        memcpy(d_code,raw_code,7);
        *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
        byte jmpCode[5];
        jmpCode[0]=0xe9;
        *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
        WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
        while(1)
        {
            int flag=0;
            ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
            if(flag==1)
                break;
        }
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
        VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
    }
}


void SendNetMessage(int msgType,int remoteClient,int ignoreClient,int number,float number2,float number3,float number4,int number5,int number6,int number7)
{
    if(reg)
    {
        int times=1;
        byte b[500],raw_code[10];
        ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        int blen=getHexCode("813D  00000000  00000000\
                        0F84 46000000\
                        51\
                        52\
                        B9 00000000\
                        BA 00000000\
                        \
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        \
                        E8 00000000\
                        5A\
                        59\
                        FF 05 00000000\
                        0000 00000000 00\
                        E9 00000000",
                            b);
        void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        /*char str[20];
        sprintf(str,"%x",hookAddr);
        MessageBox(0,str,str,MB_OK);*/
        void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
        int *d_flag1=(int*)&b[2];
        int *d_times=(int*)&b[6];
        int *d_msgType=(int*)&b[19];
        int *d_remoteClient=(int*)&b[24];
        int *d_ignoreClient=(int*)&b[29];
        int *d_number=(int*)&b[39];
        int *d_number2=(int*)&b[44];
        int *d_number3=(int*)&b[49];
        int *d_number4=(int*)&b[54];
        int *d_number5=(int*)&b[59];
        int *d_number6=(int*)&b[64];
        int *d_number7=(int*)&b[69];
        int *d_jmpSend=(int*)&b[74];
        int *d_flag2=(int*)&b[82];
        int *d_code=(int*)&b[86];
        int *d_jmpRet=(int*)&b[blen-4];
        *d_flag1=(int)flagAddr;
        *d_times=times;
        *d_msgType=msgType;
        *d_remoteClient=remoteClient;
        *d_ignoreClient=ignoreClient;
        *d_number=number;
        *d_number2=number2;
        *d_number3=number3;
        *d_number4=number4;
        *d_number5=number5;
        *d_number6=number6;
        *d_number7=number7;
        *d_jmpSend=Terraria_NetMessage_SendData-(hookAddr+74)-4;
        *d_flag2=(int)flagAddr;
        memcpy(d_code,raw_code,7);
        *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
        byte jmpCode[5];
        jmpCode[0]=0xe9;
        *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
        WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
        while(1)
        {
            int flag=0;
            ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
            if(flag==times)
                break;
        }
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
        VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
    }
}


void NewNPC(float X,float Y,int Type,int number)
{
    if(reg)
    {
        byte b[500],raw_code[7];
        ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        int blen=getHexCode(
                        "813D  00000000  00000000\
                        0F84 3B000000\
                        51\
                        52\
                        B9 00000000\
                        BA 00000000\
                        68 00000000\
                        \
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        E8 00000000\
                        5A\
                        59\
                        FF 05 00000000\
                        0000 00000000 00\
                        E9 00000000"
                        ,b);
        void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
        /*char str[20];
        sprintf(str,"%x",hookAddr);
        MessageBox(0,str,str,MB_OK);*/
        int *d_flag1=(int*)&b[2];
        int *d_number=(int*)&b[6];
        int *d_X=(int*)&b[19];
        int *d_Y=(int*)&b[24];
        int *d_Type=(int*)&b[29];
        int *d_Start=(int*)&b[34];
        int *d_ai0=(int*)&b[39];
        int *d_ai1=(int*)&b[44];
        int *d_ai2=(int*)&b[49];
        int *d_ai3=(int*)&b[54];
        int *d_Target=(int*)&b[59];
        int *d_jmp_NewNPC=(int*)&b[64];
        int *d_flag2=(int*)&b[72];
        int *d_code=(int*)&b[76];
        int *d_jmpRet=(int*)&b[blen-4];
        *d_flag1=(int)flagAddr;
        *d_number=number;
        *d_X=X;
        *d_Y=Y;
        *d_Type=Type;
        *d_Start=0;
        *d_ai0=0;
        *d_ai1=0;
        *d_ai2=0;
        *d_ai3=0;
        *d_Target=getMyPlayer();
        *d_jmp_NewNPC=Terraria_NPC_NewNPC-(hookAddr+64)-4;
        *d_flag2=(int)flagAddr;
        memcpy(d_code,raw_code,7);
        *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
        byte jmpCode[5];
        jmpCode[0]=0xe9;
        *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
        WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
        while(1)
        {
            int flag=0;
            ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
            if(flag==number)
                break;
        }
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
        VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
    }
}

wchar_t *ReadUUID()
{
    if(reg)
    {
        void *Terraria_Main_ClientInitialize;
        SearchFunctionByName(L"Terraria.Main::ClientInitialize",&Terraria_Main_ClientInitialize,1);
        void *v,*v1;
        ReadProcessMemory(hProcess,Terraria_Main_ClientInitialize+0x5c,&v,4,NULL);
        ReadProcessMemory(hProcess,v,&v1,4,NULL);
        wchar_t *UUID=(wchar_t*)malloc(32+4+1);
        ReadProcessMemory(hProcess,v1+8,UUID,(32+4+1)*sizeof(wchar_t),NULL);
        return UUID;
    }
    return NULL;
}



int RandomUUID()
{
    if(reg)
    {
        void *Terraria_Main_ClientInitialize;
        SearchFunctionByName(L"Terraria.Main::ClientInitialize",&Terraria_Main_ClientInitialize,1);
        void *v,*v1;
        ReadProcessMemory(hProcess,Terraria_Main_ClientInitialize+0x5c,&v,4,NULL);
        ReadProcessMemory(hProcess,v,&v1,4,NULL);
        wchar_t uuid[32+4];
        {
            srand((unsigned)time(NULL));
            char tmp_uuid[32+4];
            for(int i=0; i<32+4; i++)
            {
                if(i==8||i==13||i==18||i==23)
                {
                    tmp_uuid[i]='-';
                    continue;
                }
                int d=rand()%16;
                sprintf(&tmp_uuid[i],"%x",d);
            }
            wsprintfW(uuid,L"%hs",tmp_uuid);
        }
        WriteProcessMemory(hProcess,v1+8,uuid,(32+4)*sizeof(wchar_t),NULL);
        return 1;
    }
    return 0;
}

int De_EnableAllRecipes()
{
    if(reg)
    {
        void *Terraria_Recipe_FindRecipes;
        SearchFunctionByName(L"Terraria.Recipe::FindRecipes",&Terraria_Recipe_FindRecipes,1);
        {
            void *addr;
            ReadProcessMemory(hProcess,Terraria_Recipe_FindRecipes+0xd,&addr,4,NULL);
            addr+=(int)Terraria_Recipe_FindRecipes+0xd+4;
            char str[20];
            sprintf(str,"%x",(unsigned)addr);
            VirtualFreeEx(hProcess,addr,0,MEM_RELEASE);
        }
        byte b[6];
        int blen=getHexCode("8D BD 38 FF FF FF",b);
        WriteProcessMemory(hProcess,Terraria_Recipe_FindRecipes+0xc,b,blen,NULL);
        return 1;
    }
    return 0;
}

int EnableAllRecipes()
{
    if(reg)
    {
        void *Terraria_Recipe_FindRecipes;
        SearchFunctionByName(L"Terraria.Recipe::FindRecipes",&Terraria_Recipe_FindRecipes,1);
        byte b[256];
        byte jmp_code[6];
        int blen=getHexCode("8D 65 F4  5B 5E 5F 5D C3",b);
        void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        jmp_code[0]=0xe9;
        jmp_code[5]=0x90;
        int *d_jmp_to=(int*)&jmp_code[1];
        *d_jmp_to=hookAddr-(Terraria_Recipe_FindRecipes+0xC)-5;
        WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
        WriteProcessMemory(hProcess,Terraria_Recipe_FindRecipes+0xC,jmp_code,6,NULL);
        //Sleep(60);
        void *recipeArrAddr=0,*maxRecipe=0;
        {
            void *v;
            ReadProcessMemory(hProcess,Terraria_Recipe_FindRecipes+0x1c,&v,4,NULL);
            ReadProcessMemory(hProcess,v,&recipeArrAddr,4,NULL);
            v=(void*)aobscan(hProcess,"00 8b 85 e8 fd ff ff 3b 05",0);
            ReadProcessMemory(hProcess,v+0x9,&maxRecipe,4,NULL);
            /*char str[20];
            sprintf(str,"%x",v);
            MessageBox(0,str,str,MB_OK);*/
        }
        int MAX=2000;
        for(int i=0; i<MAX; i++)
        {
            void* addr=recipeArrAddr+0x08+i*0x04;
            WriteProcessMemory(hProcess,addr,&i,4,NULL);
        }
        WriteProcessMemory(hProcess,maxRecipe,&MAX,4,NULL);
        return 1;
    }
    return 0;
}

byte getNPCActive(int nid)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(npcarrbase,&v,1,2,0x8+nid*0x4,0x18);
        return v;
    }
    return 0;
}

void NPC_AddBuff(int nid,int buff,int time)
{
    if(reg)
    {
        int addr;
        {
            ReadProcessMemory(hProcess,(void*)(npcarrbase+0x08+0x04*nid),&addr,4,NULL);
        }
        byte b[500],raw_code[7];
        ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        ///mov flag,0
        ///push ecx
        ///push edx
        ///mov ecx,base
        ///mov edx,buffType
        ///push buffTime
        ///push quiet
        ///call Terraria.NPC::AddBuff
        ///pop edx
        ///pop ecx
        ///fild dword ptr [edx+00000340]
        ///mov flag,1
        ///jmp back
        int blen=getHexCode("C7 05 00 00 00 00 00 00 00 00\
                        51\
                        52\
                        B9 00 00 00 00\
                        BA 00 00 00 00\
                        68 00 00 00 00\
                        6A 00\
                        E8 00 00 00 00\
                        5A\
                        59\
                        0000 00000000 00\
                        C7 05 00 00 00 00 01 00 00 00\
                        E9 00 00 00 00",
                            b);
        void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        /*char str[20];
        sprintf(str,"%x",hookAddr);
        MessageBox(0,str,str,MB_OK);*/
        void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
        int *d_flag1=(int*)&b[2];
        int *d_Base=(int*)&b[13];
        int *d_buffType=(int*)&b[18];
        int *d_buffTime=(int*)&b[23];
        int *d_jmpAddBuff=(int*)&b[30];
        int *d_code=(int*)&b[36];
        int *d_flag2=(int*)&b[45];
        int *d_jmpRet=(int*)&b[blen-4];
        *d_flag1=(int)flagAddr;
        *d_Base=addr;
        *d_buffType=buff;
        *d_buffTime=time;
        *d_jmpAddBuff=Terraria_NPC_AddBuff-(hookAddr+30)-4;
        memcpy(d_code,raw_code,7);
        *d_flag2=(int)flagAddr;
        *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
        byte jmpCode[5];
        jmpCode[0]=0xe9;
        *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
        WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
        while(1)
        {
            int flag=0;
            ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
            if(flag==1)
                break;
        }
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
        VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
    }
}

void Player_AddBuff(int pid,int buff,int time)
{
    if(reg)
    {
        int addr;
        {
            ReadProcessMemory(hProcess,(void*)(playerarrbase+0x08+0x04*pid),&addr,4,NULL);
        }
        byte b[500],raw_code[7];
        ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        ///mov flag,0
        ///push ecx
        ///push edx
        ///mov ecx,base
        ///mov edx,buffType
        ///push buffTime
        ///push quiet
        ///call Terraria.NPC::AddBuff
        ///pop edx
        ///pop ecx
        ///fild dword ptr [edx+00000340]
        ///mov flag,1
        ///jmp back
        int blen=getHexCode("C7 05 00 00 00 00 00 00 00 00\
                        51\
                        52\
                        B9 00 00 00 00\
                        BA 00 00 00 00\
                        68 00 00 00 00\
                        6A 00\
                        E8 00 00 00 00\
                        5A\
                        59\
                        0000 00000000 00\
                        C7 05 00 00 00 00 01 00 00 00\
                        E9 00 00 00 00",
                            b);
        void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        /*char str[20];
        sprintf(str,"%x",hookAddr);
        MessageBox(0,str,str,MB_OK);*/
        void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
        int *d_flag1=(int*)&b[2];
        int *d_Base=(int*)&b[13];
        int *d_buffType=(int*)&b[18];
        int *d_buffTime=(int*)&b[23];
        int *d_jmpAddBuff=(int*)&b[30];
        int *d_code=(int*)&b[36];
        int *d_flag2=(int*)&b[45];
        int *d_jmpRet=(int*)&b[blen-4];
        *d_flag1=(int)flagAddr;
        *d_Base=addr;
        *d_buffType=buff;
        *d_buffTime=time;
        *d_jmpAddBuff=Terraria_Player_AddBuff-(hookAddr+30)-4;
        memcpy(d_code,raw_code,7);
        *d_flag2=(int)flagAddr;
        *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
        byte jmpCode[5];
        jmpCode[0]=0xe9;
        *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
        WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
        while(1)
        {
            int flag=0;
            ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
            if(flag==1)
                break;
        }
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
        VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
    }
}


int StrengthenVampireKnives()
{
    if(reg)
    {
        void*path=(void*)aobscan(hProcess,"81 78 6c 21 06 00 00 0f 85",0);
        void* numberAddr=path+0x13;
        int v=0x100;
        WriteProcessMemory(hProcess,numberAddr,&v,4,NULL);
        return 1;
    }
    return 0;
}

int De_StrengthenVampireKnives()
{
    if(reg)
    {
        void*path=(void*)aobscan(hProcess,"81 78 6c 21 06 00 00 0f 85",0);
        void* numberAddr=path+0x13;
        int v=0x4;
        WriteProcessMemory(hProcess,numberAddr,&v,4,NULL);
        return 1;
    }
    return 0;
}

void SetItemDefaults(int slot,int type,int prefix)
{
    if(reg)
    {
        int addr;
        {
            int data;
            ReadProcessMemory(hProcess,(void*)(getPlayerBaseAddress(getMyPlayer())+itemArrOff),&data,4,NULL);
            ReadProcessMemory(hProcess,(void*)(data+0x08+0x04*slot),&addr,4,NULL);
        }
        byte b[500],raw_code[7];
        ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        ///mov flag,0
        ///push ecx
        ///push edx
        ///mov ecx,base
        ///mov edx,Type
        ///push noMatCheck
        ///call Terraria.Item::SetDefaults
        ///mov ecx,base
        ///mov edx,Prefix
        ///call Terraria.Item::Prefix
        ///pop edx
        ///pop ecx
        ///fild dword ptr [edx+00000340]
        ///mov flag,1
        ///jmp back
        int blen=getHexCode("C7 05 00 00 00 00 00 00 00 00\
                        51\
                        52\
                        B9 00 00 00 00\
                        BA 00 00 00 00\
                        6A 00\
                        E8 00 00 00 00\
                        B9 00 00 00 00\
                        BA 00 00 00 00\
                        E8 00 00 00 00\
                        5A\
                        59\
                        00 00 00000000 00\
                        C7 05 00 00 00 00 01 00 00 00\
                        E9 00 00 00 00",
                            b);
        void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        /*char str[20];
        sprintf(str,"%x",hookAddr);
        MessageBox(0,str,str,MB_OK);*/
        void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
        int *d_flag1=(int*)&b[2];
        int *d_itemBase=(int*)&b[13];
        int *d_Type=(int*)&b[18];
        int *d_jmpSetDefaults=(int*)&b[25];
        int *d_itemBase1=(int*)&b[30];
        int *d_Prefix=(int*)&b[35];
        int *d_jmpPrefix=(int*)&b[40];
        int *d_code=(int*)&b[46];
        int *d_flag2=(int*)&b[55];
        int *d_jmpRet=(int*)&b[blen-4];
        *d_flag1=(int)flagAddr;
        *d_itemBase=addr;
        *d_Type=type;
        *d_jmpSetDefaults=Terraria_Item_SetDefaults-(hookAddr+25)-4;
        *d_itemBase1=addr;
        *d_Prefix=prefix;
        *d_jmpPrefix=Terraria_Item_Prefix-(hookAddr+40)-4;
        memcpy(d_code,raw_code,7);
        *d_flag2=(int)flagAddr;
        *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
        byte jmpCode[5];
        jmpCode[0]=0xe9;
        *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
        WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
        while(1)
        {
            int flag=0;
            ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
            if(flag==1)
                break;
        }
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        /*VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
        VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);*/
    }
}



void setItemArrayOffset(int off)
{
    itemArrOff=off;
}

byte PassWord(char *w)
{
    char cpuid[20];
    getCPUID(cpuid);
    char name[100];
    DWORD len=100;
    GetComputerName(name,&len);
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
    if(strcmp(rst,w)==0)
    {
        reg=1;
    }
    else
    {
        reg=0;
    }
    free(rst);
    return reg;
}

LPSTR GetProcessIdByName(int pid)
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
        if(pe.th32ProcessID==pid)
        {
            LPSTR s=(LPSTR)malloc(128);
            ZeroMemory(s,128);
            _tcscpy(s,pe.szExeFile);
            return s;
        }
    }
    return 0;
}

int swprintf(wchar_t*,const wchar_t*,...);

void* getPlayerBase(int pid,HANDLE hP)
{
    {
        char *s=GetProcessIdByName(pid);
        PWCHAR module=(PWCHAR)malloc(256);
        ZeroMemory(module,256);
        swprintf(module,L"%hs",s);
        InitCL(pid,TRUE,module);
    }
    SearchFunctionByName(L"Terraria.Main::DrawInterface_Resources_Life",&Terraria_Main_DrawInterface_Resources_Life,1);
    SearchFunctionByName(L"Terraria.Item::SetDefaults",&Terraria_Item_SetDefaults,1);
    SearchFunctionByName(L"Terraria.NPC::AddBuff",&Terraria_NPC_AddBuff,1);
    SearchFunctionByName(L"Terraria.Player::AddBuff",&Terraria_Player_AddBuff,1);
    SearchFunctionByName(L"Terraria.Item::Prefix",&Terraria_Item_Prefix,1);
    SearchFunctionByName(L"Terraria.NPC::NewNPC",&Terraria_NPC_NewNPC,1);
    SearchFunctionByName(L"Terraria.NetMessage::SendData",&Terraria_NetMessage_SendData,1);
    SearchFunctionByName(L"Terraria.Main::Update",&Terraria_Main_Update,1);
    SearchFunctionByName(L"Terraria.WorldGen::SquareTileFrame",&Terraria_WorldGen_SquareTileFrame,1);
    SearchFunctionByName(L"Terraria.NetMessage::sendWater",&Terraria_NetMessage_sendWater,1);
    SearchFunctionByName(L"Terraria.Main::AnglerQuestSwap",&Terraria_Main_AnglerQuestSwap,1);

    SearchFunctionByName(L"Terraria.Map.WorldMap::UpdateLighting",&Terraria_Map_WorldMap_UpdateLighting,1);



    hProcess=hP;
    InitEax(pid);
    if(getPlayerBaseAddress(getMyPlayer())<=0)
    {
        return (void*)-1;
    }

    ReadProcessMemory(hProcess,Terraria_Main_AnglerQuestSwap+0x8,&netMode,4,NULL);

    void*pkTile;
    SearchFunctionByName(L"Terraria.Player::PickTile",&pkTile,1);
    ReadProcessMemory(hProcess,pkTile+0x36,&tile,4,NULL);

    void* newItemBase;
    SearchFunctionByName(L"Terraria.Item::NewItem",&newItemBase,3);
    void* e;
    ReadProcessMemory(hProcess,newItemBase+0x73,&e,4,NULL);
    ReadProcessMemory(hProcess,e,&dropeditembase,4,NULL);

    void* npcAddHaightBase;
    SearchFunctionByName(L"Terraria.Main::NPCAddHeight",&npcAddHaightBase,1);
    ReadProcessMemory(hProcess,npcAddHaightBase+0x6,&e,4,NULL);
    ReadProcessMemory(hProcess,e,&npcarrbase,4,NULL);
    InitOffset();
    return getPlayerBaseAddress(getMyPlayer());
}


HWND GetXHandle(LPCSTR procName)
{
    DWORD iProcID=0;

    PROCESSENTRY32 pEntry= {sizeof(PROCESSENTRY32)};

    HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPALL,0);
    if(hSnapshot!=INVALID_HANDLE_VALUE)
    {
        if(Process32First(hSnapshot,&pEntry))
        {
            while (Process32Next(hSnapshot, &pEntry))
            {
                if(lstrcmpi(procName, pEntry.szExeFile) == 0)
                {
                    iProcID=pEntry.th32ProcessID;
                    CloseHandle(hSnapshot);
                    break;
                }
            }
        }
    }

    HWND hwnd=GetTopWindow(NULL);
    while(hwnd)
    {
        DWORD pid=0;
        DWORD dwProcessId=GetWindowThreadProcessId(hwnd,&pid);

        if(dwProcessId!=0)
        {
            if(pid==iProcID)
            {
                return hwnd;
            }
        }

        hwnd=GetNextWindow(hwnd,GW_HWNDNEXT);
    }
    return NULL;
}


void* inline_hook(HANDLE hProcess,void*path,int dstlen,byte *code,int codelen)
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
    //hi->HOOK_CODE=malloc(dstlen);
    //hi->HOOK_CODE_LENGTH=dstlen;
    //ReadProcessMemory(hProcess,path,hi->HOOK_CODE,dstlen,NULL);
    WriteProcessMemory(hProcess,path,HookCode,5,NULL);
    //
    //hi->HOOK_PATH=path;
    //hi->ASM_PATH=pCode;
    Sleep(200);
    return pCode;
}
void un_inline_hook(HANDLE hProcess,char *aobstr,char *headstr,int off)
{
    int path1=aobscan(hProcess,aobstr,0);
    if(path1<=0)
    {
        return;
    }
    int path=path1+off;
    byte *b=(byte*)malloc(1024);
    int headlen=getHexCode(headstr,b);
    int addr;
    ReadProcessMemory(hProcess,(void*)(path-headlen+1),&addr,4,NULL);
    /*char str[20];
    sprintf(str,"%x",addr);
    MessageBox(0,str,str,MB_OK);*/
    WriteProcessMemory(hProcess,(void*)(path-headlen),&(b[0]),headlen,NULL);
    VirtualFreeEx(hProcess,(void*)((DWORD)addr+path),0,MEM_RELEASE);
}
void _Read_FromBase(void* baseaddr,void*v,int len,int n,...)
{
    if(!baseaddr)return;
    va_list args;
    va_start(args,n);
    //int baseaddr=getPlayerBaseAddress(getMyPlayer());
    while(n>1)
    {
        int off=va_arg(args,int);
        ReadProcessMemory(hProcess,(void*)baseaddr+off,&baseaddr,4,0);
        n--;
    }
    int off=va_arg(args,int);
    ReadProcessMemory(hProcess,(void*)baseaddr+off,v,len,0);
    va_end(args);
}

void _Hack(void* baseaddr,void*v,int len,int n,...)
{
    if(!baseaddr)return;
    va_list args;
    va_start(args,n);
    //int baseaddr=getPlayerBaseAddress(getMyPlayer());
    while(n>1)
    {
        int off=va_arg(args,int);
        ReadProcessMemory(hProcess,baseaddr+off,&baseaddr,4,0);
        n--;
    }
    void* t=baseaddr+va_arg(args,int);
    WriteProcessMemory(hProcess,t,v,len,0);
    va_end(args);
}
int search_only(char *src)
{
    int addrs=aobscan(hProcess,src,0);
    return addrs;
}
int search_replace(char *src,char *dst)
{
    int addrs;
    int flag=0;
    while((addrs=aobscan(hProcess,src,0))>-1)
    {
        byte b[256];
        int len=getHexCode(dst,b);
        WriteProcessMemory(hProcess,(void*)addrs,b,len,0);
        flag=1;
    }
    return flag;
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


int aobscan(HANDLE hProcess,const char *aob,int beginaddr)
{
    byte b[256];
    int len=getHexCode(aob,b);
    MEMORY_BASIC_INFORMATION mbi;
    int i=beginaddr;
    while(i<0x7fffffff)
    {
        unsigned int flag=VirtualQueryEx(hProcess,(void*)i,&mbi,sizeof(MEMORY_BASIC_INFORMATION));
        if(flag!=sizeof(MEMORY_BASIC_INFORMATION))
            break;
        if((int)mbi.RegionSize<=0)
            break;
        if(mbi.Protect!=64||mbi.State!=MEM_COMMIT)
        {
            i+=mbi.RegionSize;
            continue;
        }
        char *mem=(char*)malloc((int)mbi.RegionSize);
        ReadProcessMemory(hProcess,(void*)i,mem,(int)mbi.RegionSize,0);
        int r=memmem(mem,(int)mbi.RegionSize,(char*)b,len);
        if(r>=0)
        {
            return i+r;
        }
        i+=mbi.RegionSize;
    }
    return -1;
}

int InfiniteHealth()
{
    return search_replace("29 82 40 03 00 00","01 82 40 03 00 00");
}

int InfiniteMana()
{
    if(reg)
    {
        int a=search_replace("29 BE 44 03 00 00","01 BE 44 03 00 00");
        int b=search_replace("29 82 44 03 00 00","01 82 44 03 00 00");
        return a||b;
    }
    return 0;
}

int InfiniteMinion()
{
    if(reg)
        return search_replace("C7 86 14 02 00 00 01 00 00 00","C7 86 14 02 00 00 0 FF FF FF");
    return 0;
}

int InfiniteItems()
{
    if(reg)
        return search_replace("FF 88 80 00 00 00 8B 45 08","90 90 90 90 90 90 8B 45 08");
    return 0;
}

int InfiniteFly()
{
    if(reg)
        return search_replace("D9 99 20 02 00 00 5D C3 00","90 90 90 90 90 90 5D C3 00");
    return 0;
}

int AwfulFishingSkill()
{
    if(reg)
        return search_replace("83 83 00 02 00 00 0F E9 A1 3B 00 00","83 83 00 02 00 00 64 E9 A1 3B 00 00");
    return 0;
}

int GhostMode()
{
    char v=1;
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,1,1,0x549);
    }
    return 0;
}

int InfiniteOxygen()
{
    if(reg)
        return search_replace("FF 88 B4 02 00 00 83 B8 B4 02 00 00 00","90 90 90 90 90 90 83 B8 B4 02 00 00 00");
    return 0;
}

int InfiniteBullet()
{
    if(reg)
        return search_replace("FF 8B 80 00 00 00 83 BB 80","90 90 90 90 90 90");
    return 0;
}

int NoRespawnTime()
{
    if(reg)
        return search_replace("C7 86 E8 02 00 00 58 02 00 00","C7 86 E8 02 00 00 00 00 00 00");
    return 0;
}

int AttackThroughWalls()
{
    if(reg)
        return search_replace("0F 85 D4 03 00 00 8D 55","E9 D5 03 00 00 90 8D 55");
    return 0;
}

int ProjectileIgnoreTiles()
{
    if(reg)
    {
        void* Terraria_Projectile_HandleMovement;
        SearchFunctionByName(L"Terraria.Projectile::HandleMovement",&Terraria_Projectile_HandleMovement,1);
        int aAddr=(int)ceil((int)Terraria_Projectile_HandleMovement/0x10000)*0x10000;
        byte v=0x8d;
        WriteProcessMemory(hProcess,(void*)aobscan(hProcess,"8d 7d d8",aAddr)-0x5,&v,1,NULL);
        return 1;
    }
    return 0;
}

int JumpAsFeather()
{

    if(reg)
    {
        int path=aobscan(hProcess,"89 96 14 04 00 00",0);
        if(path<=0)
        {
            return 0;
        }
        path-=6;
        byte ASM_CODE[]= {0xC7,0x86,0x10,0x04,0x00,0x00,0x00,0x00,0x20,0x41};
        inline_hook(hProcess,(void*)path,6,ASM_CODE,sizeof(ASM_CODE));
        return 1;
    }
    return 0;
}


int FastSpeed()
{

    if(reg)
    {
        int path=aobscan(hProcess,"D9 9E BC 03 00 00 88 96 4B 05 00 00 88 96 4D 05 00 00",0);
        if(path<=0)
        {
            return 0;
        }
        byte ASM_CODE[]= {0xC7,0x86,itemArrOff,0x03,0x00,0x00,0x00,0x20,0x4B,0x46, 0xC7,0x86,0xE4,0x03,0x00,0x00,0x00,0x20,0x4B,0x46};//700????0xC7,0x86,itemArrOff,0x03,0x00,0x00,0x00,0x40,0x9C,0x45,0xC7,0x86,0xE4,0x03,0x00,0x00,0x00,0x40,0x9C,0x45
        inline_hook(hProcess,(void*)path,6,ASM_CODE,sizeof(ASM_CODE));
        return 1;
    }
    return 0;
}


int KillAllNPC()
{

    if(reg)
    {
        int path=aobscan(hProcess,"8B 80 F4 00 00 00 8B 95 C4 B0 FF FF 3B 82 F8 00 00 00 0F 8C",0);
        if(path<=0)
        {
            return 0;
        }
        byte ASM_CODE[]= {0xC7,0x80,0xF4,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        inline_hook(hProcess,(void*)path,6,ASM_CODE,sizeof(ASM_CODE));
        return 1;
    }
    return 0;
}

int GrabItemFarAway()
{
    if(reg)
    {
        int path=aobscan(hProcess,"80 BB 2E 06 00 00 00 74",0);
        int a=path+20;
        int b=path+15;
        int c=path+7;
        int y=path+23;
        int rangeaddr;
        ReadProcessMemory(hProcess,(void*)y,&rangeaddr,4,NULL);
        byte co[]= {0x90,0x90};
        WriteProcessMemory(hProcess,(void*)a,(void*)&co[0],2,NULL);
        WriteProcessMemory(hProcess,(void*)b,(void*)&co[0],2,NULL);
        WriteProcessMemory(hProcess,(void*)c,(void*)&co[0],2,NULL);
        int range=1000;
        WriteProcessMemory(hProcess,(void*)rangeaddr,(void*)&range,4,NULL);
        return 1;
    }
    return 0;
}

int ToggleTime()
{

    if(reg)
    {
        int path1=aobscan(hProcess,"8B 48 28 39 09 FF 15",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1+0x84;
        int timeaddr;
        byte t;
        ReadProcessMemory(hProcess,(void*)path,&timeaddr,4,NULL);
        ReadProcessMemory(hProcess,(void*)timeaddr,&t,1,NULL);
        if(t==0)
        {
            t=1;
        }
        else
        {
            t=0;
        }
        WriteProcessMemory(hProcess,(void*)timeaddr,(void*)&t,1,NULL);
        return 1;
    }
    return 0;
}

int AddExtraSlots()
{
    if(reg)
    {
        int path=aobscan(hProcess,"C7 86 40 01 00 00 01 00 00 00 EB 08 33 D2",0);
        byte t[]= {0x90,0x90}; //74 0C
        WriteProcessMemory(hProcess,(void*)(path-2),(void*)&t[0],2,NULL);
        if(path<=0)
        {
            return 0;
        }
        byte ASM_CODE[]= {0xC7,0x86,0x40,0x01,0x00,0x00,0x02,0x00,0x00,0x00};
        inline_hook(hProcess,(void*)path+0x0E,6,ASM_CODE,sizeof(ASM_CODE));
        return 1;
    }
    return 0;
}



int PumpkinMoon()
{
    if(reg)
    {
        void* Terraria_Main_startPumpkinMoon;
        SearchFunctionByName(L"Terraria.Main::startPumpkinMoon",&Terraria_Main_startPumpkinMoon,1);
        void* pmaddr;
        ReadProcessMemory(hProcess,Terraria_Main_startPumpkinMoon+0x8,&pmaddr,4,NULL);
        int t=0;
        ReadProcessMemory(hProcess,pmaddr,&t,1,NULL);
        t=t==0?1:0;
        WriteProcessMemory(hProcess,pmaddr,(void*)&t,1,NULL);
        return 1;
    }
    return 0;
}

int SnowMoon()
{
    if(reg)
    {
        void* Terraria_Main_startPumpkinMoon;
        SearchFunctionByName(L"Terraria.Main::startPumpkinMoon",&Terraria_Main_startPumpkinMoon,1);
        void* smaddr;
        ReadProcessMemory(hProcess,Terraria_Main_startPumpkinMoon+0xf,&smaddr,4,NULL);
        int t=0;
        ReadProcessMemory(hProcess,smaddr,&t,1,NULL);
        t=t==0?1:0;
        WriteProcessMemory(hProcess,smaddr,(void*)&t,1,NULL);
        return 1;
    }
    return 0;
}

int BloodMoon()
{
    if(reg)
    {
        void* Terraria_Main_startPumpkinMoon;
        SearchFunctionByName(L"Terraria.Main::startPumpkinMoon",&Terraria_Main_startPumpkinMoon,1);
        void* bmaddr;
        ReadProcessMemory(hProcess,Terraria_Main_startPumpkinMoon+0x16,&bmaddr,4,NULL);
        int t=0;
        ReadProcessMemory(hProcess,(void*)(bmaddr),&t,1,NULL);
        t=t==0?1:0;
        WriteProcessMemory(hProcess,(void*)bmaddr,(void*)&t,1,NULL);
        return 1;
    }
    return 0;
}

int Eclipse()
{
    if(reg)
    {
        int path=aobscan(hProcess,"80 B8 83 01 00 00 00 74 15",0);
        if(path<=0)
        {
            return 0;
        }
        int bmaddr;
        ReadProcessMemory(hProcess,(void*)(path+0x48),&bmaddr,4,NULL);
        int t;
        ReadProcessMemory(hProcess,(void*)(bmaddr),&t,1,NULL);
        if(t==0)
        {
            t=1;
        }
        else
        {
            t=0;
        }
        WriteProcessMemory(hProcess,(void*)bmaddr,(void*)&t,1,NULL);
        return 1;
    }
    return 0;
}

int SunDial()
{
    if(reg)
    {
        void* Terraria_Main_UpdateSundial;
        SearchFunctionByName(L"Terraria.Main::UpdateSundial",&Terraria_Main_UpdateSundial,1);
        void* saddr;
        ReadProcessMemory(hProcess,Terraria_Main_UpdateSundial+0x2,&saddr,4,NULL);
        int t=0;
        ReadProcessMemory(hProcess,(void*)(saddr),&t,1,NULL);
        t=t==0?1:0;
        WriteProcessMemory(hProcess,(void*)saddr,(void*)&t,1,NULL);
        return 1;
    }
    return 0;
}


int GoldHoleDropBag()
{
    if(reg)
    {
        int path1=aobscan(hProcess,"8D 85 08 C7 FF FF D9 40 04",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1-0x0c;
        byte b[30];
        int len=getHexCode("68 04 0D 00 00 6A 01 6A 00",b);
        inline_hook(hProcess,(void*)path,6,b,len);
        return 1;
    }
    return 0;
}


int SlimeGunBurn()
{
    if(reg)
    {
        int path1=aobscan(hProcess,"8B 95 CC F3 FF FF 39 09 FF",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1-0x0d;
        byte b[40];
        int len=getHexCode("68 c0 4b 03 00  6a 00  8b 8d 2c 94 ff ff  ba 99 00 00 00     90 39 09",b);///99 /2c
        WriteProcessMemory(hProcess,(void*)path,(void*)&b,len,NULL);
        return 1;
    }
    return 0;
}


int NoPotionDelay()
{
    if(reg)
    {
        int path1=aobscan(hProcess,"89 90 70 04 00 00 8B 85 18 F1 FF FF",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1-0x12;
        byte b[40];
        int len=getHexCode("C7 80 6C 04 00 00 00 00 00 00",b);
        inline_hook(hProcess,(void*)path,6,b,len);
        return 1;
    }
    return 0;
}


int KillAllScreen()
{
    if(reg)
    {
        void *addr=(void*)malloc(4);
        SearchFunctionByName(L"Terraria.Player::ItemCheck",&addr,1);
        void *dst=addr+0x1e008;
        byte b[20];
        int len=getHexCode("90 90 90 90 90 90 90 90",b);
        WriteProcessMemory(hProcess,dst,b,len,NULL);
    }
    return 0;
}




int FastTileSpeed()
{
    if(reg)
    {
        int path1=aobscan(hProcess,"8B 85 18 F1 FF FF D9 80 C4 03 00 00 D9 05",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1-0x6;
        byte b[40];
        int len=getHexCode("D9 98 C8 03 00 00 C7 80 C8 03 00 00 00 00 80 3E",b);
        inline_hook(hProcess,(void*)path,6,b,len);
        return 1;
    }
    return 0;
}


int De_FastTileSpeed()
{
    un_inline_hook(hProcess,"8B 85 18 F1 FF FF D9 80 C4 03 00 00 D9 05","D9 98 C8 03 00 00",0);
    return 1;
}



int RulerEffect()
{
    if(reg)
    {
        int path1=aobscan(hProcess,"88 96 f7 05 00 00 88 96 f8 05 00 00",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1-6;
        byte b[40];
        int len=getHexCode("88 96 F6 05 00 00 C7 86 F6 05 00 00 01 00 00 00",b);
        inline_hook(hProcess,(void*)path,6,b,len);
        return 1;
    }
    return 0;
}


int De_RulerEffect()
{
    un_inline_hook(hProcess,"88 96 F7 05 00 00 88 96 F8 05 00 00","88 96 F6 05 00 00",0);
    return 1;
}


int MachinicalRulerEffect()
{
    if(reg)
    {
        int path1=aobscan(hProcess,"88 96 F7 05 00 00 88 96 F8 05 00 00",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1-6;
        byte b[40];
        int len=getHexCode("88 96 F6 05 00 00 C7 86 F6 05 00 00 01 00 00 00",b);
        inline_hook(hProcess,(void*)path,6,b,len);
        return 1;
    }
    return 0;
}


int De_MachinicalRulerEffect()
{
    un_inline_hook(hProcess,"88 96 F7 05 00 00 88 96 F8 05 00 00","88 96 F6 05 00 00",0);
    return 1;
}


int InfernoEffect()
{
    if(reg)
    {
        int path1=aobscan(hProcess,"88 96 FF 04 00 00 88 96 00 05 00 00",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1-6;
        byte b[40];
        int len=getHexCode("88 96 03 05 00 00 C7 86 03 05 00 00 01 00 00 00",b);
        inline_hook(hProcess,(void*)path,6,b,len);
        return 1;
    }
    return 0;
}


int De_InfernoEffect()
{
    un_inline_hook(hProcess,"88 96 FF 04 00 00 88 96 00 05 00 00","88 96 03 05 00 00",0);
    return 1;
}


int ShadowDodge()
{
    if(reg)
    {
        int path1=aobscan(hProcess,"88 96 33 05 00 00 88 96 A9 05 00 00",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1-6;
        byte b[40];
        int len=getHexCode("88 96 32 05 00 00 C7 86 32 05 00 00 01 00 00 00",b);
        inline_hook(hProcess,(void*)path,6,b,len);
        return 1;
    }
    return 0;
}


int De_ShadowDodge()
{
    un_inline_hook(hProcess,"88 96 33 05 00 00 88 96 A9 05 00 00","88 96 32 05 00 00",0);
    return 1;
}


int ShowCircuit()
{
    if(reg)
    {
        int path1=aobscan(hProcess,"88 96 1D 06 00 00 88 96 1E 06 00 00",0);
        if(path1<=0)
        {
            return 0;
        }
        int path=path1-6;
        byte b[40];
        int len=getHexCode("88 96 2A 06 00 00 C7 86 2A 06 00 00 01 00 00 00",b);
        inline_hook(hProcess,(void*)path,6,b,len);
        return 1;
    }
    return 0;
}

int De_ShowCircuit()
{
    un_inline_hook(hProcess,"88 96 1D 06 00 00 88 96 1E 06 00 00","88 96 2A 06 00 00",0);
    return 1;
}


int FishOnlyCrates()
{
    if(reg)
    {
        search_replace("0f 8d 4F 01 00 00 8b 45","90 90 90 90 90 90");
        return 1;
    }
    return 0;
}

int De_FishOnlyCrates()
{
    search_replace("90 90 90 90 90 90 8B 45 A8 0B 45 A4","0f 8d 4F 01 00 00 8b 45");
    return 1;
}
//88 96 1C 06 00 00 88 96 1D 06 00 00
//88 96 29 06 00 00 C7 86 29 06 00 00 01 00 00 00



int De_InfiniteHealth()
{
    return search_replace("01 82 40 03 00 00","29 82 40 03 00 00");
}

int De_InfiniteMana()
{
    //search_replace("01 BE 44 03 00 00","29 BE 44 03 00 00");
    return search_replace("01 82 44 03 00 00","29 82 44 03 00 00");
}

int De_InfiniteItems()
{
    return search_replace("90 90 90 90 90 90 8B 45 08","FF 88 80 00 00 00 8B 45 08");
}

int De_InfiniteMinion()
{
    return search_replace("C7 86 14 02 00 00 FF FF FF FF","C7 86 14 02 00 00 01 00 00 00");
}

int De_InfiniteFly()
{
    return search_replace("90 90 90 90 90 90 5D C3 00","D9 99 20 02 00 00 5D C3 00");
}

int De_AwfulFishingSkill()
{
    return search_replace("83 83 00 02 00 00 64 E9 A1 3B 00 00","83 83 00 02 00 00 0F E9 A1 3B 00 00");
}

int De_GhostMode()
{
    char v=0;
    _Hack(getPlayerBaseAddress(getMyPlayer()),&v,1,1,0x549);
    return 0;
}

int De_InfiniteOxygen()
{
    return search_replace("90 90 90 90 90 90 83 B8 B4 02 00 00 00","FF 88 B4 02 00 00 83 B8 B4 02 00 00 00");
}

int De_InfiniteBullet()
{
    return search_replace("90 90 90 90 90 90 83 BB 80","FF 8B 80 00 00 00 83 BB 80");
}

int De_NoRespawnTime()
{
    return search_replace("C7 86 E8 02 00 00 00 00 00 00","C7 86 E8 02 00 00 58 02 00 00");
}

int De_AttackThroughWalls()
{
    return search_replace("E9 D5 03 00 00 90 8D 55","0F 85 D4 03 00 00 8D 55");
}

int De_ProjectileIgnoreTiles()
{
    if(reg)
    {
        void* Terraria_Projectile_HandleMovement;
        SearchFunctionByName(L"Terraria.Projectile::HandleMovement",&Terraria_Projectile_HandleMovement,1);
        int aAddr=(int)ceil((int)Terraria_Projectile_HandleMovement/0x10000)*0x10000;
        byte v=0x84;
        WriteProcessMemory(hProcess,(void*)aobscan(hProcess,"8d 7d d8",aAddr)-0x5,&v,1,NULL);
        return 1;
    }
    return 0;
}

int De_JumpAsFeather()
{
    un_inline_hook(hProcess,"89 96 14 04 00 00","D9 9E 10 04 00 00",0);
    return 1;
}

int De_FastSpeed()
{
    un_inline_hook(hProcess,"88 96 4B 05 00 00 88 96 4D 05 00 00","D9 9E BC 03 00 00",0);
    return 1;
}

int De_KillAllNPC()
{
    un_inline_hook(hProcess,"8B 95 C4 B0 FF FF 3B 82 F8 00 00 00 0F 8C","8B 80 F4 00 00 00",0);
    return 1;
}

int De_GrabItemFarAway()
{
    int path=aobscan(hProcess,"80 BB 2E 06 00 00 00 90 90",0);
    byte b[256];
    char *aob="80 BB 2E 06 00 00 00 74 15 8B 51 6C 83 FA 47 7C 0D 83 FA 4A 7F 08";
    int len=getHexCode(aob,b);
    WriteProcessMemory(hProcess,(void*)path,(void*)&b[0],len,NULL);
    return 1;
}

int De_AddExtraSlots()
{
    int path=aobscan(hProcess,"C7 86 40 01 00 00 01 00 00 00 EB 08",0);
    byte t[]= {0x74,0x0c}; //74 0C
    WriteProcessMemory(hProcess,(void*)(path-2),(void*)&t[0],2,NULL);
    //un_inline_hook(hProcess,"C7 86 40 01 00 00 01 00 00 00 EB 08 33 D2","89 96 40 01 00 00",0x0e);
    int paddr;
    ReadProcessMemory(hProcess,(void*)(path+0x0f),&paddr,4,NULL);
    byte rb[10];
    getHexCode("89 96 40 01 00 00",rb);
    WriteProcessMemory(hProcess,(void*)(path+0x0e),(void*)&rb[0],6,NULL);
    VirtualFreeEx(hProcess,(void*)paddr,0,MEM_RELEASE);
    return 1;
}

int De_GoldHoleDropBag()
{
    un_inline_hook(hProcess,"8D 85 08 C7 FF FF D9 40 04","6A 49 6A 01 6A 00 6A 00 6A 00 6A 00",0);
    return 1;
}

int De_SlimeGunBurn()
{
    int path=aobscan(hProcess,"68 c0 4b 03 00 6a 00 8b 8d 2c 94 ff ff ba 2c 00 00 00 90 39 09",0);
    if(path<=0)
    {
        return 0;
    }
    byte b[40];
    int len=getHexCode("68 dc 05 00 00 6a 00 8b 8d 2c 94 ff ff 8b 95 cc f3 ff ff 39 09",b);
    WriteProcessMemory(hProcess,(void*)path,(void*)&b,len,NULL);
    return 1;
}



int De_NoPotionDelay()
{
    un_inline_hook(hProcess,"89 90 70 04 00 00 8B 85 18 F1 FF FF","89 90 6C 04 00 00",-12);
    return 1;
}

int De_KillAllScreen()
{
    if(reg)
    {
        void *addr=(void*)malloc(4);
        SearchFunctionByName(L"Terraria.Player::ItemCheck",&addr,1);
        void *dst=addr+0x1e008;
        byte b[20];
        int len=getHexCode("85 C0 0F 84 C5 14 00 00",b);
        WriteProcessMemory(hProcess,dst,b,len,NULL);
    }
    return 1;
}




int getHealth()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x340);
    return v;
}

void setHealth(int health)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&health,4,1,0x340);
}


int getMaxHealth()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x338);
    return v;
}

void setMaxHealth(int health)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&health,4,1,0x338);
}

int getMana()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x34c);
    return v;
}

void setMana(int mana)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&mana,4,1,0x34c);
}

int getMaxMana()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x348);
    return v;
}

void setMaxMana(int mana)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&mana,4,1,0x348);
    }
}



float getX()
{
    float v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x20);
    return v;
}

void setX(float X)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&X,4,1,0x20);
}

float getY()
{
    float v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x24);
    return v;
}

void setY(float Y)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&Y,4,1,0x24);
}



int HighLight()
{
    if(reg)
    {
        int path=aobscan(hProcess,"d9 46 08 d9 45 c4 df f1 dd d8 7a 0a 73 08 d9 46 08 d9 5d c4 eb 2c d9 45 c4 dd 05",0);
        if(path<=0)
        {
            return 0;
        }
        byte ASM_CODE[512];
        int len=getHexCode("C7 46 08 00 00 80 3F C7 46 10 00 00 80 3F C7 46 18 00 00 80 3F D9 46 08 D9 45 C4",ASM_CODE);

        inline_hook(hProcess,(void*)path,6,ASM_CODE,len);
        return 1;
    }
    return 0;
}

int De_HighLight()
{
    un_inline_hook(hProcess,"df f1 dd d8 7a 0a 73 08 d9 46 08 d9 5d c4 eb 2c d9 45 c4 dd 05","d9 46 08 d9 45 c4",0);
    return 1;
}


int IgnoreRange()
{
    if(reg)
    {
        int path=aobscan(hProcess,"89 44 8A 08 41 3B",0);
        if(path<=0)
        {
            return 0;
        }
        int t1=path+0x1A;
        int t2=path+0x24;
        int v=999;
        WriteProcessMemory(hProcess,(void*)t1,(void*)&v,4,NULL);
        WriteProcessMemory(hProcess,(void*)t2,(void*)&v,4,NULL);
        return 1;
    }
    return 0;
}

int De_IgnoreRange()
{
    int path=aobscan(hProcess,"89 44 8A 08 41 3B",0);
    if(path<=0)
    {
        return 0;
    }
    int t1=path+0x1A;
    int t2=path+0x24;
    int v1=5;
    int v2=4;
    WriteProcessMemory(hProcess,(void*)t1,(void*)&v1,4,NULL);
    WriteProcessMemory(hProcess,(void*)t2,(void*)&v2,4,NULL);
    return 1;
}

byte getPlayerActive(int pid)
{
    byte v;
    _Read_FromBase(playerarrbase,&v,1,2,0x08+pid*0x04,0x18);
    return v;
}

int getPlayerBuffType(int pid,int id)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,3,0x08+pid*0x04,0xac,0x08+id*0x04);
    return v;
}


int getPlayerBuffTime(int pid,int id)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,3,0x08+pid*0x04,0xb0,0x08+id*0x04);
    return v;
}

int getBuffType(int id)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,2,0xac,0x08+id*0x04);
    return v;
}

void setBuffType(int id,int type)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&type,4,2,0xac,0x08+id*0x04);
}

int getBuffTime(int id)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,2,0xb0,0x08+id*0x04);
    return v;
}

void setBuffTime(int id,int time)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&time,4,2,0xb0,0x08+id*0x04);
}


void* InitEax(int pid)
{
    void* r;
    int f=aobscan(hProcess,"8B 44 90 08 80 B8 E2 05 00 00 00 74 08",0);//Terraria.Lighting::LightTiles+13B - 8B 44 90 08
    if(f<=0)return 0;
    f-=0x13;
    int q;
    ReadProcessMemory(hProcess,(void*)f,&q,4,NULL);
    ReadProcessMemory(hProcess,(void*)q,&r,4,NULL);
    playerarrbase=r;
    /*char *p=(char*)malloc(20);
    itoa(playerarrbase,p,16);
    MessageBoxA(NULL,p,p,MB_OK);*/
    return playerarrbase;
}



wchar_t *getPlayerName(int id,int *len)
{
    setlocale(LC_ALL, "");
    wchar_t *c=(wchar_t*)malloc(40);
    memset(c,0,40);
    _Read_FromBase(playerarrbase,c,40,3,0x08+id*0x04,0x70,0x08);
    *len=wcslen(c);
    return c;
}


float getPlayerX(int id)
{
    float v;
    _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0x20);
    return v;
}


float getPlayerY(int id)
{
    float v;
    _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0x24);
    return v;
}


int getPlayerHealth(int id)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0x340);
    return v;
}


int getPlayerMaxHealth(int id)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0x338);
    return v;
}


int getPlayerItemBase(int id)
{
    if(reg)
    {
        int v;
        _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0xbc);
        return v;
    }
    return 0;
}

void setPlayerItemBase(int id,int ibase)
{
    if(reg)
    {
        _Hack(playerarrbase,&ibase,4,2,0x08+id*0x04,0xbc);
    }
}

int getMyPlayer()
{
    if(reg)
    {
        void *addr;
        SearchFunctionByName(L"Terraria.Main::ReverseGravitySupport",&addr,1);
        addr+=0xb;
        void *addr1;
        ReadProcessMemory(hProcess,addr,&addr1,4,NULL);
        int target;
        ReadProcessMemory(hProcess,addr1,&target,4,NULL);
        return target;
    }
    return 0;
}

void setMyPlayer(int index)
{
    if(reg)
    {
        void *addr;
        SearchFunctionByName(L"Terraria.Main::ReverseGravitySupport",&addr,1);
        addr+=0xb;
        void *addr1;
        ReadProcessMemory(hProcess,addr,&addr1,4,NULL);
        WriteProcessMemory(hProcess,addr1,&index,4,NULL);
    }
}

void* getPlayerBaseAddress(int player)
{
    /*char str[20];
    sprintf(str,"%d",player);
    MessageBox(0,str,str,MB_OK);*/
    void *addr;
    _Read_FromBase(playerarrbase,&addr,4,1,0x8+0x4*player);
    return addr;
}


int getItemType(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.type);
    return v;
}

void setItemType(int slot,int id)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&id,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.type);
        _Hack(getPlayerBaseAddress(getMyPlayer()),&id,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.type+0xA0);
    }
}



int getItemBait(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.bait);
    return v;
}

void setItemBait(int slot,int bait)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&bait,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.bait);
}

int getItemFishingPole(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.fishingPole);
    return v;
}

void setItemFishingPole(int slot,int pole)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&pole,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.fishingPole);
    }
}

float getItemKnockBack(int slot)
{
    float v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.knockBack);
    return v;
}

void setItemKnockBack(int slot,float v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.knockBack);
}

int getItemShoot(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.shoot);
    return v;
}

void setItemShoot(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.shoot);
}

float getItemShootSpeed(int slot)
{
    float v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.shootSpeed);
    return v;
}

void setItemShootSpeed(int slot,float v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.shootSpeed);
}

int getItemCrit(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.crit);
    return v;
}

void setItemCrit(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.crit);
}

int getItemDamage(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.damage);
    return v;
}

void setItemDamage(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.damage);
}

int getItemHealLife(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.healLife);
    return v;
}

void setItemHealLife(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.healLife);
}


int getItemHealMana(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.healMana);
    return v;
}

void setItemHealMana(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.healMana);
}


int getItemStack(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.stack);
    return v;
}

void setItemStack(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.stack);
}


int getItemUseTime(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.useTime);
    return v;
}

void setItemUseTime(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.useTime);
}


int getItemPick(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.pick);
    return v;
}

void setItemPick(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.pick);
}


int getItemAxe(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.axe);
    return v;
}

void setItemAxe(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.axe);
}


int getItemHammer(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.hammer);
    return v;
}

void setItemHammer(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.hammer);
}


int getItemTileBoost(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.tileBoost);
    return v;
}

void setItemTileBoost(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.tileBoost);
}


byte getItemAutoReuse(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.autoReuse);
    return v;
}

void setItemAutoReuse(int slot,byte v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.autoReuse);
}


int getItemUseAnimation(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.useAnimation);
    return v;
}

void setItemUseAnimation(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.useAnimation);
}


int getItemBuffType(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.buffType);
    return v;
}

void setItemBuffType(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.buffType);
}


int getItemBuffTime(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.buffTime);
    return v;
}

void setItemBuffTime(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.buffTime);
}


byte getItemPrefix(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.prefix);
    return v;
}

void setItemPrefix(int slot,byte v)
{
    byte b=v;
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&b,1,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.prefix);
}


float getItemScale(int slot)
{
    float v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.scale);
    return v;
}

void setItemScale(int slot,float v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.scale);
}


int getItemDefense(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.defense);
    return v;
}

void setItemDefense(int slot,int v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.defense);
}



byte getItemAccessory(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.accessory);
    return v;
}

void setItemAccessory(int slot,byte v)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.accessory);
}

int getItemCreateTile(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.createTile);
    return v;
}

void setItemCreateTile(int slot,int tileID)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&tileID,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.createTile);
}

int getItemCreateWall(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.createWall);
    return v;
}

void setItemCreateWall(int slot,int wallID)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&wallID,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.createWall);
}

int getItemMana(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mana);
    return v;
}

void setItemMana(int slot,int mana)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&mana,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mana);
}

int getItemMaxStack(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.maxStack);
    return v;
}

void setItemMaxStack(int slot,int max)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&max,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.maxStack);
}

int getItemUseStyle(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.useStyle);
    return v;
}

void setItemUseStyle(int slot,int style)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&style,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.useStyle);
}

int getItemPlaceStyle(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.placeStyle);
    return v;
}

void setItemPlaceStyle(int slot,int style)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&style,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.placeStyle);
}

int getItemRare(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.rare);
    return v;
}

void setItemRare(int slot,int rare)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&rare,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.rare);
}

int getItemReuseDelay(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.reuseDelay);
    return v;
}

void setItemReuseDelay(int slot,int delay)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&delay,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.reuseDelay);
}

int getItemTileWand(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.tileWand);
    return v;
}

void setItemTileWand(int slot,int wand)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&wand,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.tileWand);
}

int getItemUseAmmo(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.useAmmo);
    return v;
}

void setItemUseAmmo(int slot,int ammo)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&ammo,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.useAmmo);
}

int getItemValue(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.value);
    return v;
}

void setItemValue(int slot,int val)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.value);
}





short getItemGlowMask(int slot)
{
    short v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,2,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.glowMask);
    return v;
}

void setItemGlowMask(int slot,short glow)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&glow,2,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.glowMask);
}

short getItemMakeNPC(int slot)
{
    short v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,2,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.makeNPC);
    return v;
}

void setItemMakeNPC(int slot,short npc)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&npc,2,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.makeNPC);
}




int getItemAmmo(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.ammo);
    return v;
}

void setItemAmmo(int slot,int tileID)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&tileID,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.ammo);
}

byte getItemHeadSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.headSlot);
    return v;
}

void setItemHeadSlot(int slot,byte headSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&headSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.headSlot);
}

byte getItemBodySlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.bodySlot);
    return v;
}

void setItemBodySlot(int slot,byte bodySlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&bodySlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.bodySlot);
}

byte getItemLegSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.legSlot);
    return v;
}

void setItemLegSlot(int slot,byte legSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&legSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.legSlot);
}

byte getItemBalloonSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.balloonSlot);
    return v;
}

void setItemBalloonSlot(int slot,byte ballSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&ballSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.balloonSlot);
}

byte getItemFrontSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.frontSlot);
    return v;
}

void setItemFrontSlot(int slot,byte frontSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&frontSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.frontSlot);
}

byte getItemWaistSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.waistSlot);
    return v;
}

void setItemWaistSlot(int slot,byte waistSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&waistSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.waistSlot);
}

byte getItemWingSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.wingSlot);
    return v;
}

void setItemWingSlot(int slot,byte wingSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&wingSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.wingSlot);
}

byte getItemBackSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.backSlot);
    return v;
}

void setItemBackSlot(int slot,byte backSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&backSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.backSlot);
}

byte getItemFaceSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.faceSlot);
    return v;
}

void setItemFaceSlot(int slot,byte faceSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&faceSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.faceSlot);
}

byte getItemHandOnSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.handOnSlot);
    return v;
}

void setItemHandOnSlot(int slot,byte handOnSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&handOnSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.handOnSlot);
}

byte getItemHandOffSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.handOffSlot);
    return v;
}

void setItemHandOffSlot(int slot,byte handOffSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&handOffSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.handOffSlot);
}

byte getItemNeckSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.neckSlot);
    return v;
}

void setItemNeckSlot(int slot,byte neckSlot)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&neckSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.neckSlot);
}

byte getItemDye(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.dye);
        return v;
    }
    return 0;
}
void setItemDye(int slot,byte dye)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&dye,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.dye);
}

byte getItemShieldSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shieldSlot);
    return v;
}

void setItemShieldSlot(int slot,byte shield)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&shield,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shieldSlot);
}

byte getItemShoeSlot(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shoeSlot);
    return v;
}

void setItemShoeSlot(int slot,byte shoe)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&shoe,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shoeSlot);
}

byte getItemPaint(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.paint);
    return v;
}

void setItemPaint(int slot,byte paint)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&paint,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.paint);
}

byte getItemCartTrack(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.cartTrack);
    return v;
}

void setItemCartTrack(int slot,byte cart)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&cart,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.cartTrack);
}

byte getItemConsumable(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.consumable);
    return v;
}

void setItemConsumable(int slot,byte cons)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&cons,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.consumable);
}

byte getItemNoUseGraphic(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noUseGraphic);
    return v;
}

void setItemNoUseGraphic(int slot,byte no)
{
    if(reg)
        _Hack(getPlayerBaseAddress(getMyPlayer()),&no,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noUseGraphic);
}












int getPlayerItem(int id,int slot)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,4,0x08+id*0x04,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.type);
    return v;
}


int getPlayerItemNum(int id,int slot)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,4,0x08+id*0x04,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.stack);
    return v;
}

int getDropedItemID(int index)
{
    if(reg)
    {
        int val;
        _Read_FromBase(dropeditembase,&val,4,2,0x08+index*0x04,OFFSET_ITEM.type);
        return val;
    }
    return 0;
}


void setDropedItemID(int index,int id)
{
    if(reg)
    {
        _Hack(dropeditembase,&id,4,2,0x08+index*0x04,OFFSET_ITEM.type);
        _Hack(dropeditembase,&id,4,2,0x08+index*0x04,OFFSET_ITEM.type+0xA0);
    }
}


float getDropedItemX(int index)
{
    if(reg)
    {
        float val;
        _Read_FromBase(dropeditembase,&val,4,2,0x08+index*0x04,0x20);
        return val;
    }
    return 0;
}


void setDropedItemX(int index,float X)
{
    if(reg)
    {
        _Hack(dropeditembase,&X,4,2,0x08+index*0x04,0x20);
    }
}

float getDropedItemY(int index)
{
    if(reg)
    {
        float val;
        _Read_FromBase(dropeditembase,&val,4,2,0x08+index*0x04,0x24);
        return val;
    }
    return 0;
}


void setDropedItemY(int index,float Y)
{
    if(reg)
    {
        _Hack(dropeditembase,&Y,4,2,0x08+index*0x04,0x24);
    }
}


int getDropedItemCount(int index)
{
    if(reg)
    {
        int val;
        _Read_FromBase(dropeditembase,&val,4,2,0x08+index*0x04,OFFSET_ITEM.stack);
        return val;
    }
    return 0;
}


void setDropedItemCount(int index,int count)
{
    if(reg)
    {
        _Hack(dropeditembase,&count,4,2,0x08+index*0x04,OFFSET_ITEM.stack);
    }
}


int getItemLifeRegen(int slot)
{
    if(reg)
    {
        int val;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.lifeRegen);
        return val;
    }
    return 0;
}


void setItemLifeRegen(int slot,int regen)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&regen,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.lifeRegen);
    }
}


int getItemHoldStyle(int slot)
{
    if(reg)
    {
        int val;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.holdStyle);
        return val;
    }
    return 0;
}


void setItemHoldStyle(int slot,int style)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&style,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.holdStyle);
    }
}

byte getItemMagic(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.magic);
        return v;
    }
    return 0;
}

void setItemMagic(int slot,byte magic)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&magic,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.magic);
    }
}

byte getItemMech(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mech);
        return v;
    }
    return 0;
}

void setItemMech(int slot,byte mech)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&mech,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mech);
    }
}

byte getItemMelee(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.melee);
        return v;
    }
    return 0;
}

void setItemMelee(int slot,byte melee)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&melee,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.melee);
    }
}

byte getItemNoMelee(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noMelee);
        return v;
    }
    return 0;
}

void setItemNoMelee(int slot,byte melee)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&melee,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noMelee);
    }
}

byte getItemRanged(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.ranged);
        return v;
    }
    return 0;
}

void setItemRanged(int slot,byte melee)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&melee,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.ranged);
    }
}

byte getItemMaterial(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.material);
        return v;
    }
    return 0;
}

void setItemMaterial(int slot,byte mat)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&mat,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.material);
    }
}

byte getItemSentry(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.sentry);
        return v;
    }
    return 0;
}

void setItemSentry(int slot,byte mat)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&mat,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.sentry);
    }
}

int getItemMountType(int slot)
{
    if(reg)
    {
        int val;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mountType);
        return val;
    }
    return 0;
}


void setItemMountType(int slot,int type)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&type,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mountType);
    }
}

short getItemHairDye(int slot)
{
    if(reg)
    {
        short val;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,2,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.hairDye);
        return val;
    }
    return 0;
}


void setItemHairDye(int slot,short dye)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&dye,2,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.hairDye);
    }
}

byte getItemQuestItem(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.questItem);
        return v;
    }
    return 0;
}

void setItemQuestItem(int slot,byte quest)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&quest,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.questItem);
    }
}

byte getItemThrown(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.thrown);
        return v;
    }
    return 0;
}

void setItemThrown(int slot,byte thrown)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&thrown,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.thrown);
    }
}

byte getItemInstanced(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.instanced);
        return v;
    }
    return 0;
}

void setItemInstanced(int slot,byte ins)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&ins,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.instanced);
    }
}

byte getItemExpertOnly(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.expertOnly);
        return v;
    }
    return 0;
}

void setItemExpertOnly(int slot,byte expert)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&expert,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.expertOnly);
    }
}

byte getItemExpert(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.expert);
        return v;
    }
    return 0;
}

void setItemExpert(int slot,byte expert)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&expert,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.expert);
    }
}

byte getItemSummon(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.summon);
        return v;
    }
    return 0;
}

void setItemSummon(int slot,byte summon)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&summon,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.summon);
    }
}

byte getItemNoWet(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noWet);
        return v;
    }
    return 0;
}

void setItemNoWet(int slot,byte noWet)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&noWet,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noWet);
    }
}

byte getItemVanity(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.vanity);
        return v;
    }
    return 0;
}

void setItemVanity(int slot,byte vanity)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&vanity,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.vanity);
    }
}

byte getItemChannel(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.channel);
        return v;
    }
    return 0;
}

void setItemChannel(int slot,byte channel)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&channel,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.channel);
    }
}

int getItemManaIncrease(int slot)
{
    if(reg)
    {
        int val;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.manaIncrease);
        return val;
    }
    return 0;
}


void setItemManaIncrease(int slot,int inc)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&inc,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.manaIncrease);
    }
}

int getItemRelease(int slot)
{
    if(reg)
    {
        int val;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.release);
        return val;
    }
    return 0;
}


void setItemRelease(int slot,int rel)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&rel,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.release);
    }
}


byte getItemActive(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.active);
        return v;
    }
    return 0;
}

void setItemActive(int slot,byte active)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&active,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.active);
    }
}

byte getItemPotion(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.potion);
        return v;
    }
    return 0;
}

void setItemPotion(int slot,byte potion)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&potion,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.potion);
    }
}

byte getItemUseTurn(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.useTurn);
        return v;
    }
    return 0;
}

void setItemUseTurn(int slot,byte useTurn)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&useTurn,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.useTurn);
    }
}

byte getItemBuy(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.buy);
        return v;
    }
    return 0;
}

void setItemBuy(int slot,byte buy)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&buy,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.buy);
    }
}

byte getItemUniqueStack(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.uniqueStack);
        return v;
    }
    return 0;
}

void setItemUniqueStack(int slot,byte uni)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&uni,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.uniqueStack);
    }
}

byte getItemFavorited(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.favorited);
        return v;
    }
    return 0;
}

void setItemFavorited(int slot,byte fav)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&fav,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.favorited);
    }
}

byte getItemFlame(int slot)
{
    if(reg)
    {
        byte v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.flame);
        return v;
    }
    return 0;
}

void setItemFlame(int slot,byte flame)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&flame,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.flame);
    }
}

int getItemAlpha(int slot)
{
    if(reg)
    {
        int v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.alpha);
        return v;
    }
    return 0;
}

void setItemAlpha(int slot,int alpha)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&alpha,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.alpha);
    }
}

int getItemShopSpecialCurrency(int slot)
{
    if(reg)
    {
        int v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shopSpecialCurrency);
        return v;
    }
    return 0;
}

void setItemShopSpecialCurrency(int slot,int sh)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&sh,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shopSpecialCurrency);
    }
}

int getItemShopCustomPrice(int slot)
{
    if(reg)
    {
        int v;
        _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shopCustomPrice);
        return v;
    }
    return 0;
}

void setItemShopCustomPrice(int slot,int sh)
{
    if(reg)
    {
        _Hack(getPlayerBaseAddress(getMyPlayer()),&sh,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shopCustomPrice);
    }
}

void FreeMemory(void *v)
{
	free(v);
}

int getMaxTilesX()
{
    void* f,*r;
    int t;
    SearchFunctionByName(L"Terraria.DelegateMethods::TestDust",&f,1);
    f+=0xd;

    ReadProcessMemory(hProcess,f,&r,4,NULL);
    ReadProcessMemory(hProcess,r,&t,4,NULL);
    return t;
}

int getMaxTilesY()
{
    void* f,*r;
    int t;
    SearchFunctionByName(L"Terraria.DelegateMethods::TestDust",&f,1);
    f+=0x19;

    ReadProcessMemory(hProcess,f,&r,4,NULL);
    ReadProcessMemory(hProcess,r,&t,4,NULL);
    return t;
}

void* getMain_Map()
{
    void* f,*r;
    f=(void*)aobscan(hProcess,"0F 8C 84 FE FF FF 43",0);
    f-=0x15;

    ReadProcessMemory(hProcess,f,&r,4,NULL);
    return r;
}

void UpdateLighting(int x,int y,byte light)
{
    if(reg)
    {
        void* addr=getMain_Map();
        byte b[500],raw_code[7];
        ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        ///mov flag,0
        ///push ecx
        ///push edx
        ///push eax
        ///push ebx
        ///mov ecx,Map
        ///mov edx,X
        ///push Y
        ///push light
        ///call Terraria.Map.WorldMap::UpdateLighting
        ///pop ebx
        ///pop eax
        ///pop edx
        ///pop ecx
        ///xxxx
        ///mov flag,1
        ///jmp back
        int blen=getHexCode("C7 05 00 00 00 00 00 00 00 00\
                        51\
                        52\
                        50\
                        53\
                        8B 0D 00 00 00 00\
                        BA 00 00 00 00\
                        68 00 00 00 00\
                        6A 00\
                        E8 00 00 00 00\
                        5B\
                        58\
                        5A\
                        59\
                        00 00 00000000 00\
                        C7 05 00 00 00 00 01 00 00 00\
                        E9 00 00 00 00",
                            b);
        void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
        int *d_flag1=(int*)&b[2];
        int *d_Map=(int*)&b[16];
        int *d_X=(int*)&b[21];
        int *d_Y=(int*)&b[26];
        byte *d_light=(byte*)&b[31];
        int *d_jmpUpdateLighting=(int*)&b[33];
        int *d_code=(int*)&b[41];
        int *d_flag2=(int*)&b[50];
        int *d_jmpRet=(int*)&b[blen-4];
        *d_flag1=(int)flagAddr;
        *d_Map=(int)addr;
        *d_X=x;
        *d_Y=y;
        *d_light=light;
        *d_jmpUpdateLighting=Terraria_Map_WorldMap_UpdateLighting-(hookAddr+33)-4;
        memcpy(d_code,raw_code,7);
        *d_flag2=(int)flagAddr;
        *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
        byte jmpCode[5];
        jmpCode[0]=0xe9;
        *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
        WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
        while(1)
        {
            int flag=0;
            ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
            if(flag==1)
                break;
        }
        WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
        VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
        VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
    }
}

void RefreshMap()
{

    void *t,*r;
    byte f=1;
    t=(void*)aobscan(hProcess,"E9 CF 00 00 00 8B D8 B9",0);
    t-=0x18;
    ReadProcessMemory(hProcess,t,&r,4,NULL);
    WriteProcessMemory(hProcess,r,&f,4,NULL);
}

int getSelectedItem()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x280);
    return v;
}

void setSelectedItem(int si)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&si,4,1,0x280);
}

int BlockAttacking()
{
    if(reg)
        return search_replace("80 7C 02 08 00 0F 84 DA 02 00 00 83 BD","80 7C 02 08 FF");
    return 0;
}

int De_BlockAttacking()
{
    if(reg)
        return search_replace("80 7C 02 08 FF 0F 84 DA 02 00 00 83 BD","80 7C 02 08 00");
    return 0;
}

