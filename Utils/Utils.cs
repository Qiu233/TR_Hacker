using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Terraria_Hacker;

namespace Utils
{
	[PluginInfo("Utils", "1.0")]
	public class Utils : Plugin
	{
		public override void Loaded()
		{
			RegisterTab("Utils");
			RegisterButton("99层帽子", "Utils", Buckit, null, false);
			RegisterButton("隐身并无敌", "Utils", Invisible, null, false);
			RegisterButton("放置物蜂巢", "Utils", PlaceLarva, null, false);
			RegisterButton("可以叠加999", "Utils", MaxStack999, null, false);
		}

		private int MaxStack999()
		{
			HackFunctions.setItemMaxStack(HackFunctions.getSelectedItem(), 999);
			return 1;
		}

		private int PlaceLarva()
		{
			HackFunctions.setItemCreateTile(HackFunctions.getSelectedItem(), 231);
			return 1;
		}

		private int Buckit()
		{
			HackFunctions.setItemArrayOffset(HackFunctions.OFFSET_ARMOR);
			HackFunctions.SetItemDefaults(10, 205, 0);
			HackFunctions.setItemStack(10, 99);
			HackFunctions.setItemArrayOffset(HackFunctions.OFFSET_INV);
			return 1;
		}
		private int Invisible()
		{
			HackFunctions.ShadowDodge();//免伤害，伤害会让隐身buff失效
			HackFunctions.AddBuff(10, 216000);//隐身buff
			return 1;
		}
	}
}
