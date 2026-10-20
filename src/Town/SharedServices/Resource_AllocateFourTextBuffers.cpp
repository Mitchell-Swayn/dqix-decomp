#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct GameResources;
extern "C" GameResources* GameResources_GetInstance();
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
// Original: arm9/ov003 @ 0x021602BC; symbol: func_ov003_021602bc; size: 0x88.
extern "C" void Resource_AllocateFourTextBuffers(char* self) {
 char* resource=(char*)GameResources_GetInstance();
 for(int i=0;i<4;i++) {
  (*(char***)(self+0x394))[i]=0;
  (*(char***)(self+0x394))[i]=_ZN13SafeAllocator8AllocateEj((unsigned)(self+0x228),0x30);
  memset((*(char***)(self+0x394))[i],0,0x30);
  if(resource+0x435c+i*0x30) sprintf((*(char***)(self+0x394))[i],resource+0x435c+i*0x30);
 }
}
