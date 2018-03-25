/*
 * 由SharpDevelop创建。
 * 用户： lopi2
 * 日期: 2017/6/28
 * 时间: 8:42
 * 
 * 要改变这种模板请点击 工具|选项|代码编写|编辑标准头文件
 */
using System;
using System.IO;

namespace Image_Packer
{
	class Program
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("输入文件类型：");
			string type = Console.ReadLine();
			string[] files = Directory.GetFiles("./");
			FileStream target = File.Open("./ItemImage.bin", FileMode.OpenOrCreate);
			BinaryWriter bw = new BinaryWriter(target);
			int number = 0;
			foreach (var f in files)
			{
				if (f.EndsWith(type))
				{
					FileStream file = File.Open(f, FileMode.Open);
					BinaryReader br = new BinaryReader(file);
					byte[] val = new byte[file.Length];
					br.Read(val, 0, val.Length);
					bw.Write(Path.GetFileNameWithoutExtension(file.Name));
					bw.Write(file.Length);
					bw.Write(val);
					br.Close();
					file.Close();
					number++;
				}
			}
			bw.Close();
			target.Close();
			Console.WriteLine("Packed:" + number + " files");
			Console.ReadKey(true);
		}
	}
}