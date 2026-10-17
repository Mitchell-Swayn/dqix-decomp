#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" unsigned char* ReadGlobalValueAt020FB3F0();extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);extern "C" int sprintf(char*,const char*,...);extern "C" char* strcpy(char*,const char*);extern "C" char data_020ef587[];extern "C" char* data_020ef460[3];extern "C" char data_020ef58f[];
// Original: arm9/main @ 0x02020B98; symbol: func_02020b98; size: 0x80.
extern "C" int BackgroundLoader_QueueFormattedInnerPathAndCopyNames(unsigned char* p){void* loader=_ZN16BackgroundLoader11GetInstanceEv();unsigned char* ctx=ReadGlobalValueAt020FB3F0();char path[32];sprintf(path,data_020ef587,ctx+38);int task=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_020ef460[2],path,0);strcpy((char*)p+0xa35,(char*)ctx+38);strcpy((char*)p+0x548,data_020ef58f);return task;}
