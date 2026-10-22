#include <globaldefs.h>
#pragma always_inline on
// Original data: arm9/main @ 0x210fd74; symbol: data_0210fd74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210fd7c; symbol: data_0210fd7c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210fdbc; symbol: data_0210fdbc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1460 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage[],NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage_Variant2[];extern "C" char NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage[];
extern "C" void SoundCommand_SubmitOpcodeThirteenAndTrackMask(unsigned,unsigned,unsigned,unsigned),SoundCommand_SubmitOpcodeTwentyFive(unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned ReadSelectedGlobalValueUnderIRQProtection();extern "C" int SoundCommand_FlushPendingBatch(unsigned int flags);extern "C" void SoundCommand_WaitForCompletionTarget(unsigned);
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(void*,void**,int);extern "C" void ResourceManager_ClearGlobalFlagMask(unsigned),Sound_ReleaseHardwareChannels(unsigned),Sound_ReleaseStreamAlarmSlot(int);
inline bool available(int slot){return slot>=0;}
// Original: arm9/main @ 0x020BCF3C; symbol: func_020bcf3c; size: 0xF0.
extern "C" void NNSi_SndCaptureStop(){unsigned *object=NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage_Variant2;if(!NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage[18])return;bool active=available((int)object[11]);unsigned mask=active?(1u<<object[11]):0;SoundCommand_SubmitOpcodeThirteenAndTrackMask(object[9],object[10],mask,0);if(active){unsigned state=ReadSelectedGlobalValueUnderIRQProtection();SoundCommand_FlushPendingBatch(1);SoundCommand_WaitForCompletionTarget(state);while(MessageQueue_ReceiveWithOptionalBlocking(NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage,0,0)){} }if(object[10])ResourceManager_ClearGlobalFlagMask(object[10]);if(object[8])Sound_ReleaseHardwareChannels(object[8]);if(active)Sound_ReleaseStreamAlarmSlot(object[11]);if(object[1]==1)SoundCommand_SubmitOpcodeTwentyFive(0,0,0,0);object[0]=0;}
