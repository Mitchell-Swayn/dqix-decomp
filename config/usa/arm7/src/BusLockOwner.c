/* Read the owner field of a shared bus lock. */
#pragma dont_inline on
typedef struct { volatile unsigned int atomic; unsigned short ownerID,unknown6; } BusLock;
// Original: arm7/wram @ 0x037FBC80; symbol: ARM7_GetBusLockOwner.
unsigned short ARM7_GetBusLockOwner(BusLock *lock){return lock->ownerID;}
