#include <globaldefs.h>
struct Service {char pad[0x48];unsigned initialized;};
struct TimerJob {unsigned unused,active;char pad8[0x1c];void* handle;char pad28[0x14];unsigned timer[4];int flag,last;};
// Original data: arm9/main @ 0x210fd74; symbol: data_0210fd74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Service NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x210fdbc; symbol: data_0210fdbc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1460 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" TimerJob NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" void Timer_AdvanceInterpolation(void*);
extern "C" int Timer_IsInterpolationComplete(void*);
extern "C" int Timer_InterpolateIntegerValue(void*);
extern "C" void NNSi_SndCaptureStop();
extern "C" void SoundCommand_SubmitOpcodeTwenty(void*,int,unsigned);
// Original: arm9/main @ 0x020BCEB4; symbol: func_020bceb4; size: 0x88.
extern "C" void ResourceTimer_UpdateChangedScaledTime() {TimerJob* p=&NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage_Variant2;if(!NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage.initialized)return;if(p->active)return;Timer_AdvanceInterpolation(p->timer);if(p->flag&&Timer_IsInterpolationComplete(p->timer)){NNSi_SndCaptureStop();return;}int time=Timer_InterpolateIntegerValue(p->timer)>>8;if(time==p->last)return;SoundCommand_SubmitOpcodeTwenty(p->handle,time,0);p->last=time;}
