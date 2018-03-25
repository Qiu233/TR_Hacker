using System;

namespace TR_DDOS
{
	// Token: 0x02000068 RID: 104
	public abstract class RemoteAddress
	{
		// Token: 0x060009C0 RID: 2496
		public abstract string GetFriendlyName();

		// Token: 0x060009BF RID: 2495
		public abstract string GetIdentifier();

		// Token: 0x060009C1 RID: 2497
		public abstract bool IsLocalHost();

		// Token: 0x04000DB6 RID: 3510
		public AddressType Type;
	}
}
