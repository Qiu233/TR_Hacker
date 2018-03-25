/*
 * Created by SharpDevelop.
 * User: jianqiu
 * Date: 2016/8/3
 * Time: 16:20
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;

namespace RegisterInfo
{
	class Program
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("Name:\n"+new HardwareInfo().GetHostName().ToUpper());
			Console.WriteLine("CPUID:\n"+new HardwareInfo().GetCpuID());
			Console.ReadKey(true);
		}
	}
}