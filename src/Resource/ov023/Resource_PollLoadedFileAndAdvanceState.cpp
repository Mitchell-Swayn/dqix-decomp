#include <globaldefs.h>
ARM
struct State;
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" unsigned _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void* func_ov011_021849c8(State*);
extern "C" void OV023_WriteWordField04(void*,int);
extern "C" int OV023_ReadWordField04(void*);
extern "C" void Graphics_LoadNamedResourcesAndStageSharedState(unsigned char*,State*,void*,unsigned);
// Original: arm9/ov023 @ 0x021FA9A4; symbol: func_ov023_021fa9a4; size: 0xAC.
extern "C" int Resource_PollLoadedFileAndAdvanceState(unsigned char* object,State* state) {
void* owner=func_ov011_021849c8(state);
void* loader=_ZN16BackgroundLoader11GetInstanceEv();
int task=OV023_ReadWordField04(owner);
if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)){
if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)==2){void* data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&data,&size);Graphics_LoadNamedResourcesAndStageSharedState(object,state,data,size);}
_ZN16BackgroundLoader10RemoveTaskEi(loader,task);
OV023_WriteWordField04(owner,-1);
return 2;
}
return *(int*)(object+0x1c);
}
