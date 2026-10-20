#include <globaldefs.h>
ARM
struct GameResources;struct MapGameObject;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void GameObject_RequestMovementInputEnable(void*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" GameResources* GameResources_GetInstance();
extern "C" void Resource_PollNestedLoaderIfPresent(GameResources*);
extern "C" void Memory_ReleaseTwoEmbeddedAllocatorsAndClearResourceFlag(void*);
typedef int (*Callback)(unsigned char*);
struct Table {Callback callbacks[9];};
// Original data: arm9/ov017 @ 0x21d6cc4; symbol: data_ov017_021d6cc4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 28f61b02fcf61b02acf71b02a0f91b0240fc1b0260fe1b02e8fe1b0224ff1b0200000000.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Table GameStateDispatchNineStateCallbacksAndFinish_UnknownRoleProcedureReferenceRecords;
// Original: arm9/ov017 @ 0x021BF534; symbol: func_ov017_021bf534; size: 0xA8.
extern "C" void GameState_DispatchNineStateCallbacksAndFinish(unsigned char* p){
 MapGameObject* obj=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
 GameResources* res=GameResources_GetInstance();
 if(res)Resource_PollNestedLoaderIfPresent(res);
 Table table=GameStateDispatchNineStateCallbacksAndFinish_UnknownRoleProcedureReferenceRecords;
 if(table.callbacks[p[10]])p[10]=table.callbacks[p[10]](p);
 else{
 if(obj)GameObject_RequestMovementInputEnable(obj);
 Memory_ReleaseTwoEmbeddedAllocatorsAndClearResourceFlag(p);
 p[1]=1;
 *(int*)(TextContext_GetSharedInstance()+0x2d8)=0;
 }
}
