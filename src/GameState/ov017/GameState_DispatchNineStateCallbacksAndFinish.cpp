#include <globaldefs.h>
ARM
struct GameResources;struct MapGameObject;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void SetByteFieldAtOffset253ToOne(void*);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" GameResources* GameResources_GetInstance();
extern "C" void Resource_PollNestedLoaderIfPresent(GameResources*);
extern "C" void Memory_ReleaseTwoEmbeddedAllocatorsAndClearResourceFlag(void*);
typedef int (*Callback)(unsigned char*);
struct Table {Callback callbacks[9];};
extern "C" Table data_ov017_021d6cc4;
// Original: arm9/ov017 @ 0x021BF534; symbol: func_ov017_021bf534; size: 0xA8.
extern "C" void GameState_DispatchNineStateCallbacksAndFinish(unsigned char* p){
 MapGameObject* obj=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
 GameResources* res=GameResources_GetInstance();
 if(res)Resource_PollNestedLoaderIfPresent(res);
 Table table=data_ov017_021d6cc4;
 if(table.callbacks[p[10]])p[10]=table.callbacks[p[10]](p);
 else{
 if(obj)SetByteFieldAtOffset253ToOne(obj);
 Memory_ReleaseTwoEmbeddedAllocatorsAndClearResourceFlag(p);
 p[1]=1;
 *(int*)(ReadWordFieldAtOffset1C()+0x2d8)=0;
 }
}
