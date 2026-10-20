#include <globaldefs.h>
extern "C" void TouchInput_ClearResumePendingOnSample();
extern "C" void TP_SetCallback(void(*)());
extern "C" void TouchInput_ResetTrackingState(void*);
extern "C" void IPC_InitializeSampleBufferAndSendCommand(unsigned,unsigned,void*,unsigned);
extern "C" void TP_WaitBusy(unsigned);
extern "C" void TP_CheckError(unsigned);
struct State {char pad[0x30];int a,b;char pad38[8];unsigned value;char pad44[0x1b];unsigned char first,flag,pad61,enabled,second;unsigned newValue;int newA,newB;};
// Original: arm9/main @ 0x02012938; symbol: func_02012938; size: 0x7C.
extern "C" void Input_ConfigureSamplingAndSynchronizePendingValues(State* p) {TP_SetCallback(TouchInput_ClearResumePendingOnSample);p->enabled=1;TouchInput_ResetTrackingState(p);IPC_InitializeSampleBufferAndSendCommand(0,1,p,4);TP_WaitBusy(2);TP_CheckError(2);p->flag=0;p->first=p->second;p->value=p->newValue;if(p->newA>=0)p->a=p->newA;if(p->newB>=0)p->b=p->newB;}
