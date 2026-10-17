#include <globaldefs.h>
#include <System/GamecardBusOwnership.h>
#include <System/Interrupts.h>
unsigned GetLockOwner(GamecardBusLock*);
extern "C" void WaitByLoop(unsigned);
// Original: arm9/main @ 0x020D14E4; symbol: func_020d14e4; size: 0x5C.
extern "C" void AcquireGBABusOrDetectOtherOwner(unsigned short owner,unsigned* output) {GamecardBusLock* lock=(GamecardBusLock*)0x027fffe8;for(;;){output[1]=DisableIRQInterrupts();*output=GetLockOwner(lock)&0x40;if(*output)return;if(!TryAcquireGBABus(owner))return;SetIRQInterruptState(output[1]);WaitByLoop(1);}}
