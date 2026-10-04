/* NDS bus lock wrappers use the shared record at 0x027fffe0 and mask IRQ only. */
#pragma dont_inline on
typedef struct { volatile unsigned int atomic; unsigned short ownerID,unknown6; } BusLock;
typedef void (*LockCallback)(void);
extern int ARM7_UnlockBus(unsigned short,BusLock*,LockCallback,int);
extern int ARM7_TryLockBus(unsigned short,BusLock*,LockCallback,int);
extern void ARM7_MarkNDSBusAcquired(void);
extern void ARM7_MarkNDSBusReleased(void);
int ARM7_ReleaseNDSBus(unsigned short owner)
{
 return ARM7_UnlockBus(owner,(BusLock*)0x027fffe0,ARM7_MarkNDSBusReleased,0);
}
int ARM7_TryAcquireNDSBus(unsigned short owner)
{
 return ARM7_TryLockBus(owner,(BusLock*)0x027fffe0,ARM7_MarkNDSBusAcquired,0);
}
