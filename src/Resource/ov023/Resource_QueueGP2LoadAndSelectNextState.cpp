#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" const char* data_020f2a1c;
extern "C" const char* data_020f2a14;
struct Resource { int pad[2]; unsigned int kind:4;unsigned int rest:28; };
// Original: arm9/ov023 @ 0x021E05E4; symbol: func_ov023_021e05e4; size: 0xAC.
extern "C" int Resource_QueueGP2LoadAndSelectNextState(unsigned char* p) {
void* loader=_ZN16BackgroundLoader11GetInstanceEv();
if(*(unsigned short*)(p+0x774)&0x1000)return 8;
if(!*(void**)(p+0x4c))return 3;
memset(p+0x630,0,0x100);
*(int*)(p+0x740)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_020f2a1c,data_020f2a14,0);
int simple=(*(Resource**)(p+0x4c))->kind<=7;
if(simple)return 3;
if(*(unsigned short*)(p+0x774)&0x400)return 3;
return 8;
}
