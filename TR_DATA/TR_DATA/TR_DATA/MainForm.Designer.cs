/*
 * 由SharpDevelop创建。
 * 用户： lopi2
 * 日期: 2017/4/9
 * 时间: 11:40
 * 
 * 要改变这种模板请点击 工具|选项|代码编写|编辑标准头文件
 */
 
using System.Windows.Forms;
namespace TR_DATA
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			// 
			// MainForm
			// 
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.Text = "TR_DATA";
			this.Name = "MainForm";
			this.MaximizeBox=false;
			this.MinimizeBox=false;
			this.FormBorderStyle=FormBorderStyle.FixedSingle;
			this.StartPosition = FormStartPosition.CenterScreen;
		}
	}
}
