#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" void GameState_SetUnknown3b0(void*,void*);
extern "C" int GameState_GetFieldAddress5CA4(int);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);
extern "C" void BoneTrackingCamera_Initialize(unsigned char*);
extern "C" void Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(char*,Object3D*);
extern "C" void BoneTrackingCamera_SetEyeBoneName(void*,const char*);
extern "C" void BoneTrackingCamera_SetTargetBoneName(int,char*);
extern "C" void BoneTrackingCamera_SetAttachmentBoneName(int,const char*);
extern "C" void Object3D_SetLinkedTarget(int,unsigned);
extern "C" int Script_ResolveEventObjectIndex(int);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" unsigned Script_ReadParameterString(void*);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x02160768; symbol: func_ov001_02160768; size: 0x134.
extern "C" int Script_CreateLinkedBoneTrackingObject(unsigned char* args) {
 void* game=_ZN9GameState11GetInstanceEv();
 unsigned allocator=EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
 unsigned char* field=(unsigned char*)GameState_GetFieldAddress5CA4((int)game);
 int first=Script_ReadParameterAsInteger((IntegerParameterView*)args);
 unsigned resource=Script_ReadParameterString(args+8);
 unsigned name=Script_ReadParameterString(args+16);
 unsigned extra=Script_ReadParameterString(args+24);
 int second=Script_ReadParameterAsInteger((IntegerParameterView*)(args+32));
 first=Script_ResolveEventObjectIndex(first);
 second=Script_ResolveEventObjectIndex(second);
 void* source=_ZN9GameState20GetGameObjectByIndexEi(game,first);
 if(!source)return 0;
 void* target=_ZN9GameState20GetGameObjectByIndexEi(game,second);
 if(!target)return 0;
 char* object=_ZN13SafeAllocator8AllocateEj(allocator,0x268);
 *(void**)(field+4)=GameState_ReadUnknownB0(game);
 BoneTrackingCamera_Initialize((unsigned char*)object);
 Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(object,(Object3D*)source);
 BoneTrackingCamera_SetEyeBoneName(object,(const char*)resource);
 BoneTrackingCamera_SetTargetBoneName((int)object,(char*)name);
 BoneTrackingCamera_SetAttachmentBoneName((int)object,(const char*)extra);
 Object3D_SetLinkedTarget((int)object,(unsigned)target);
 _ZN8Object3D10EnableFlagEi(source,1);
 _ZN8Object3D10EnableFlagEi(source,0x20);
 GameState_SetUnknown3b0(game,object);
 return 1;
}
