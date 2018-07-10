#ifndef _HACK_API

#define _HACK_API

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include "cpuid.h"
#include "../MyCheatLibrary/CheatLibrary/CheatLibrary.h"


typedef struct
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
} tag_OFFSET_ITEM;

__declspec(dllexport)
void SendNetMessage(int msgType,int remoteClient,int ignoreClient,int number,float number2,float number3,float number4,int number5,int number6,int number7);

__declspec(dllexport)
wchar_t *ReadUUID();
__declspec(dllexport)
int RandomUUID();


__declspec(dllexport)
byte getPlayerActive(int pid);


__declspec(dllexport)
int GetNetMode();
__declspec(dllexport)
void DropLiquid(int X,int Y,byte header);

__declspec(dllexport)
void SendNetWater(int X,int Y);

__declspec(dllexport)
void Player_AddBuff(int pid,int buff,int time);
__declspec(dllexport)
void NewNPC(float X,float Y,int Type,int number);

__declspec(dllexport)
void NPC_AddBuff(int nid,int buff,int time);
__declspec(dllexport)
byte getNPCActive(int nid);

__declspec(dllexport)
int EnableAllRecipes();
__declspec(dllexport)
int De_EnableAllRecipes();

__declspec(dllexport)
int StrengthenVampireKnives();
__declspec(dllexport)
int De_StrengthenVampireKnives();

__declspec(dllexport)
void SetItemDefaults(int slot,int type,int prefix);


__declspec(dllexport)
void setItemArrayOffset(int off);

__declspec(dllexport)
int getPlayerItemBase(int id);
__declspec(dllexport)
void setPlayerItemBase(int id,int ibase);


__declspec(dllexport)
int getMyPlayer();
__declspec(dllexport)
void setMyPlayer(int index);


__declspec(dllexport)
void* getPlayerBase(int pid,HANDLE hP);
void* getPlayerBaseAddress(int player);
int aobscan(HANDLE hProcess,const char *aob,int beginaddr);
int getHexCode(const char *str,byte *res);
void* inline_hook(HANDLE hProcess,void*path,int dstlen,byte *code,int codelen);
void un_inline_hook(HANDLE hProcess,char *aobstr,char *headstr,int off);
__declspec(dllexport)
//byte PassWord(char *w);
int memmem(char * a, int alen, char * b, int blen);
int ctoh(char hex);
__declspec(dllexport)
int search_replace(char *src,char *dst);
int search_only(char *src);
void _Read_FromBase(void* baseaddr,void*v,int len,int n,...);
void _Hack(void* baseaddr,void*v,int len,int n,...);

__declspec(dllexport)
void* InitEax(int pid);





__declspec(dllexport)
int InfiniteHealth();
__declspec(dllexport)
int InfiniteMana();
__declspec(dllexport)
int InfiniteMinion();
__declspec(dllexport)
int InfiniteItems();
__declspec(dllexport)
int InfiniteFly();
__declspec(dllexport)
int AwfulFishingSkill();
__declspec(dllexport)
int GhostMode();
__declspec(dllexport)
int InfiniteOxygen();
__declspec(dllexport)
int InfiniteBullet();
__declspec(dllexport)
int NoRespawnTime();
__declspec(dllexport)
int AttackThroughWalls();
__declspec(dllexport)
int ProjectileIgnoreTiles();
__declspec(dllexport)
int JumpAsFeather();
__declspec(dllexport)
int FastSpeed();
__declspec(dllexport)
int KillAllNPC();
__declspec(dllexport)
int GrabItemFarAway();
__declspec(dllexport)
int ToggleTime();
__declspec(dllexport)
int AddExtraSlots();
__declspec(dllexport)
int PumpkinMoon();
__declspec(dllexport)
int SnowMoon();
__declspec(dllexport)
int BloodMoon();
__declspec(dllexport)
int Eclipse();
__declspec(dllexport)
int SunDial();
__declspec(dllexport)
int GoldHoleDropBag();
__declspec(dllexport)
int SlimeGunBurn();
__declspec(dllexport)
int FastTileSpeed();
__declspec(dllexport)
int De_FastTileSpeed();
__declspec(dllexport)
int RulerEffect();
__declspec(dllexport)
int NoPotionDelay();
__declspec(dllexport)
int KillAllScreen();


