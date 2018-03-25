using System;

namespace TR_DDOS
{
	// Token: 0x02000073 RID: 115
	public interface ISocket
	{
		// Token: 0x060009F5 RID: 2549
		void Close();

		// Token: 0x060009F6 RID: 2550
		bool IsConnected();

		// Token: 0x060009F7 RID: 2551
		void Connect(RemoteAddress address);

		// Token: 0x060009F8 RID: 2552
		void AsyncSend(byte[] data, int offset, int size, SocketSendCallback callback, object state = null);

		// Token: 0x060009F9 RID: 2553
		void AsyncReceive(byte[] data, int offset, int size, SocketReceiveCallback callback, object state = null);

		// Token: 0x060009FA RID: 2554
		bool IsDataAvailable();

		// Token: 0x060009FB RID: 2555
		void SendQueuedPackets();

		// Token: 0x060009FC RID: 2556
		bool StartListening(SocketConnectionAccepted callback);

		// Token: 0x060009FD RID: 2557
		void StopListening();

		// Token: 0x060009FE RID: 2558
		RemoteAddress GetRemoteAddress();
	}
}
