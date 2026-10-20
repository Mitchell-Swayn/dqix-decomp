#include <globaldefs.h>
ARM
extern "C" {
void* GameResources_GetInstance();
void* Text_GetSharedResourceScratchBuffer();
void* memset(void*,int,unsigned);
void _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int,const void*,unsigned,unsigned,bool,bool);
void* SystemState_GetGlobalFlags();
bool SystemState_TestAnyFlags(const unsigned*,unsigned);
void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
void* _ZN9GameState11GetInstanceEv();
void* _ZN9GameState20GetUnknownGameObjectEv(void*);
void GameObject_RequestMovementInputEnable(void*);
}
struct Flag { unsigned a:3; unsigned reset:1; unsigned rest:28; };
// Original: arm9/ov017 @ 0x021B2968; symbol: func_ov017_021b2968; size: 0x170.
extern "C" int Graphics_ClearBackgroundsAndFinishTransition(char* self) {
 void* resources=GameResources_GetInstance();
 if(((Flag*)(self+0x38))->reset) {
  void* data=Text_GetSharedResourceScratchBuffer();
  memset(data,0,0x800);
  _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(5,data,0,0x800,true,false);
  _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(7,data,0,0x800,true,false);
  _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(9,data,0,0x800,true,false);
  _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(6,data,0,0x20,true,false);
  _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(8,data,0,0x20,true,false);
  _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(10,data,0,0x20,true,false);
  unsigned* state=(unsigned*)SystemState_GetGlobalFlags();
  if(!SystemState_TestAnyFlags(state,1) && !SystemState_TestAnyFlags(state,0x40))
   _Z17SetMainBrightnessP13GameResourcesii(resources,0,40);
  else _Z13SetBrightnessP13GameResourcesii(resources,0,40);
 }
 void* obj=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
 if(obj)GameObject_RequestMovementInputEnable(obj);
 self[1]=1;
 return 8;
}
