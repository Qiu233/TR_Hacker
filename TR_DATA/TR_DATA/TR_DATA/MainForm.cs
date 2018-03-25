/*
 * 由SharpDevelop创建。
 * 用户： lopi2
 * 日期: 2017/4/9
 * 时间: 11:40
 * 
 * 要改变这种模板请点击 工具|选项|代码编写|编辑标准头文件
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Resources;

namespace TR_DATA
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		public ResourceManager res;
		public ListView items;
		public string[] itemID;
		public string[] projID;
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			res=new ResourceManager("TR_DATA.Resource1",this.GetType().Assembly);
			itemID=System.Text.Encoding.UTF8.GetString((byte[])res.GetObject("itemID")).Split(new string[]{"\n"},StringSplitOptions.RemoveEmptyEntries);
			projID=System.Text.Encoding.UTF8.GetString((byte[])res.GetObject("projID")).Split(new string[]{"\n"},StringSplitOptions.RemoveEmptyEntries);
			InitializeComponent();
			this.Width=350;
			this.Height=400;
			items=new ListView();
			items.Location=new Point(0,0);
			items.Size=new Size(340,360);
			items.View=View.Details;
			items.MultiSelect=false;
			items.FullRowSelect=true;
			items.BeginUpdate();
			items.Columns.Add("ID",items.Size.Width/7);
			items.Columns.Add("Name",items.Size.Width/7*4);
			items.Columns.Add("ProjID",items.Size.Width/7*2);
			this.Controls.Add(items);
			for(int i=0;i<itemID.Length;i++)
			{
				string ID=i.ToString();
				items.Items.Add(ID,ID,0);
				items.Items[ID].SubItems.Add(itemID[i].Split(new string[]{"="},StringSplitOptions.RemoveEmptyEntries)[1]);
				items.Items[ID].SubItems.Add(projID[i].Split(new string[]{"="},StringSplitOptions.RemoveEmptyEntries)[1]);
			}
			items.MultiSelect=false;
			items.EndUpdate();
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
	}
}
