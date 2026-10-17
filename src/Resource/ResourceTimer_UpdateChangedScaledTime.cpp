#include <globaldefs.h>
struct Service {char pad[0x48];unsigned initialized;};
struct TimerJob {unsigned unused,active;char pad8[0x1c];void* handle;char pad28[0x14];unsigned timer[4];int flag,last;};
extern "C" Service data_0210fd74;
extern "C" TimerJob data_0210fdbc;
extern "C" void IncrementIndexWithinLimit(void*);
extern "C" int IsWordElementTwoAtLeastElementThree(void*);
extern "C" int Timer_InterpolateIntegerValue(void*);
extern "C" void SubmitConditionalChannelMaskAndWait();
extern "C" void SoundCommand_SubmitOpcodeTwenty(void*,int,unsigned);
// Original: arm9/main @ 0x020BCEB4; symbol: func_020bceb4; size: 0x88.
extern "C" void ResourceTimer_UpdateChangedScaledTime() {TimerJob* p=&data_0210fdbc;if(!data_0210fd74.initialized)return;if(p->active)return;IncrementIndexWithinLimit(p->timer);if(p->flag&&IsWordElementTwoAtLeastElementThree(p->timer)){SubmitConditionalChannelMaskAndWait();return;}int time=Timer_InterpolateIntegerValue(p->timer)>>8;if(time==p->last)return;SoundCommand_SubmitOpcodeTwenty(p->handle,time,0);p->last=time;}
