#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct State;
extern "C" char data_ov023_021fe5ec[];
extern "C" void* func_ov011_021849c8(State*);
extern "C" int OV023_ReadWordField04(void*);
extern "C" void OV023_WriteWordField04(void*,int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
// Original: arm9/ov023 @ 0x021F75D0; symbol: func_ov023_021f75d0; size: 0xB8.
extern "C" int Filesystem_QueueNamedFileOrArchiveLoad(unsigned char* self,State* state) {
 void* data=func_ov011_021849c8(state);
 if(!*(const char**)(self+0x10)) return 1;
 if(OV023_ReadWordField04(data)<0) {
  void* loader=_ZN16BackgroundLoader11GetInstanceEv();
  char path[80];
  if(*(const char**)(self+0x24)) sprintf(path,data_ov023_021fe5ec,*(const char**)(self+0x24));
  else sprintf(path,data_ov023_021fe5ec,*(const char**)(self+0x10));
  int task;
  if(*(const char**)(self+0x24)) task=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,path,*(const char**)(self+0x10),0);
  else task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
  OV023_WriteWordField04(data,task);
  return 1;
 }
 return *(int*)(self+0x1c);
}
