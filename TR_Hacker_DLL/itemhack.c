#include "Func.h"


extern int itemArrOff;
extern tag_OFFSET_ITEM OFFSET_ITEM;


int getItemType(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.type);
    return v;
}

void setItemType(int slot,int id)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&id,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.type);
    _Hack(getPlayerBaseAddress(getMyPlayer()),&id,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.type+0xA0);
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
    _Hack(getPlayerBaseAddress(getMyPlayer()),&pole,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.fishingPole);
}

float getItemKnockBack(int slot)
{
    float v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x8+slot*0x4,OFFSET_ITEM.knockBack);
    return v;
}

void setItemKnockBack(int slot,float v)
{
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
    _Hack(getPlayerBaseAddress(getMyPlayer()),&neckSlot,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.neckSlot);
}

byte getItemDye(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.dye);
    return v;
}
void setItemDye(int slot,byte dye)
{
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
    _Hack(getPlayerBaseAddress(getMyPlayer()),&no,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noUseGraphic);
}


int getItemLifeRegen(int slot)
{
    int val;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.lifeRegen);
    return val;
}


void setItemLifeRegen(int slot,int regen)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&regen,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.lifeRegen);
}


int getItemHoldStyle(int slot)
{
    int val;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.holdStyle);
    return val;
}


void setItemHoldStyle(int slot,int style)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&style,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.holdStyle);
}

byte getItemMagic(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.magic);
    return v;
}

void setItemMagic(int slot,byte magic)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&magic,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.magic);
}

byte getItemMech(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mech);
    return v;
}

void setItemMech(int slot,byte mech)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&mech,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mech);
}

byte getItemMelee(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.melee);
    return v;
}

void setItemMelee(int slot,byte melee)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&melee,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.melee);
}

byte getItemNoMelee(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noMelee);
    return v;
}

void setItemNoMelee(int slot,byte melee)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&melee,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noMelee);
}

byte getItemRanged(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.ranged);
    return v;
}

void setItemRanged(int slot,byte melee)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&melee,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.ranged);
}

byte getItemMaterial(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.material);
    return v;
}

void setItemMaterial(int slot,byte mat)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&mat,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.material);
}

byte getItemSentry(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.sentry);
    return v;
}

void setItemSentry(int slot,byte mat)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&mat,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.sentry);
}

int getItemMountType(int slot)
{
    int val;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mountType);
    return val;
}


void setItemMountType(int slot,int type)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&type,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.mountType);
}

short getItemHairDye(int slot)
{
    short val;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,2,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.hairDye);
    return val;
}


void setItemHairDye(int slot,short dye)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&dye,2,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.hairDye);
}

byte getItemQuestItem(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.questItem);
    return v;
}

void setItemQuestItem(int slot,byte quest)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&quest,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.questItem);
}

byte getItemThrown(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.thrown);
    return v;
}

void setItemThrown(int slot,byte thrown)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&thrown,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.thrown);
}

byte getItemInstanced(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.instanced);
    return v;
}

void setItemInstanced(int slot,byte ins)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&ins,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.instanced);
}

byte getItemExpertOnly(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.expertOnly);
    return v;
}

void setItemExpertOnly(int slot,byte expert)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&expert,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.expertOnly);
}

byte getItemExpert(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.expert);
    return v;
}

void setItemExpert(int slot,byte expert)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&expert,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.expert);
}

byte getItemSummon(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.summon);
    return v;
}

void setItemSummon(int slot,byte summon)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&summon,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.summon);
}

byte getItemNoWet(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noWet);
    return v;
}

void setItemNoWet(int slot,byte noWet)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&noWet,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.noWet);
}

byte getItemVanity(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.vanity);
    return v;
}

void setItemVanity(int slot,byte vanity)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&vanity,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.vanity);
}

byte getItemChannel(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.channel);
    return v;
}

void setItemChannel(int slot,byte channel)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&channel,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.channel);
}

int getItemManaIncrease(int slot)
{
    int val;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.manaIncrease);
    return val;
}


void setItemManaIncrease(int slot,int inc)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&inc,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.manaIncrease);
}

int getItemRelease(int slot)
{
    int val;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&val,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.release);
    return val;
}


void setItemRelease(int slot,int rel)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&rel,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.release);
}


byte getItemActive(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.active);
    return v;
}

void setItemActive(int slot,byte active)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&active,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.active);
}

byte getItemPotion(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.potion);
    return v;
}

void setItemPotion(int slot,byte potion)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&potion,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.potion);
}

byte getItemUseTurn(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.useTurn);
    return v;
}

void setItemUseTurn(int slot,byte useTurn)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&useTurn,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.useTurn);
}

byte getItemBuy(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.buy);
    return v;
}

void setItemBuy(int slot,byte buy)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&buy,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.buy);
}

byte getItemUniqueStack(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.uniqueStack);
    return v;
}

void setItemUniqueStack(int slot,byte uni)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&uni,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.uniqueStack);
}

byte getItemFavorited(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.favorited);
    return v;
}

void setItemFavorited(int slot,byte fav)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&fav,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.favorited);
}

byte getItemFlame(int slot)
{
    byte v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.flame);
    return v;
}

void setItemFlame(int slot,byte flame)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&flame,1,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.flame);
}

int getItemAlpha(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.alpha);
    return v;
}

void setItemAlpha(int slot,int alpha)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&alpha,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.alpha);
}

int getItemShopSpecialCurrency(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shopSpecialCurrency);
    return v;
}

void setItemShopSpecialCurrency(int slot,int sh)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&sh,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shopSpecialCurrency);
}

int getItemShopCustomPrice(int slot)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shopCustomPrice);
    return v;
}

void setItemShopCustomPrice(int slot,int sh)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&sh,4,3,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.shopCustomPrice);
}
