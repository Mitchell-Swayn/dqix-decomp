#include <globaldefs.h>
extern "C" void ClearGlobalFlagForId16();
extern "C" void WriteGlobalValueUnderIRQProtection(void(*)());
extern "C" void TouchInput_ResetTrackingState(void*);
extern "C" void IPC_InitializeSampleBufferAndSendCommand(unsigned,unsigned,void*,unsigned);
extern "C" void WaitForGlobalMaskBitsToClear(unsigned);
extern "C" void TestFieldBitsAtOffset38(unsigned);
struct State {char pad[0x30];int a,b;char pad38[8];unsigned value;char pad44[0x1b];unsigned char first,flag,pad61,enabled,second;unsigned newValue;int newA,newB;};
// Original: arm9/main @ 0x02012938; symbol: func_02012938; size: 0x7C.
extern "C" void Input_ConfigureSamplingAndSynchronizePendingValues(State* p) {WriteGlobalValueUnderIRQProtection(ClearGlobalFlagForId16);p->enabled=1;TouchInput_ResetTrackingState(p);IPC_InitializeSampleBufferAndSendCommand(0,1,p,4);WaitForGlobalMaskBitsToClear(2);TestFieldBitsAtOffset38(2);p->flag=0;p->first=p->second;p->value=p->newValue;if(p->newA>=0)p->a=p->newA;if(p->newB>=0)p->b=p->newB;}
