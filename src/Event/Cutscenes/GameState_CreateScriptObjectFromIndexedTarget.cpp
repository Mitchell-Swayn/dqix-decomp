#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetFieldAddress5CA4();
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" int Script_ResolveEventObjectIndex(int);
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" void BoneTrackingCamera_Initialize(unsigned char*);
extern "C" void Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(char*,void*);
extern "C" void BoneTrackingCamera_SetEyeBoneName(void*,const char*);
extern "C" void BoneTrackingCamera_SetTargetBoneName(int,char*);
extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);
extern "C" void GameState_SetUnknown3b0(void*,void*);
extern "C" unsigned Script_ReadParameterString(void*);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x0215F854; symbol: GameState_CreateScriptObjectFromIndexedTarget; size: 0xDC.
// Builds a 0x268-byte object for the selected script index, attaches its source object and names, enables two flags, and stores it in GameState.
extern "C" int GameState_CreateScriptObjectFromIndexedTarget(void* parameter) {
    void* game=_ZN9GameState11GetInstanceEv();
    char* allocator=*(char**)(&EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage);
    char* stateField=(char*)GameState_GetFieldAddress5CA4();
    int scriptIndex=Script_ReadParameterAsInteger(parameter);
    unsigned resourceName=Script_ReadParameterString((char*)parameter+8);
    unsigned objectName=Script_ReadParameterString((char*)parameter+0x10);
    int objectIndex=Script_ResolveEventObjectIndex(scriptIndex);
    void* sourceObject=_ZN9GameState20GetGameObjectByIndexEi(game,objectIndex);
    if(!sourceObject)return 0;
    char* object=_ZN13SafeAllocator8AllocateEj((unsigned)allocator,0x268);
    *(void**)(stateField+4)=GameState_ReadUnknownB0(game);
    BoneTrackingCamera_Initialize((unsigned char*)object);
    Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(object,sourceObject);
    BoneTrackingCamera_SetEyeBoneName(object,(const char*)resourceName);
    BoneTrackingCamera_SetTargetBoneName((int)object,(char*)objectName);
    _ZN8Object3D10EnableFlagEi(sourceObject,1);
    _ZN8Object3D10EnableFlagEi(sourceObject,0x20);
    GameState_SetUnknown3b0(game,object);
    return 1;
}
