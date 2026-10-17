#include <globaldefs.h>
ARM
struct State;
extern "C" void* func_ov011_021849c8(State*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" unsigned OV023_ReadWordField04(void*);
extern "C" void OV023_WriteWordField04(void*,int);
extern "C" void World_LoadZoneRenderPartWithSavedVram(char*,State*,const void*,int);
// Original: arm9/ov023 @ 0x021F707C; symbol: func_ov023_021f707c; size: 0xAC.
extern "C" int World_PollZoneRenderPartLoad(char* self,State* state) {
 void* data=func_ov011_021849c8(state);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 unsigned task=OV023_ReadWordField04(data);
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)) {
  if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)==2) {
   void* file; unsigned size;
   _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&file,&size);
   World_LoadZoneRenderPartWithSavedVram(self,state,file,size);
  }
  _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
  OV023_WriteWordField04(data,-1);
  return 2;
 }
 return *(int*)(self+0x1c);
}
