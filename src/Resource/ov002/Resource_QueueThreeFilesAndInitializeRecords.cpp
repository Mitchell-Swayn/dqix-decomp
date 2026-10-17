#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader8AddFenceEv(void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" void Initialize1RecordFields_Main0209A804(void*);
extern "C" void Initialize2RecordFields_Main0209A338(unsigned*);
extern "C" const char* data_020f2a18;
extern "C" const char* data_020f2a0c;
extern "C" const char data_ov002_0216cf21[];
extern "C" const char data_ov002_0216cf39[];
// Original: arm9/ov002 @ 0x02156BC8; symbol: func_ov002_02156bc8; size: 0xB4.
extern "C" void Resource_QueueThreeFilesAndInitializeRecords(char* self) {
if(*(unsigned*)(self+0x247c)&0x10) return;
void* loader=_ZN16BackgroundLoader11GetInstanceEv();
_ZN16BackgroundLoader8AddFenceEv(loader);
*(unsigned*)(self+0x1ba4)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_020f2a18,data_020f2a0c,0);
*(unsigned*)(self+0x1ba8)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,data_ov002_0216cf21,0);
*(unsigned*)(self+0x1bac)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,data_ov002_0216cf39,0);
Initialize1RecordFields_Main0209A804(self+0x2444);
Initialize2RecordFields_Main0209A338((unsigned*)(self+0x243c));
*(unsigned*)(self+0x247c)|=0x10;
}
