#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
extern "C" char data_020f1368[],data_020f1382[];extern "C" void func_020dfec0(void*,SafeAllocator*,void*,unsigned);
// Original: arm9/main @ 0x02092F80; symbol: func_02092f80; size: 0x100.
extern "C" ARM void BackgroundLoader_AdvanceThreePhaseGP2ResourceLoad(unsigned char* p){void* file;unsigned size;BackgroundLoader* loader=BackgroundLoader::GetInstance();if(p[0x35]==0){*(int*)(p+0x2c)=loader->QueueLoadFileInGP2(data_020f1368,data_020f1382,0);p[0x35]++;}else if(p[0x35]==1){if(loader->GetTaskStatus(*(int*)(p+0x2c))){loader->GetLoadedFileByID(*(int*)(p+0x2c),&file,&size);((SafeAllocator*)p)->Reset();func_020dfec0(p+0x14,(SafeAllocator*)p,file,size);loader->RemoveTask(*(int*)(p+0x2c));*(int*)(p+0x2c)=-1;p[0x35]++;}}else if(p[0x35]==2){p[0x34]=3;p[0x35]=0;if(p[0x37]&1)p[0x34]=1;if(!(p[0x37]&8))p[0x37]|=4;p[0x36]=0;}}
