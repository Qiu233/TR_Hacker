/*
 * Created by SharpDevelop.
 * User: Qiu
 * Date: 2016/7/16
 * Time: 12:44
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Runtime.InteropServices;
using System.Collections;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading;
using System.Reflection;
using System.Windows.Forms;

namespace Terraria_Hacker
{
	/// <summary>
	/// Description of HackFunctions.
	/// </summary>
	/// 

	struct Position
	{
		public float X, Y;
		public string Dec;
	}

	public class HackFunctions
	{

		public const int OFFSET_INV = 0xBC, OFFSET_ARMOR = 0x98, OFFSET_DYE = 0x9C, OFFSET_MISC = 0xA0, OFFSET_MISCDYE = 0xA4;
		public static Hashtable warps = new Hashtable();
		private static Thread th;
		private static int itemClipBoard = -1;
		public static bool stop = true;
		private static int[] Debuffs = { 20, 21, 22, 23, 24, 30, 31, 32,
			33, 35, 36, 37, 38, 39, 46, 47, 67, 68, 69, 70, 72, 80,
			88, 94, 144, 145, 148, 149, 153, 156, 160, 163, 164, 169,
			192, 194, 195, 196, 197, 199 };

		public const int ITEM_MAX_COUNT = 59, INV_MAX_COUNT = 50, ARMOR_MAX_COUNT = 20, DYE_MAX_COUNT = 10, MISC_MAX_COUNT = 5, MISCDYE_MAX_COUNT = 5;
		public const int BUFF_MAX_COUNT = 22;
		public static void SaveInv(string name)
		{
			if (File.Exists(name)) File.Delete(name);
			BinaryWriter bw = new BinaryWriter(new FileStream(name, FileMode.OpenOrCreate));
			for (int i = 0; i < ITEM_MAX_COUNT; i++)
			{
				bw.Write(getItemType(i));
				bw.Write(getItemStack(i));
				bw.Write(getItemPrefix(i));
			}
			setItemArrayOffset(OFFSET_ARMOR);
			for (int i = 0; i < ARMOR_MAX_COUNT; i++)
			{
				bw.Write(getItemType(i));
				bw.Write(getItemStack(i));
				bw.Write(getItemPrefix(i));
			}
			setItemArrayOffset(OFFSET_DYE);
			for (int i = 0; i < DYE_MAX_COUNT; i++)
			{
				bw.Write(getItemType(i));
				bw.Write(getItemStack(i));
				bw.Write(getItemPrefix(i));
			}
			setItemArrayOffset(OFFSET_MISC);
			for (int i = 0; i < MISC_MAX_COUNT; i++)
			{
				bw.Write(getItemType(i));
				bw.Write(getItemStack(i));
				bw.Write(getItemPrefix(i));
			}
			setItemArrayOffset(OFFSET_MISCDYE);
			for (int i = 0; i < MISCDYE_MAX_COUNT; i++)
			{
				bw.Write(getItemType(i));
				bw.Write(getItemStack(i));
				bw.Write(getItemPrefix(i));
			}

			setItemArrayOffset(OFFSET_INV);
			bw.Close();
		}
		public static void LoadInv(Form f, string name)
		{
			int j = 0;
			Form p = new Form();
			ProgressBar pb = new ProgressBar();
			Label tip = new Label(), percent = new Label();
			tip.Text = "Loading inventory...";
			tip.Location = new System.Drawing.Point(0, 0);
			tip.Size = new System.Drawing.Size(150, 30);
			tip.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			percent.Location = new System.Drawing.Point(150, 0);
			percent.Size = new System.Drawing.Size(30, 30);
			percent.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			System.Timers.Timer timer = new System.Timers.Timer(1);
			p.FormBorderStyle = FormBorderStyle.FixedSingle;
			p.ClientSize = new System.Drawing.Size(300, 60);
			p.ControlBox = false;
			pb.Location = new System.Drawing.Point(0, 30);
			pb.Size = new System.Drawing.Size(300, 30);
			pb.Maximum = ITEM_MAX_COUNT + ARMOR_MAX_COUNT + DYE_MAX_COUNT + MISC_MAX_COUNT + MISCDYE_MAX_COUNT;
			pb.Minimum = 0;
			pb.Value = 0;
			p.Controls.Add(tip);
			p.Controls.Add(percent);
			p.Controls.Add(pb);
			timer.Elapsed += (sender, e) =>
			{
				pb.Value = j;
				percent.Text = pb.Value + "/" + pb.Maximum;
				if (j >= pb.Maximum) p.Dispose();
			};
			timer.Start();
			p.Show();
			p.Location = new System.Drawing.Point(f.Location.X + f.Width / 2 - p.ClientSize.Width / 2, f.Location.Y + f.Height / 2 - p.ClientSize.Height / 2);
			new Thread((s) =>
			{
				f.Enabled = false;
				BinaryReader br = new BinaryReader(new FileStream(name, FileMode.Open));
				for (int i = 0; i < ITEM_MAX_COUNT; i++)
				{
					j++;
					int type = br.ReadInt32();
					int stack = br.ReadInt32();
					byte prefix = br.ReadByte();
					if (type <= 0 && getItemType(i) <= 0) continue;
					SetItemDefaults(i, type, prefix);
					setItemStack(i, stack);
				}
				setItemArrayOffset(OFFSET_ARMOR);
				for (int i = 0; i < ARMOR_MAX_COUNT; i++)
				{
					j++;
					int type = br.ReadInt32();
					int stack = br.ReadInt32();
					byte prefix = br.ReadByte();
					if (type <= 0 && getItemType(i) <= 0) continue;
					SetItemDefaults(i, type, prefix);
					setItemStack(i, stack);
				}
				setItemArrayOffset(OFFSET_DYE);
				for (int i = 0; i < DYE_MAX_COUNT; i++)
				{
					j++;
					int type = br.ReadInt32();
					int stack = br.ReadInt32();
					byte prefix = br.ReadByte();
					if (type <= 0 && getItemType(i) <= 0) continue;
					SetItemDefaults(i, type, prefix);
					setItemStack(i, stack);
				}
				setItemArrayOffset(OFFSET_MISC);
				for (int i = 0; i < MISC_MAX_COUNT; i++)
				{
					j++;
					int type = br.ReadInt32();
					int stack = br.ReadInt32();
					byte prefix = br.ReadByte();
					if (type <= 0 && getItemType(i) <= 0) continue;
					SetItemDefaults(i, type, prefix);
					setItemStack(i, stack);
				}
				setItemArrayOffset(OFFSET_MISCDYE);
				for (int i = 0; i < MISCDYE_MAX_COUNT; i++)
				{
					j++;
					int type = br.ReadInt32();
					int stack = br.ReadInt32();
					byte prefix = br.ReadByte();
					if (type <= 0 && getItemType(i) <= 0) continue;
					SetItemDefaults(i, type, prefix);
					setItemStack(i, stack);
				}

				setItemArrayOffset(OFFSET_INV);
				br.Close();
				f.Enabled = true;
			}
			).Start();
		}

		public static void AddItem(int type, int stack, byte prefix)
		{
			for (int i = 0; i < INV_MAX_COUNT; i++)
			{
				if (getItemType(i) == 0)
				{
					SetItemDefaults(i, type, prefix);
					setItemStack(i, stack);
					break;
				}
			}
		}

		public static void SetArmor(int index, int type, int stack, byte prefix)
		{
			setItemArrayOffset(OFFSET_ARMOR);
			SetItemDefaults(index, type, prefix);
			setItemStack(index, stack);
			setItemArrayOffset(OFFSET_INV);
		}

		public static void SetDye(int index, int type, int stack, byte prefix)
		{
			setItemArrayOffset(OFFSET_DYE);
			SetItemDefaults(index, type, prefix);
			setItemStack(index, stack);
			setItemArrayOffset(OFFSET_INV);
		}

		public static void SetMisc(int index, int type, int stack, byte prefix)
		{
			setItemArrayOffset(OFFSET_MISC);
			SetItemDefaults(index, type, prefix);
			setItemStack(index, stack);
			setItemArrayOffset(OFFSET_INV);
		}

		public static void SetMiscDye(int index, int type, int stack, byte prefix)
		{
			setItemArrayOffset(OFFSET_MISCDYE);
			SetItemDefaults(index, type, prefix);
			setItemStack(index, stack);
			setItemArrayOffset(OFFSET_INV);
		}

		public static void CopyItem(int s)
		{
			itemClipBoard = s;
		}
		public static bool IsCopiedItem()
		{
			return itemClipBoard != -1;
		}
		public static void PasteItem(int s)
		{
			Assembly assembly = Assembly.GetExecutingAssembly();
			Type type = assembly.GetType("Terraria_Hacker.HackFunctions");
			int raw_id = getItemType(itemClipBoard);
			int raw_count = getItemStack(itemClipBoard);
			byte raw_prefix = getItemPrefix(itemClipBoard);
			SetItemDefaults(s, raw_id, raw_prefix);
			setItemStack(s, raw_count);
		}


		public static int BurnAllNPC()
		{
			int i = 0;
			Form p = new Form();
			ProgressBar pb = new ProgressBar();
			Label tip = new Label(), percent = new Label();
			tip.Text = "Burning NPCS...";
			tip.Location = new System.Drawing.Point(0, 0);
			tip.Size = new System.Drawing.Size(150, 30);
			tip.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			percent.Location = new System.Drawing.Point(150, 0);
			percent.Size = new System.Drawing.Size(50, 30);
			percent.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			System.Timers.Timer timer = new System.Timers.Timer(1);
			p.FormBorderStyle = FormBorderStyle.FixedSingle;
			p.ClientSize = new System.Drawing.Size(300, 60);
			p.ControlBox = false;
			pb.Location = new System.Drawing.Point(0, 30);
			pb.Size = new System.Drawing.Size(300, 30);
			pb.Maximum = 200;
			pb.Minimum = 0;
			pb.Value = 0;
			p.Controls.Add(tip);
			p.Controls.Add(percent);
			p.Controls.Add(pb);
			timer.Elapsed += (sender, e) =>
			{
				pb.Value = i;
				percent.Text = pb.Value + "/" + pb.Maximum;
				if (i >= pb.Maximum) p.Dispose();
			};
			timer.Start();
			p.Show();
			p.Location = new System.Drawing.Point(MainForm.mainWindow.Location.X + MainForm.mainWindow.Width / 2 - p.ClientSize.Width / 2, MainForm.mainWindow.Location.Y + MainForm.mainWindow.Height / 2 - p.ClientSize.Height / 2);
			new Thread(() =>
			{
				MainForm.mainWindow.Enabled = false;
				for (; i < 200; i++)
					if (getNPCActive(i))
						NPC_AddBuff(i, 0x99, 216000);
				MainForm.mainWindow.Enabled = true;
			}).Start();
			return 1;
		}

		public static int BurnAllPlayer()
		{
			int i = 0;
			Form p = new Form();
			ProgressBar pb = new ProgressBar();
			Label tip = new Label(), percent = new Label();
			tip.Text = "Burning Players...";
			tip.Location = new System.Drawing.Point(0, 0);
			tip.Size = new System.Drawing.Size(150, 30);
			tip.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			percent.Location = new System.Drawing.Point(150, 0);
			percent.Size = new System.Drawing.Size(50, 30);
			percent.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			System.Timers.Timer timer = new System.Timers.Timer(1);
			p.FormBorderStyle = FormBorderStyle.FixedSingle;
			p.ClientSize = new System.Drawing.Size(300, 60);
			p.ControlBox = false;
			pb.Location = new System.Drawing.Point(0, 30);
			pb.Size = new System.Drawing.Size(300, 30);
			pb.Maximum = 255;
			pb.Minimum = 0;
			pb.Value = 0;
			p.Controls.Add(tip);
			p.Controls.Add(percent);
			p.Controls.Add(pb);
			timer.Elapsed += (sender, e) =>
			{
				pb.Value = i;
				percent.Text = pb.Value + "/" + pb.Maximum;
				if (i >= pb.Maximum) p.Dispose();
			};
			timer.Start();
			p.Show();
			p.Location = new System.Drawing.Point(MainForm.mainWindow.Location.X + MainForm.mainWindow.Width / 2 - p.ClientSize.Width / 2, MainForm.mainWindow.Location.Y + MainForm.mainWindow.Height / 2 - p.ClientSize.Height / 2);
			new Thread(() =>
			{
				MainForm.mainWindow.Enabled = false;
				for (; i < 255; i++)
					if (getPlayerActive(i))
						Player_AddBuff(i, 44, 216000);
				MainForm.mainWindow.Enabled = true;
			}).Start();
			return 1;
		}


		public static int Aob_Replace(string src, string dst)
		{
			char[] ca = src.ToCharArray();
			sbyte[] a = new sbyte[ca.Length + 1];
			char[] cb = dst.ToCharArray();
			sbyte[] b = new sbyte[cb.Length + 1];

			{
				for (int i = 0; i < ca.Length; i++)
				{
					a[i] = (sbyte)ca[i];
				}
				a[a.Length - 1] = 0;
			}
			{
				for (int i = 0; i < cb.Length; i++)
				{
					b[i] = (sbyte)cb[i];
				}
				b[b.Length - 1] = 0;
			}
			return search_replace(a, b);
		}

		[DllImport("TR_Hacker.dll")]
		public static extern int BlockAttacking();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_BlockAttacking();

		[DllImport("TR_Hacker.dll")]
		public static extern int getSelectedItem();
		[DllImport("TR_Hacker.dll")]
		public static extern void setSelectedItem(int si);

		[DllImport("TR_Hacker.dll")]
		public static extern int getMaxTilesX();
		[DllImport("TR_Hacker.dll")]
		public static extern int getMaxTilesY();
		[DllImport("TR_Hacker.dll")]
		public static extern int getMain_Map();
		[DllImport("TR_Hacker.dll")]
		public static extern void UpdateLighting(int x, int y, byte light);
		[DllImport("TR_Hacker.dll")]
		public static extern void RefreshMap();


		[DllImport("TR_Hacker.dll")]
		public static extern int search_replace(sbyte[] src, sbyte[] dst);

		[DllImport("TR_Hacker.dll")]
		public static extern int GetNetMode();
		[DllImport("TR_Hacker.dll")]
		public static extern void DropLiquid(int X, int Y, byte header);


		[DllImport("TR_Hacker.dll")]
		public static extern void SendNetWater(int X, int Y);

		[DllImport("TR_Hacker.dll")]
		public static extern void SendNetMessage(int msgType, int remoteClient = -1, int ignoreClient = -1, int number = 0, float number2 = 0, float number3 = 0f, float number4 = 0f, int number5 = 0, int number6 = 0, int number7 = 0);

		[DllImport("TR_Hacker.dll")]
		unsafe public static extern Int16* ReadUUID();
		[DllImport("TR_Hacker.dll")]
		public static extern int RandomUUID();


		[DllImport("TR_Hacker.dll")]
		public static extern bool getPlayerActive(int pid);

		[DllImport("TR_Hacker.dll")]
		public static extern void Player_AddBuff(int pid, int buff, int time);
		[DllImport("TR_Hacker.dll")]
		public static extern void NewNPC(float X, float Y, int Type, int number);

		[DllImport("TR_Hacker.dll")]
		public static extern void NPC_AddBuff(int nid, int buff, int time);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getNPCActive(int nid);


		[DllImport("TR_Hacker.dll")]
		public static extern int EnableAllRecipes();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_EnableAllRecipes();

		[DllImport("TR_Hacker.dll")]
		public static extern int StrengthenVampireKnives();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_StrengthenVampireKnives();



		[DllImport("TR_Hacker.dll")]
		public static extern void SetItemDefaults(int slot, int type, int prefix);

		[DllImport("TR_Hacker.dll")]
		unsafe public static extern byte* getItemMemory(int slot);
		[DllImport("TR_Hacker.dll")]
		unsafe public static extern void setItemMemory(int slot, byte* mem);

		[DllImport("TR_Hacker.dll")]
		public static extern void setItemArrayOffset(int off);



		[DllImport("TR_Hacker.dll")]
		public static extern int getPlayerItemBase(int id);
		[DllImport("TR_Hacker.dll")]
		public static extern void setPlayerItemBase(int id, int ibase);

		[DllImport("TR_Hacker.dll")]
		public static extern int getMyPlayer();
		[DllImport("TR_Hacker.dll")]
		public static extern int setMyPlayer(int index);



		[DllImport("TR_Hacker.dll")]
		public static extern int getDropedItemID(int index);
		[DllImport("TR_Hacker.dll")]
		public static extern void setDropedItemID(int index, int id);
		[DllImport("TR_Hacker.dll")]
		public static extern float getDropedItemX(int index);
		[DllImport("TR_Hacker.dll")]
		public static extern void setDropedItemX(int index, float X);
		[DllImport("TR_Hacker.dll")]
		public static extern float getDropedItemY(int index);
		[DllImport("TR_Hacker.dll")]
		public static extern void setDropedItemY(int index, float Y);
		[DllImport("TR_Hacker.dll")]
		public static extern int getDropedItemCount(int index);
		[DllImport("TR_Hacker.dll")]
		public static extern void setDropedItemCount(int index, int count);



		//Getter Functions


		[DllImport("TR_Hacker.dll")]
		public static extern int getHealth();
		[DllImport("TR_Hacker.dll")]
		public static extern int getMaxHealth();
		[DllImport("TR_Hacker.dll")]
		public static extern int getMana();
		[DllImport("TR_Hacker.dll")]
		public static extern int getMaxMana();

		[DllImport("TR_Hacker.dll")]
		public static extern int getPlayerBase(int pid, int hProcess);

		[DllImport("TR_Hacker.dll")]
		public static extern int getItemType(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemDamage(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern float getItemShootSpeed(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern float getItemKnockBack(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern float getX();
		[DllImport("TR_Hacker.dll")]
		public static extern float getY();
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemCrit(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemShoot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemStack(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemUseTime(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemPick(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemAxe(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemHammer(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemTileBoost(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemUseAnimation(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemAutoReuse(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemBuffType(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemBuffTime(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern byte getItemPrefix(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern float getItemScale(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemDefense(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemHealLife(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemHealMana(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemAccessory(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemCreateTile(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemBait(int slot);


		[DllImport("TR_Hacker.dll")]
		public static extern int getItemCreateWall(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemFishingPole(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemMana(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemMaxStack(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemUseStyle(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemPlaceStyle(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemRare(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemReuseDelay(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemTileWand(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemUseAmmo(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemValue(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemLifeRegen(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemHoldStyle(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemMountType(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemAmmo(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemManaIncrease(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemRelease(int slot);


		[DllImport("TR_Hacker.dll")]
		public static extern short getItemGlowMask(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern short getItemMakeNPC(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern short getItemHairDye(int slot);


		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemHeadSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemBodySlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemLegSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemBalloonSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemFrontSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemWaistSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemWingSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemBackSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemFaceSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemHandOnSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemHandOffSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemNeckSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemDye(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemShieldSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemShoeSlot(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern sbyte getItemPaint(int slot);

		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemCartTrack(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemConsumable(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemNoUseGraphic(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemMagic(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemMech(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemMelee(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemNoMelee(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemRanged(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemMaterial(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemSentry(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemThrown(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemQuestItem(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemInstanced(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemExpertOnly(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemExpert(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemSummon(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemNoWet(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemVanity(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemChannel(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemActive(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemPotion(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemUseTurn(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemBuy(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemUniqueStack(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemFavorited(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern bool getItemFlame(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemAlpha(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemShopSpecialCurrency(int slot);
		[DllImport("TR_Hacker.dll")]
		public static extern int getItemShopCustomPrice(int slot);



		public static void AddBuff(int buffID, int buffTime)
		{
			for (int j = 0; j < 22; j++)//这里的22是TR玩家可以同时拥有的buff最大数量
			{
				if (getBuffType(j) == buffID)
				{
					setBuffTime(j, buffTime + getBuffTime(j));
					return;
				}
			}
			for (int j = 0; j < 22; j++)
			{
				if (getBuffType(j) == 0)
				{
					setBuffTime(j, buffTime);
					setBuffType(j, buffID);
					break;
				}
			}
		}

		public static void RemoveBuff(int buffID)
		{
			for (int j = 0; j < 22; j++)//这里的22是TR玩家可以同时拥有的buff最大数量
			{
				if (getBuffType(j) == buffID)
				{
					setBuffTime(j, 0);
					return;
				}
			}
		}

		//Set Functions

		[DllImport("TR_Hacker.dll")]
		public static extern void setHealth(int hlth);
		[DllImport("TR_Hacker.dll")]
		public static extern void setMaxHealth(int hlth);
		[DllImport("TR_Hacker.dll")]
		public static extern void setMana(int mana);
		[DllImport("TR_Hacker.dll")]
		public static extern void setMaxMana(int mana);

		[DllImport("TR_Hacker.dll")]
		public static extern void setItemType(int slot, int id);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemDamage(int slot, int dmg);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemShootSpeed(int slot, float sht);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemKnockBack(int slot, float knckbck);
		[DllImport("TR_Hacker.dll")]
		public static extern void setX(float X);
		[DllImport("TR_Hacker.dll")]
		public static extern void setY(float Y);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemCrit(int slot, int crt);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemShoot(int slot, int bfid);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemStack(int slot, int count);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemUseTime(int slot, int delay);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemPick(int slot, int pick);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemAxe(int slot, int axe);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemHammer(int slot, int hammer);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemTileBoost(int slot, int dstc);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemUseAnimation(int slot, int speed);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemAutoReuse(int slot, bool isAuto);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemBuffType(int slot, int id);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemBuffTime(int slot, int time);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemPrefix(int slot, byte prefix);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemScale(int slot, float scale);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemDefense(int slot, int defense);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemHealLife(int slot, int v);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemHealMana(int slot, int v);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemAccessory(int slot, bool v);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemCreateTile(int slot, int tileID);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemBait(int slot, int power);

		[DllImport("TR_Hacker.dll")]
		public static extern void setItemCreateWall(int slot, int wall);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemFishingPole(int slot, int pole);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemMana(int slot, int cos);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemMaxStack(int slot, int max);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemUseStyle(int slot, int style);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemPlaceStyle(int slot, int style);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemRare(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemReuseDelay(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemTileWand(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemUseAmmo(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemValue(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemLifeRegen(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemHoldStyle(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemMountType(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemAmmo(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemManaIncrease(int slot, int val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemRelease(int slot, int val);


		[DllImport("TR_Hacker.dll")]
		public static extern void setItemGlowMask(int slot, short val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemMakeNPC(int slot, short val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemHairDye(int slot, short val);


		[DllImport("TR_Hacker.dll")]
		public static extern void setItemHeadSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemBodySlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemLegSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemBalloonSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemFrontSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemWaistSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemWingSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemBackSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemFaceSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemHandOnSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemHandOffSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemNeckSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemDye(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemShieldSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemShoeSlot(int slot, byte val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemPaint(int slot, byte paint);

		[DllImport("TR_Hacker.dll")]
		public static extern void setItemCartTrack(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemConsumable(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemNoUseGraphic(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemMagic(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemMech(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemMelee(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemNoMelee(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemRanged(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemMaterial(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemSentry(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemThrown(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemQuestItem(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemInstanced(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemExpertOnly(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemExpert(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemSummon(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemNoWet(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemVanity(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemChannel(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemActive(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemPotion(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemUseTurn(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemBuy(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemUniqueStack(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemFavorited(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemFlame(int slot, bool val);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemAlpha(int slot, int alpha);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemShopSpecialCurrency(int slot, int sh);
		[DllImport("TR_Hacker.dll")]
		public static extern void setItemShopCustomPrice(int slot, int sh);

		//
		//Get Functions
		[DllImport("TR_Hacker.dll")]
		public static extern int InfiniteHealth();
		[DllImport("TR_Hacker.dll")]
		public static extern int InfiniteMana();
		[DllImport("TR_Hacker.dll")]
		public static extern int InfiniteMinion();
		[DllImport("TR_Hacker.dll")]
		public static extern int InfiniteItems();
		[DllImport("TR_Hacker.dll")]
		public static extern int InfiniteFly();
		[DllImport("TR_Hacker.dll")]
		public static extern int AwfulFishingSkill();
		[DllImport("TR_Hacker.dll")]
		public static extern int GhostMode();
		[DllImport("TR_Hacker.dll")]
		public static extern int IgnoreRange();
		[DllImport("TR_Hacker.dll")]
		public static extern int InfiniteOxygen();
		[DllImport("TR_Hacker.dll")]
		public static extern int InfiniteBullet();
		[DllImport("TR_Hacker.dll")]
		public static extern int NoRespawnTime();
		[DllImport("TR_Hacker.dll")]
		public static extern int AttackThroughWalls();
		[DllImport("TR_Hacker.dll")]
		public static extern int JumpAsFeather();
		[DllImport("TR_Hacker.dll")]
		public static extern int FastSpeed();
		[DllImport("TR_Hacker.dll")]
		public static extern int KillAllNPC();
		[DllImport("TR_Hacker.dll")]
		public static extern int ProjectileIgnoreTiles();
		[DllImport("TR_Hacker.dll")]
		public static extern int GrabItemFarAway();
		[DllImport("TR_Hacker.dll")]
		public static extern int ToggleTime();
		[DllImport("TR_Hacker.dll")]
		public static extern int AddExtraSlots();
		[DllImport("TR_Hacker.dll")]
		public static extern int PumpkinMoon();
		[DllImport("TR_Hacker.dll")]
		public static extern int SnowMoon();
		[DllImport("TR_Hacker.dll")]
		public static extern int BloodMoon();
		[DllImport("TR_Hacker.dll")]
		public static extern int Eclipse();
		[DllImport("TR_Hacker.dll")]
		public static extern int SunDial();
		[DllImport("TR_Hacker.dll")]
		public static extern int GoldHoleDropBag();
		[DllImport("TR_Hacker.dll")]
		public static extern int SlimeGunBurn();
		[DllImport("TR_Hacker.dll")]
		public static extern int FastTileSpeed();
		[DllImport("TR_Hacker.dll")]
		public static extern int RulerEffect();
		[DllImport("TR_Hacker.dll")]
		public static extern int MachinicalRulerEffect();
		[DllImport("TR_Hacker.dll")]
		public static extern int InfernoEffect();
		[DllImport("TR_Hacker.dll")]
		public static extern int ShadowDodge();
		[DllImport("TR_Hacker.dll")]
		public static extern int ShowCircuit();
		[DllImport("TR_Hacker.dll")]
		public static extern int FishOnlyCrates();
		[DllImport("TR_Hacker.dll")]
		public static extern int NoPotionDelay();
		[DllImport("TR_Hacker.dll")]
		public static extern int KillAllScreen();


		[DllImport("TR_Hacker.dll")]
		public static extern int De_InfiniteHealth();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_InfiniteMana();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_InfiniteItems();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_InfiniteMinion();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_InfiniteFly();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_AwfulFishingSkill();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_GhostMode();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_IgnoreRange();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_InfiniteOxygen();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_InfiniteBullet();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_NoRespawnTime();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_AttackThroughWalls();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_JumpAsFeather();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_FastSpeed();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_KillAllNPC();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_ProjectileIgnoreTiles();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_GrabItemFarAway();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_AddExtraSlots();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_GoldHoleDropBag();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_SlimeGunBurn();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_FastTileSpeed();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_RulerEffect();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_MachinicalRulerEffect();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_InfernoEffect();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_ShadowDodge();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_ShowCircuit();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_FishOnlyCrates();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_NoPotionDelay();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_KillAllScreen();

		//
		[DllImport("TR_Hacker.dll")]
		public static extern int HighLight();
		[DllImport("TR_Hacker.dll")]
		public static extern int De_HighLight();

		//
		[DllImport("TR_Hacker.dll", CharSet = CharSet.Unicode)]
		unsafe public static extern char* getPlayerName(int id, int* len);
		[DllImport("TR_Hacker.dll")]
		public static extern int InitEax(int pid);
		[DllImport("TR_Hacker.dll")]
		public static extern float getPlayerX(int id);
		[DllImport("TR_Hacker.dll")]
		public static extern float getPlayerY(int id);
		[DllImport("TR_Hacker.dll")]
		public static extern int getPlayerHealth(int id);
		[DllImport("TR_Hacker.dll")]
		public static extern int getPlayerMaxHealth(int id);

		//
		[DllImport("TR_Hacker.dll")]
		public static extern int getBuffType(int id);
		[DllImport("TR_Hacker.dll")]
		public static extern int getBuffTime(int id);
		[DllImport("TR_Hacker.dll")]
		public static extern void setBuffType(int id, int type);
		[DllImport("TR_Hacker.dll")]
		public static extern void setBuffTime(int id, int time);

		[DllImport("TR_Hacker.dll")]
		public static extern int getPlayerItem(int id, int slot);

		[DllImport("TR_Hacker.dll")]
		public static extern int getPlayerItemNum(int id, int slot);

		[DllImport("TR_Hacker.dll")]
		public static extern int getPlayerBuffType(int pid, int id);

		[DllImport("TR_Hacker.dll")]
		public static extern int getPlayerBuffTime(int pid, int id);

		public static int immuneBuff()
		{
			if (th != null && th.ThreadState == ThreadState.Running)
			{
				De_immuneBuff();
			}
			th = new Thread(() =>
			{
				while (!stop)
					foreach (var i in Debuffs)
						RemoveBuff(i);
			});
			stop = false;
			th.Start();
			return 1;
		}
		public static int De_immuneBuff()
		{
			stop = true;
			Thread.Sleep(100);
			return 1;
		}

		public static void CopyEffectsID(int srcslot, int tgtslot)
		{
			int srcEffectsID = getItemShoot(srcslot);
			Console.WriteLine("Source EffectsID:\t{0}", srcEffectsID);
			int tgtEffectsID = getItemShoot(tgtslot);
			Console.WriteLine("Target EffectsID:\t{0}", tgtEffectsID);
			setItemShoot(tgtslot, srcEffectsID);
		}

		public static void WarpAdd(string name, string Dec)
		{
			if (!warps.Contains(name))
			{
				Position p = new Position();
				p.X = getX();
				p.Y = getY();
				p.Dec = Dec;
				warps.Add(name, p);
				Console.WriteLine("Added " + name);
			}
			else
			{
				Console.WriteLine(name + " was existed");
			}
		}
		public static void WarpDel(string name)
		{
			if (warps.Contains(name))
			{
				warps.Remove(name);
				Console.WriteLine("Deleted " + name);
			}
			else
			{
				Console.WriteLine(name + " not found");
			}
		}
		public static void WarpList()
		{
			int i = 0;
			foreach (DictionaryEntry de in warps)
			{
				Console.WriteLine(i + ".\t" + de.Key + "\t" + ((Position)de.Value).Dec);
				i++;
			}
		}
		public static void WarpRename(string oldName, string newName)
		{
			if (warps.Contains(oldName))
			{
				Position p = (Position)warps[oldName];
				warps.Remove(oldName);
				warps.Add(newName, p);
				Console.WriteLine("Renamed " + oldName + " to " + newName);
			}
			else
			{
				Console.WriteLine(oldName + " not found");
			}
		}
		public static void Warp(string name)
		{
			if (warps.Contains(name))
			{
				Position p = (Position)warps[name];
				setX(p.X);
				setY(p.Y);
				Console.WriteLine("Warped to " + name);
			}
			else
			{
				Console.WriteLine(name + " not found");
			}
		}
		public static void WarpSave()
		{
			File.Delete("WarpList");
			Stream s = File.Open("WarpList", FileMode.OpenOrCreate);
			StreamWriter sw = new StreamWriter(s);
			foreach (DictionaryEntry de in warps)
			{
				Position p = (Position)de.Value;
				sw.WriteLine(de.Key + " " + p.X + " " + p.Y + " " + p.Dec);
			}
			sw.Close();
			s.Close();
			Console.WriteLine("Warplist has been saved");
		}
		public static void WarpLoad()
		{
			warps.Clear();
			Stream s = File.Open("WarpList", FileMode.OpenOrCreate);
			StreamReader sr = new StreamReader(s);
			string[] str = sr.ReadToEnd().Replace("\r", "").Split(new string[] { "\n" }, StringSplitOptions.RemoveEmptyEntries);
			foreach (var tmp in str)
			{
				string[] a = tmp.Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries);
				Position p = new Position();
				p.X = (float)Convert.ToDouble(a[1]);
				p.Y = (float)Convert.ToDouble(a[2]);
				p.Dec = a[3];
				warps.Add(a[0], p);
			}
			s.Close();
			s.Close();
			Console.WriteLine("Warplist has been loaded");
		}
	}
}
