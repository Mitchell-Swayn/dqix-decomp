#include <globaldefs.h>
struct State { unsigned short a,flag; }; struct Control { char pad[16]; int state; }; extern "C" Control data_021015a0; extern "C" void SetGlobalValueExceptModesNineAndTen(unsigned); extern "C" int PollCallbackStateAndMarkReady(unsigned);
// Original: arm9/main @ 0x0202C918; symbol: func_0202c918; size: 0x40.
extern "C" void ProcessFlagAndSetGlobalFailureState(State* self) { unsigned flag=self->flag; if(flag) { SetGlobalValueExceptModesNineAndTen(flag); data_021015a0.state=9; } else { if(!PollCallbackStateAndMarkReady(flag))data_021015a0.state=9; } }
