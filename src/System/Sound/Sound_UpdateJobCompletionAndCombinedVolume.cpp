#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 4
#include <Memory/SignedAllocator.h>
struct SoundOwner {char pad[32];unsigned char volume;};struct SoundJob {char pad[4];SoundOwner* owner;char pad2[56];unsigned char c,b;};
// Original data: arm9/main @ 0x20ed82c; symbol: data_020ed82c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00805bfe97febbfed4fee7fef7fe04ff10ff1aff23ff2cff33ff3aff40ff46ff4cff51ff56ff5bff5fff64ff68ff6cff6fff73ff76ff7aff7dff80ff83ff86ff ...; full span in module reference.
// Observed span: 1792 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210f3d8; symbol: data_0210f3d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" SignedAllocatorList SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage;extern "C" short NNSiSndArcStrmMain_UnknownRoleInitializedBytes[];extern "C" unsigned SoundCommand_ReadInvalidatedSharedStatus();extern "C" bool TestWraparoundTargetCounterUnderIRQGuard(unsigned);extern "C" void Timer_AdvanceInterpolation(void*);extern "C" int Timer_InterpolateIntegerValue(void*);extern "C" int Timer_IsInterpolationComplete(void*);extern "C" void SoundCommand_SubmitOpcodeSixWithModeTwo(unsigned char,int);extern "C" void SoundCommand_SubmitOpcodeThree(unsigned char);extern "C" void ResourceEntry_StopHandleAndRelease(void*);extern "C" void DetachOwnerLinksAndReturnChildToAllocatorList(void*);
// Original: arm9/main @ 0x020BC2F0; symbol: func_020bc2f0; size: 0x164.
extern "C" void Sound_UpdateJobCompletionAndCombinedVolume() {unsigned char* current;unsigned char* next;unsigned mask=SoundCommand_ReadInvalidatedSharedStatus();current=(unsigned char*)SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage.ElementAfter(0);if(!current)return;do {next=(unsigned char*)SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage.ElementAfter((SignedAllocatorHeader*)current);if(!current[0x2d] && TestWraparoundTargetCounterUnderIRQGuard(*(unsigned*)(current+0x30)))current[0x2d]=1;if(current[0x2d] && !(mask&(1u<<current[0x3c]))) {DetachOwnerLinksAndReturnChildToAllocatorList(current);}else {Timer_AdvanceInterpolation(current+0x1c);short b,c,a;SoundJob* job=(SoundJob*)current;unsigned ia=job->owner->volume;unsigned ib=job->b;unsigned ic=job->c;b=NNSiSndArcStrmMain_UnknownRoleInitializedBytes[ib];c=NNSiSndArcStrmMain_UnknownRoleInitializedBytes[ic];a=NNSiSndArcStrmMain_UnknownRoleInitializedBytes[ia];int value=NNSiSndArcStrmMain_UnknownRoleInitializedBytes[Timer_InterpolateIntegerValue(current+0x1c)>>8];value+=(a+(c+b));if(value<-32768)value=-32768;else if(value>32767)value=32767;if(value!=*(short*)(current+0x3e)) {SoundCommand_SubmitOpcodeSixWithModeTwo(current[0x3c],value);*(short*)(current+0x3e)=value;}if(current[0x2c]==2 && Timer_IsInterpolationComplete(current+0x1c))ResourceEntry_StopHandleAndRelease(current);if(current[0x2f]) {SoundCommand_SubmitOpcodeThree(current[0x3c]);current[0x2f]=0;}}current=next;}while(current); }
