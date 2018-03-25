using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace TR_DDOS
{
	// Token: 0x02000075 RID: 117
	public class TcpSocket : ISocket
	{
		// Token: 0x06000A0D RID: 2573 RVA: 0x003B70FE File Offset: 0x003B52FE
		public TcpSocket()
		{
			this._connection = new TcpClient();
			this._connection.NoDelay = true;
		}

		// Token: 0x06000A0E RID: 2574 RVA: 0x003B7138 File Offset: 0x003B5338
		public TcpSocket(TcpClient tcpClient)
		{
			this._connection = tcpClient;
			this._connection.NoDelay = true;
			IPEndPoint iPEndPoint = (IPEndPoint)tcpClient.Client.RemoteEndPoint;
			this._remoteAddress = new TcpAddress(iPEndPoint.Address, iPEndPoint.Port);
		}
		

		// Token: 0x06000A12 RID: 2578 RVA: 0x003B7210 File Offset: 0x003B5410
		private void ReadCallback(IAsyncResult result)
		{
			Tuple<SocketReceiveCallback, object> tuple = (Tuple<SocketReceiveCallback, object>)result.AsyncState;
			tuple.Item1(tuple.Item2, this._connection.GetStream().EndRead(result));
		}

		// Token: 0x06000A13 RID: 2579 RVA: 0x003B724C File Offset: 0x003B544C
		private void SendCallback(IAsyncResult result)
		{
			Tuple<SocketSendCallback, object> tuple = (Tuple<SocketSendCallback, object>)result.AsyncState;
			try
			{
				this._connection.GetStream().EndWrite(result);
				tuple.Item1(tuple.Item2);
			}
			catch (Exception)
			{
				((ISocket)this).Close();
			}
		}

		// Token: 0x06000A16 RID: 2582 RVA: 0x003B72CF File Offset: 0x003B54CF
		void ISocket.AsyncReceive(byte[] data, int offset, int size, SocketReceiveCallback callback, object state)
		{
			this._connection.GetStream().BeginRead(data, offset, size, new AsyncCallback(this.ReadCallback), new Tuple<SocketReceiveCallback, object>(callback, state));
		}

		// Token: 0x06000A15 RID: 2581 RVA: 0x003B72A4 File Offset: 0x003B54A4
		void ISocket.AsyncSend(byte[] data, int offset, int size, SocketSendCallback callback, object state)
		{
			this._connection.GetStream().BeginWrite(data, 0, size, new AsyncCallback(this.SendCallback), new Tuple<SocketSendCallback, object>(callback, state));
		}

		// Token: 0x06000A0F RID: 2575 RVA: 0x003B71A1 File Offset: 0x003B53A1
		void ISocket.Close()
		{
			this._remoteAddress = null;
			this._connection.Close();
		}

		// Token: 0x06000A11 RID: 2577 RVA: 0x003B71DC File Offset: 0x003B53DC
		void ISocket.Connect(RemoteAddress address)
		{
			TcpAddress tcpAddress = (TcpAddress)address;
			this._connection.Connect(tcpAddress.Address, tcpAddress.Port);
			this._remoteAddress = address;
		}

		// Token: 0x06000A18 RID: 2584 RVA: 0x003B730C File Offset: 0x003B550C
		RemoteAddress ISocket.GetRemoteAddress()
		{
			return this._remoteAddress;
		}

		// Token: 0x06000A10 RID: 2576 RVA: 0x003B71B5 File Offset: 0x003B53B5
		bool ISocket.IsConnected()
		{
			return this._connection != null && this._connection.Client != null && this._connection.Connected;
		}

		// Token: 0x06000A17 RID: 2583 RVA: 0x003B72FA File Offset: 0x003B54FA
		bool ISocket.IsDataAvailable()
		{
			return this._connection.GetStream().DataAvailable;
		}

		// Token: 0x06000A14 RID: 2580 RVA: 0x00029F71 File Offset: 0x00028171
		void ISocket.SendQueuedPackets()
		{
		}
		

		// Token: 0x06000A1A RID: 2586 RVA: 0x003B73AC File Offset: 0x003B55AC
		void ISocket.StopListening()
		{
			this._isListening = false;
		}

		public bool StartListening(SocketConnectionAccepted callback)
		{
			throw new NotImplementedException();
		}

		// Token: 0x170000F0 RID: 240
		public int MessagesInQueue
		{
			// Token: 0x06000A0C RID: 2572 RVA: 0x003B70F6 File Offset: 0x003B52F6
			get
			{
				return this._messagesInQueue;
			}
		}

		// Token: 0x04000DD5 RID: 3541
		private List<object> _callbackBuffer = new List<object>();

		// Token: 0x04000DD7 RID: 3543
		private TcpClient _connection;

		// Token: 0x04000DDB RID: 3547
		private bool _isListening;

		// Token: 0x04000DD8 RID: 3544
		private TcpListener _listener;

		// Token: 0x04000DD9 RID: 3545
		private SocketConnectionAccepted _listenerCallback;

		// Token: 0x04000DD6 RID: 3542
		private int _messagesInQueue;

		// Token: 0x04000DD3 RID: 3539
		private byte[] _packetBuffer = new byte[1024];

		// Token: 0x04000DD4 RID: 3540
		private int _packetBufferLength;

		// Token: 0x04000DDA RID: 3546
		private RemoteAddress _remoteAddress;
	}
}
