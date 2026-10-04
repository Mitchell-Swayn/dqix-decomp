/* Shared cartridge bus locks use an atomic claim followed by a 16-bit owner ID.
 * Strict callers mask IRQ and FIQ; other callers mask IRQ only.
 * Callback ordering and the error/previous-claim return values are preserved. */
#pragma dont_inline on
typedef struct { volatile unsigned int atomic; unsigned short ownerID,unknown6; } BusLock;
typedef void (*LockCallback)(void);
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern int ARM7_DisableIRQAndFIQInterrupts(void);
extern int ARM7_SetIRQAndFIQInterruptState(int);
extern unsigned int ARM7_AtomicSwap(unsigned int,volatile unsigned int*);
extern void ARM7_BusLockWait(int);
extern int ARM7_TestSharedBootFlag4(void);
extern void ARM7_BeforeReleaseGBABus(void);
extern void ARM7_AfterAcquireGBABus(void);
extern void ARM7_MarkGBABusAcquired(void);
extern void ARM7_MarkGBABusReleased(void);
int ARM7_UnlockBus(unsigned short owner,BusLock *lock,LockCallback callback,int strict)
{
 int state;
 if(owner!=lock->ownerID)return -2;
 if(strict)state=ARM7_DisableIRQAndFIQInterrupts();
 else state=ARM7_DisableIRQInterrupts();
 lock->ownerID=0;
 if(callback)callback();
 lock->atomic=0;
 if(strict)ARM7_SetIRQAndFIQInterruptState(state);
 else ARM7_SetIRQInterruptState(state);
 return 0;
}
int ARM7_TryLockBus(unsigned short owner,BusLock *lock,LockCallback callback,int strict)
{
 int state;
 int old;
 if(strict)state=ARM7_DisableIRQAndFIQInterrupts();
 else state=ARM7_DisableIRQInterrupts();
 old=ARM7_AtomicSwap(owner,&lock->atomic);
 if(!old){if(callback)callback();lock->ownerID=owner;}
 if(strict)ARM7_SetIRQAndFIQInterruptState(state);
 else ARM7_SetIRQInterruptState(state);
 return old;
}
int ARM7_AcquireGBABus(unsigned short owner)
{
 int result;
 while((result=ARM7_TryLockBus(owner,(BusLock*)0x027fffe8,ARM7_MarkGBABusAcquired,1))>0)ARM7_BusLockWait(0x400);
 if(!ARM7_TestSharedBootFlag4())ARM7_AfterAcquireGBABus();
 return result;
}
int ARM7_InternalReleaseGBABus(unsigned short owner)
{
 if(!ARM7_TestSharedBootFlag4())ARM7_BeforeReleaseGBABus();
 return ARM7_UnlockBus(owner,(BusLock*)0x027fffe8,ARM7_MarkGBABusReleased,1);
}
