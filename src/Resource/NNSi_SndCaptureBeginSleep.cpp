#include <globaldefs.h>
// Original data: arm9/main @ 0x210fd74; symbol: data_0210fd74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210fdbc; symbol: data_0210fdbc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1460 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage[],NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage_Variant2[];extern "C" void SoundCommand_SubmitOpcodeThirteenAndTrackMask(int,int,unsigned,int);extern "C" int SoundCommand_FlushPendingBatch(unsigned int flags);extern "C" void SoundCommand_WaitForCompletionTarget(int);extern "C" int ReadSelectedGlobalValueUnderIRQProtection();struct State{char pad[0x24];int first,second,index;};
// Original: arm9/main @ 0x020BD02C; symbol: func_020bd02c; size: 0x60.
extern "C" ARM void NNSi_SndCaptureBeginSleep(){State* p=(State*)NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage_Variant2;if(!*(int*)(NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage+0x48))return;unsigned mask=p->index>=0?1u<<p->index:0;SoundCommand_SubmitOpcodeThirteenAndTrackMask(p->first,p->second,mask,0);int old=ReadSelectedGlobalValueUnderIRQProtection();SoundCommand_FlushPendingBatch(1);SoundCommand_WaitForCompletionTarget(old);}
