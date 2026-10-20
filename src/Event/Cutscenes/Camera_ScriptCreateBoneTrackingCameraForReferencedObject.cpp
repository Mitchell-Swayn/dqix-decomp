#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
struct GameState;struct GameResources;struct Object3D;extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Zone3D_GetMainInstance();extern "C" void* Network_GetConnectionManager();extern "C" bool Network_IsParentOrOffline(unsigned*);struct IntegerParameterView;extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);extern "C" unsigned Script_ReadParameterString(void*);extern "C" int GameState_GetFieldAddress5CA4(int);extern "C" void* EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;extern "C" unsigned EventGetObjectSession_UnknownRoleZeroInitializedStorage[];extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);extern "C" void* GameState_ReadUnknownB0(GameState*);extern "C" void BoneTrackingCamera_Initialize(unsigned char*);extern "C" void Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(char*,Object3D*);extern "C" void _ZN8Object3D15UntrackAllBonesEv(Object3D*);extern "C" void BoneTrackingCamera_SetEyeBoneName(void*,const char*);extern "C" void BoneTrackingCamera_SetTargetBoneName(int,char*);extern "C" void _ZN8Object3D20StopCurrentAnimationEv(Object3D*);extern "C" void _ZN8Object3D10EnableFlagEi(Object3D*,int);extern "C" void GameState_SetUnknown3b0(GameState*,void*);struct Record{unsigned kind,pad[2];Object3D* object;};
// Original: arm9/ov001 @ 0x02161650; symbol: GameState_CreateNamedScriptObjectForTypeOneEntry; size: 0x104.
extern "C" int Camera_ScriptCreateBoneTrackingCameraForReferencedObject(char* parameter){GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();void* allocator=EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;char* field=(char*)GameState_GetFieldAddress5CA4((int)game);int index=Script_ReadParameterAsInteger((IntegerParameterView*)parameter);const char* resource=(const char*)Script_ReadParameterString(parameter+8);char* name=(char*)Script_ReadParameterString(parameter+16);Record* table=(Record*)EventGetObjectSession_UnknownRoleZeroInitializedStorage[1];Object3D* target=table[index].object;if(!target||table[index].kind!=1)return 0;char* object=(char*)_ZN13SafeAllocator8AllocateEj(allocator,616);if(!object)return 0;P(field,4)=(char*)GameState_ReadUnknownB0(game);BoneTrackingCamera_Initialize((unsigned char*)object);Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(object,target);_ZN8Object3D15UntrackAllBonesEv(target);BoneTrackingCamera_SetEyeBoneName(object,resource);BoneTrackingCamera_SetTargetBoneName((int)object,name);_ZN8Object3D20StopCurrentAnimationEv(target);_ZN8Object3D10EnableFlagEi(target,1);_ZN8Object3D10EnableFlagEi(target,32);GameState_SetUnknown3b0(game,object);return 1;}