__declspec(dllexport)
int De_RulerEffect();
__declspec(dllexport)
int MachinicalRulerEffect();
__declspec(dllexport)
int De_MachinicalRulerEffect();
__declspec(dllexport)
int InfernoEffect();
__declspec(dllexport)
int De_InfernoEffect();
__declspec(dllexport)
int ShadowDodge();
__declspec(dllexport)
int De_ShadowDodge();
__declspec(dllexport)
int ShowCircuit();
__declspec(dllexport)
int De_ShowCircuit();
__declspec(dllexport)
int FishOnlyCrates();
__declspec(dllexport)
int De_FishOnlyCrates();
__declspec(dllexport)
int De_InfiniteHealth();
__declspec(dllexport)
int De_InfiniteMana();
__declspec(dllexport)
int De_InfiniteItems();
__declspec(dllexport)
int De_InfiniteMinion();
__declspec(dllexport)
int De_InfiniteFly();
__declspec(dllexport)
int De_AwfulFishingSkill();
__declspec(dllexport)
int De_GhostMode();
__declspec(dllexport)
int De_InfiniteOxygen();
__declspec(dllexport)
int De_InfiniteBullet();
__declspec(dllexport)
int De_NoRespawnTime();
__declspec(dllexport)
int De_AttackThroughWalls();
__declspec(dllexport)
int De_ProjectileIgnoreTiles();
__declspec(dllexport)
int De_JumpAsFeather();
__declspec(dllexport)
int De_FastSpeed();
__declspec(dllexport)
int De_KillAllNPC();
__declspec(dllexport)
int De_GrabItemFarAway();
__declspec(dllexport)
int De_AddExtraSlots();
__declspec(dllexport)
int De_GoldHoleDropBag();
__declspec(dllexport)
int De_SlimeGunBurn();
__declspec(dllexport)
int De_NoPotionDelay();
__declspec(dllexport)
int De_KillAllScreen();



__declspec(dllexport)
int getHealth();
__declspec(dllexport)
void setHealth(int health);
__declspec(dllexport)
int getMaxHealth();
__declspec(dllexport)
void setMaxHealth(int health);
__declspec(dllexport)
int getMana();
__declspec(dllexport)
void setMana(int mana);
__declspec(dllexport)
int getMaxMana();
__declspec(dllexport)
void setMaxMana(int mana);



__declspec(dllexport)
int getItemType(int slot);
__declspec(dllexport)
void setItemType(int slot,int id);
__declspec(dllexport)
void setItemBait(int slot,int id);
__declspec(dllexport)
int getItemBait(int slot);
__declspec(dllexport)
float getItemKnockBack(int slot);
__declspec(dllexport)
void setItemKnockBack(int slot,float v);
__declspec(dllexport)
int getItemShoot(int slot);
__declspec(dllexport)
void setItemShoot(int slot,int v);
__declspec(dllexport)
float getItemShootSpeed(int slot);
__declspec(dllexport)
void setItemShootSpeed(int slot,float v);
__declspec(dllexport)
int getItemCrit(int slot);
__declspec(dllexport)
void setItemCrit(int slot,int v);
__declspec(dllexport)
int getItemDamage(int slot);
__declspec(dllexport)
void setItemDamage(int slot,int v);
__declspec(dllexport)
int getItemHealLife(int slot);
__declspec(dllexport)
void setItemHealLife(int slot,int v);
__declspec(dllexport)
int getItemHealMana(int slot);
__declspec(dllexport)
void setItemHealMana(int slot,int v);
__declspec(dllexport)
int getItemStack(int slot);
__declspec(dllexport)
void setItemStack(int slot,int v);
__declspec(dllexport)
int getItemUseTime(int slot);
__declspec(dllexport)
void setItemUseTime(int slot,int v);
__declspec(dllexport)
int getItemPick(int slot);
__declspec(dllexport)
void setItemPick(int slot,int v);


__declspec(dllexport)
int getItemAxe(int slot);
__declspec(dllexport)
void setItemAxe(int slot,int v);
__declspec(dllexport)
int getItemHammer(int slot);
__declspec(dllexport)
void setItemHammer(int slot,int v);

