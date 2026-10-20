#include <globaldefs.h>
ARM
#include <System/Interrupts.h>
extern "C" {int ResourceManager_ExchangeGlobalValue(int);int NNS_SndArcGetFileAddress(void*);void NNS_SndArcSetFileAddress(void*,int);
// Original: arm9/main @ 0x020BE3F4; symbol: func_020be3f4; size: 0x58.
void ClearMatchingAssociationUnderIRQProtection(int id,int state,void* p){if(!state)return;int old=0;int irq=DisableIRQInterrupts();old=ResourceManager_ExchangeGlobalValue(state);if(id==NNS_SndArcGetFileAddress(p))NNS_SndArcSetFileAddress(p,0);ResourceManager_ExchangeGlobalValue(old);SetIRQInterruptState(irq);}}
