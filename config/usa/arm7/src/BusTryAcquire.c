/* Try once to acquire the GBA bus and run the post-acquire hook on success. */
#pragma dont_inline on
typedef struct { volatile unsigned int atomic; unsigned short ownerID,unknown6; } BusLock;
typedef void (*LockCallback)(void);
extern int ARM7_TestSharedBootFlag4(void);
extern void ARM7_AfterAcquireGBABus(void);
extern void ARM7_MarkGBABusAcquired(void);
extern int ARM7_TryLockBus(unsigned short,BusLock*,LockCallback,int);
int ARM7_TryAcquireGBABus(unsigned short owner)
{
 int result=ARM7_TryLockBus(owner,(BusLock*)0x027fffe8,ARM7_MarkGBABusAcquired,1);
 if(!result && !ARM7_TestSharedBootFlag4())ARM7_AfterAcquireGBABus();
 return result;
}