__declspec(dllexport)
int getItemTileBoost(int slot);
__declspec(dllexport)
void setItemTileBoost(int slot,int v);
__declspec(dllexport)
byte getItemAutoReuse(int slot);
__declspec(dllexport)
void setItemAutoReuse(int slot,byte v);
__declspec(dllexport)
int getItemUseAnimation(int slot);
__declspec(dllexport)
void setItemUseAnimation(int slot,int v);
__declspec(dllexport)
int getItemBuffType(int slot);
__declspec(dllexport)
void setItemBuffType(int slot,int v);
__declspec(dllexport)
int getItemBuffTime(int slot);
__declspec(dllexport)
void setItemBuffTime(int slot,int v);
__declspec(dllexport)
byte getItemPrefix(int slot);
__declspec(dllexport)
void setItemPrefix(int slot,byte v);
__declspec(dllexport)
float getItemScale(int slot);
__declspec(dllexport)
void setItemScale(int slot,float v);
__declspec(dllexport)
int getItemDefense(int slot);
__declspec(dllexport)
void setItemDefense(int slot,int v);



__declspec(dllexport)
byte getItemAccessory(int slot);
__declspec(dllexport)
void setItemAccessory(int slot,byte v);
__declspec(dllexport)
int getItemTileID(int slot);
__declspec(dllexport)
void setItemTileID(int slot,int tileID);
__declspec(dllexport)
int getItemCreateWall(int slot);
__declspec(dllexport)
void setItemCreateWall(int slot,int wallID);
__declspec(dllexport)
int getItemFishingPole(int slot);
__declspec(dllexport)
void setItemFishingPole(int slot,int fishingPole);
__declspec(dllexport)
int getItemMana(int slot);
__declspec(dllexport)
void setItemMana(int slot,int mana);
__declspec(dllexport)
int getItemMaxStack(int slot);
__declspec(dllexport)
void setItemMaxStack(int slot,int max);
__declspec(dllexport)
int getItemUseStyle(int slot);
__declspec(dllexport)
void setItemUseStyle(int slot,int style);
__declspec(dllexport)
int getItemPlaceStyle(int slot);
__declspec(dllexport)
void setItemPlaceStyle(int slot,int style);
__declspec(dllexport)
int getItemRare(int slot);
__declspec(dllexport)
void setItemRare(int slot,int rare);
__declspec(dllexport)
int getItemReuseDelay(int slot);
__declspec(dllexport)
void setItemReuseDelay(int slot,int delay);
__declspec(dllexport)
int getItemTileWand(int slot);
__declspec(dllexport)
void setItemTileWand(int slot,int wand);
__declspec(dllexport)
int getItemUseAmmo(int slot);
__declspec(dllexport)
void setItemUseAmmo(int slot,int ammo);
__declspec(dllexport)
int getItemValue(int slot);
__declspec(dllexport)
void setItemValue(int slot,int val);




__declspec(dllexport)
short getItemGlowMask(int slot);
__declspec(dllexport)
void setItemGlowMask(int slot,short glow);
__declspec(dllexport)
short getItemMakeNPC(int slot);
__declspec(dllexport)
void setItemMakeNPC(int slot,short npc);




__declspec(dllexport)
int getItemAmmo(int slot);
__declspec(dllexport)
void setItemAmmo(int slot,int ammo);
__declspec(dllexport)
byte getItemHeadSlot(int slot);
__declspec(dllexport)
void setItemHeadSlot(int slot,byte headSlot);
__declspec(dllexport)
byte getItemBodySlot(int slot);
__declspec(dllexport)
void setItemBodySlot(int slot,byte bodySlot);
__declspec(dllexport)
byte getItemLegSlot(int slot);
__declspec(dllexport)
void setItemLegSlot(int slot,byte legSlot);
__declspec(dllexport)
byte getItemBalloonSlot(int slot);
__declspec(dllexport)
void setItemBalloonSlot(int slot,byte ballSlot);
__declspec(dllexport)
byte getItemFrontSlot(int slot);
__declspec(dllexport)
void setItemFrontSlot(int slot,byte frontSlot);
__declspec(dllexport)
byte getItemWaistSlot(int slot);
__declspec(dllexport)
void setItemWaistSlot(int slot,byte waistSlot);
__declspec(dllexport)
byte getItemWingSlot(int slot);
__declspec(dllexport)
void setItemWingSlot(int slot,byte wingSlot);
__declspec(dllexport)
byte getItemBackSlot(int slot);
__declspec(dllexport)
void setItemBackSlot(int slot,byte backSlot);
__declspec(dllexport)
byte getItemFaceSlot(int slot);
__declspec(dllexport)
void setItemFaceSlot(int slot,byte faceSlot);
__declspec(dllexport)
byte getItemHandOnSlot(int slot);
__declspec(dllexport)
void setItemHandOnSlot(int slot,byte handOnSlot);
__declspec(dllexport)
byte getItemHandOffSlot(int slot);
__declspec(dllexport)
void setItemHandOffSlot(int slot,byte handOffSlot);
__declspec(dllexport)
byte getItemNeckSlot(int slot);
__declspec(dllexport)
void setItemNeckSlot(int slot,byte neckSlot);
__declspec(dllexport)
byte getItemDye(int slot);
__declspec(dllexport)
void setItemDye(int slot,byte dye);
__declspec(dllexport)
byte getItemShieldSlot(int slot);
__declspec(dllexport)
void setItemShieldSlot(int slot,byte shield);
__declspec(dllexport)
byte getItemShoeSlot(int slot);
__declspec(dllexport)
void setItemShoeSlot(int slot,byte shoe);
__declspec(dllexport)
byte getItemPaint(int slot);
__declspec(dllexport)
void setItemPaint(int slot,byte paint);

