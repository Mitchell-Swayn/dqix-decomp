#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" void* _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);extern "C" void BackgroundLoader_RemoveTaskAndInvalidateHandle(void*,void*);
// Original: arm9/main @ 0x020E063C; symbol: func_020e063c; size: 0x4C.
extern "C" void BackgroundLoader_QueueArchiveFileAndMarkPending(unsigned char* p,const char* file,const char* path){void* loader=_ZN16BackgroundLoader11GetInstanceEv();p[0x9c5]=1;BackgroundLoader_RemoveTaskAndInvalidateHandle(p,p+0xa0c);*(void**)(p+0xa0c)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,file,path,0);}
