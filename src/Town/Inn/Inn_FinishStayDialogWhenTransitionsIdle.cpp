#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char Main_UnknownRoleZeroInitializedStorage_Variant2[];extern unsigned char Main_UnknownRoleZeroInitializedStorage[];int Bgm_IsTemporarySequencePendingOrPlaying(char*);void SoundSfx_SetScaledPlayerVolumes(unsigned char*,int);void NetworkOwnership_GetRegistry();void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(void*);void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void Inn_ReleaseStayDialogResources(void*);}
// Original: arm9/ov003 @ 0x0215E3FC; symbol: RemoveThreeBackgroundTasksAndSetStateFive; size: 0x9c.
// Clears three background tasks and advances state5 when identifier override is inactive.
extern "C" void Inn_FinishStayDialogWhenTransitionsIdle(unsigned char* self){if(Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2)||self[0x3ec])return;SoundSfx_SetScaledPlayerVolumes(Main_UnknownRoleZeroInitializedStorage,127);NetworkOwnership_GetRegistry();if(*(void**)(self+0x3b4)){void* loader=_ZN16BackgroundLoader11GetInstanceEv();_ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(loader);for(int i=0;i<3;++i){_ZN16BackgroundLoader10RemoveTaskEi(loader,(*(int**)(self+0x3b4))[i]);(*(int**)(self+0x3b4))[i]=-1;}}Inn_ReleaseStayDialogResources(self);self[0x3bc]=5;self[0x3b8]=0;}