__declspec(dllexport)
byte getItemCartTrack(int slot);
__declspec(dllexport)
void setItemCartTrack(int slot,byte cart);
__declspec(dllexport)
byte getItemConsumable(int slot);
__declspec(dllexport)
void setItemConsumable(int slot,byte cons);
__declspec(dllexport)
byte getItemNoUseGraphic(int slot);
__declspec(dllexport)
void setItemNoUseGraphic(int slot,byte no);


__declspec(dllexport)
int getItemLifeRegen(int slot);
__declspec(dllexport)
void setItemLifeRegen(int slot,int regen);
__declspec(dllexport)
int getItemHoldStyle(int slot);
__declspec(dllexport)
void setItemHoldStyle(int slot,int style);
__declspec(dllexport)
byte getItemMagic(int slot);
__declspec(dllexport)
void setItemMagic(int slot,byte magic);
__declspec(dllexport)
byte getItemMech(int slot);
__declspec(dllexport)
void setItemMech(int slot,byte mech);
__declspec(dllexport)
byte getItemMelee(int slot);
__declspec(dllexport)
void setItemMelee(int slot,byte melee);
__declspec(dllexport)
byte getItemNoMelee(int slot);
__declspec(dllexport)
void setItemNoMelee(int slot,byte melee);
__declspec(dllexport)
byte getItemRanged(int slot);
__declspec(dllexport)
void setItemRanged(int slot,byte melee);
__declspec(dllexport)
byte getItemMaterial(int slot);
__declspec(dllexport)
void setItemMaterial(int slot,byte mat);
__declspec(dllexport)
byte getItemSentry(int slot);
__declspec(dllexport)
void setItemSentry(int slot,byte mat);
__declspec(dllexport)
int getItemMountType(int slot);
__declspec(dllexport)
void setItemMountType(int slot,int type);
__declspec(dllexport)
short getItemHairDye(int slot);
__declspec(dllexport)
void setItemHairDye(int slot,short dye);
__declspec(dllexport)
byte getItemQuestItem(int slot);
__declspec(dllexport)
void setItemQuestItem(int slot,byte quest);
__declspec(dllexport)
byte getItemThrown(int slot);
__declspec(dllexport)
void setItemThrown(int slot,byte thrown);
__declspec(dllexport)
byte getItemInstanced(int slot);
__declspec(dllexport)
void setItemInstanced(int slot,byte ins);
__declspec(dllexport)
byte getItemExpertOnly(int slot);
__declspec(dllexport)
void setItemExpertOnly(int slot,byte expert);
__declspec(dllexport)
byte getItemExpert(int slot);
__declspec(dllexport)
void setItemExpert(int slot,byte expert);
__declspec(dllexport)
byte getItemSummon(int slot);
__declspec(dllexport)
void setItemSummon(int slot,byte summon);
__declspec(dllexport)
byte getItemNoWet(int slot);
__declspec(dllexport)
void setItemNoWet(int slot,byte noWet);
__declspec(dllexport)
byte getItemVanity(int slot);
__declspec(dllexport)
void setItemVanity(int slot,byte vanity);
__declspec(dllexport)
byte getItemChannel(int slot);
__declspec(dllexport)
void setItemChannel(int slot,byte channel);
__declspec(dllexport)
int getItemManaIncrease(int slot);
__declspec(dllexport)
void setItemManaIncrease(int slot,int inc);
__declspec(dllexport)
int getItemRelease(int slot);
__declspec(dllexport)
void setItemRelease(int slot,int rel);
__declspec(dllexport)
byte getItemActive(int slot);
__declspec(dllexport)
void setItemActive(int slot,byte active);
__declspec(dllexport)
byte getItemPotion(int slot);
__declspec(dllexport)
void setItemPotion(int slot,byte potion);
__declspec(dllexport)
byte getItemUseTurn(int slot);
__declspec(dllexport)
void setItemUseTurn(int slot,byte useTurn);
__declspec(dllexport)
byte getItemBuy(int slot);
__declspec(dllexport)
void setItemBuy(int slot,byte buy);
__declspec(dllexport)
byte getItemUniqueStack(int slot);
__declspec(dllexport)
void setItemUniqueStack(int slot,byte uni);
__declspec(dllexport)
byte getItemFavorited(int slot);
__declspec(dllexport)
void setItemFavorited(int slot,byte fav);
__declspec(dllexport)
byte getItemFlame(int slot);
__declspec(dllexport)
void setItemFlame(int slot,byte flame);
__declspec(dllexport)
int getItemAlpha(int slot);
__declspec(dllexport)
void setItemAlpha(int slot,int alpha);


