#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
struct Resources {char padding[0x3718];unsigned char* volatile flags;};
extern "C" Resources* GameResources_GetInstance();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" unsigned char* GameState_GetFieldOrbitCamera(void*);
extern "C" void Graphics_ResetSharedSceneState();
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" void Camera_EnableTargetFollowing(void*);
extern "C" void ResetInterpolationAndDispatchStoredHalfwordValue(unsigned char*);
extern "C" void Bgm_SetPlaybackVolumeAndFade(unsigned char*,unsigned,int);
extern "C" void Resource_CompletePendingStateAndClearFlags(void*);
extern "C" void FieldEvent_ReleaseResourcesAndResumeFieldControl(void*);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov001 @ 0x021567C4; symbol: InitializeSceneBrightnessAndTransition; size: 0x94.
// Resets shared scene, sets brightness and interpolation, completes pending resource transition and marks entry ready.
extern "C" unsigned Event_InitializeSceneBrightnessAndTransition(unsigned char* p){
 void* state=_ZN9GameState11GetInstanceEv();Resources* resources=GameResources_GetInstance();
 _ZN9GameState20GetUnknownGameObjectEv(state);unsigned char* object=GameState_GetFieldOrbitCamera(state);
 unsigned char* flags=resources->flags; flags[1]=1;Graphics_ResetSharedSceneState();
 _Z13SetBrightnessP13GameResourcesii(resources,0,30);Camera_EnableTargetFollowing(object);ResetInterpolationAndDispatchStoredHalfwordValue(object);
 Bgm_SetPlaybackVolumeAndFade(Main_UnknownRoleZeroInitializedStorage_Variant2,*(unsigned*)(p+0x94),0);
 Resource_CompletePendingStateAndClearFlags(p);FieldEvent_ReleaseResourcesAndResumeFieldControl(p);p[1]=1;return *(unsigned short*)(p+10);
}
