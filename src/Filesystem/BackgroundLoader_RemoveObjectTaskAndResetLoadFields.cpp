#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <std_library_functions.h>
struct Bits2{unsigned char flags:2,rest:6;};
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {int GameObject_GetCurrentQueuedActionOrInvalid(Object3D*);void Resource_StopOrFadeSequence(void*,void*,int);extern char Main_UnknownRoleZeroInitializedStorage[],KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];int GameObject_GetLadderTraversalActive(Object3D*);void GameObject_SetMotionStateAndRefreshAnimation(Object3D*);int GameState_ReadFirstObjectIndex(GameState*);void*GameState_GetFieldOrbitCamera(GameState*);int Input_TestKeyMask(void*,int);unsigned char*TextContext_GetSharedInstance();void Camera_EndLoadingFocusBlend(void*);void QueueFirstObjectBytePayload(int,void*,int,int);}
// Original: arm9/main @ 0x020531F0; symbol: func_020531f0; size: 0x18C.
extern "C" ARM void BackgroundLoader_RemoveObjectTaskAndResetLoadFields(Object3D*object){unsigned char*p=(unsigned char*)object;BackgroundLoader*loader=BackgroundLoader::GetInstance();if(*(int*)(p+0x180)>-1){loader->RemoveTask(*(int*)(p+0x180));*(int*)(p+0x180)=-1;}if(GameObject_GetCurrentQueuedActionOrInvalid(object)==25)Resource_StopOrFadeSequence(Main_UnknownRoleZeroInitializedStorage,p+0x198,0);memset(p+0x178,0,4);p[0x17c]=0;p[0x17d]=0;*(int*)(p+0x180)=-1;p[0x17e]=0;p[0x17f]=0;p[0x184]=0;if(*(int*)(p+0x194)>-1){loader->RemoveTask(*(int*)(p+0x194));*(int*)(p+0x194)=-1;}*(unsigned*)(p+0x190)=0;*(int*)(p+0x194)=-1;p[0x185]=0;p[0x186]=0;if(!(*(unsigned short*)p&0x200)||!GameObject_GetLadderTraversalActive(object)){((Bits2*)(p+0xc1))->flags&=~2;object->RemoveAnimationPackageByID(2);*(short*)(p+0xb2)=0;GameObject_SetMotionStateAndRefreshAnimation(object);GameState*state=GameState::GetInstance();int id=*(short*)(p+4);int current=GameState_ReadFirstObjectIndex(state);if(current==id){void*member=GameState_GetFieldOrbitCamera(state);if(member){if(!Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)||TextContext_GetSharedInstance()[0x19b1])Camera_EndLoadingFocusBlend(member);}}unsigned local;QueueFirstObjectBytePayload(*(short*)(p+4),&local,0,1);}}