__declspec(dllexport)
int getItemShopSpecialCurrency(int slot);
__declspec(dllexport)
void setItemShopSpecialCurrency(int slot,int sh);
__declspec(dllexport)
int getItemShopCustomPrice(int slot);
__declspec(dllexport)
void setItemShopCustomPrice(int slot,int sh);


__declspec(dllexport)
float getX();
__declspec(dllexport)
void setX(float X);
__declspec(dllexport)
float getY();
__declspec(dllexport)
void setY(float Y);
__declspec(dllexport)
int getItemCreateTile(int slot);
__declspec(dllexport)
void setItemCreateTile(int slot,int tileID);
__declspec(dllexport)
int HighLight();
__declspec(dllexport)
int De_HighLight();
__declspec(dllexport)
int IgnoreRange();
__declspec(dllexport)
int De_IgnoreRange();
__declspec(dllexport)
int getPlayerBuffType(int pid,int id);
__declspec(dllexport)
int getPlayerBuffTime(int pid,int id);
__declspec(dllexport)
int getBuffType(int id);
__declspec(dllexport)
void setBuffType(int id,int type);
__declspec(dllexport)
int getBuffTime(int id);
__declspec(dllexport)
void setBuffTime(int id,int time);
__declspec(dllexport)
wchar_t *getPlayerName(int id,int *len);
__declspec(dllexport)
float getPlayerX(int id);
__declspec(dllexport)
float getPlayerY(int id);
__declspec(dllexport)
int getPlayerHealth(int id);
__declspec(dllexport)
int getPlayerMaxHealth(int id);
__declspec(dllexport)
int getPlayerItem(int id,int slot);
__declspec(dllexport)
int getPlayerItemNum(int id,int slot);



__declspec(dllexport)
int getDropedItemID(int index);
__declspec(dllexport)
void setDropedItemID(int index,int id);

__declspec(dllexport)
float getDropedItemX(int index);
__declspec(dllexport)
void setDropedItemX(int index,float X);
__declspec(dllexport)
float getDropedItemY(int index);
__declspec(dllexport)
void setDropedItemY(int index,float Y);
__declspec(dllexport)
int getDropedItemCount(int index);
__declspec(dllexport)
void setDropedItemCount(int index,int count);

__declspec(dllexport)
void FreeMemory(void *v);

__declspec(dllexport)
int getMaxTilesX();
__declspec(dllexport)
int getMaxTilesY();

__declspec(dllexport)
void* getMain_Map();

__declspec(dllexport)
void UpdateLighting(int x,int y,byte light);
__declspec(dllexport)
void RefreshMap();

__declspec(dllexport)
int getSelectedItem();
__declspec(dllexport)
void setSelectedItem(int si);

__declspec(dllexport)
int BlockAttacking();
__declspec(dllexport)
int De_BlockAttacking();
#endif //_HACK_API
