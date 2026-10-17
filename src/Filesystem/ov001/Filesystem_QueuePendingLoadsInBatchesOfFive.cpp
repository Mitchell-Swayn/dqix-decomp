#include <globaldefs.h>
ARM
#pragma optimization_level 2
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" const char data_ov001_02164bd7[];
struct Entry { unsigned char kind:4,other:4; char pad[7]; char path[36]; unsigned handle; char pad30; unsigned char loaded; short pad32; Entry* next; };
struct Entry2 { char pad; char path[35]; unsigned handle; Entry2* next; unsigned char loaded; };
// Original: arm9/ov001 @ 0x02154C64; symbol: func_ov001_02154c64; size: 0x13C.
extern "C" int Filesystem_QueuePendingLoadsInBatchesOfFive(unsigned char* p) {
 int count=0;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 Entry* e=*(Entry**)(p+0xd0);
 int result=0;
 while(e) {
 unsigned kind=e->kind;
 if((!(kind!=2 && kind!=3 && kind!=6 && kind!=7 && kind!=8)) && !e->loaded) {
 unsigned h;
 if(kind==6) h=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_ov001_02164bd7,e->path,0);
 else h=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,e->path,0);
 count++;e->handle=h;
 result=1;
 if(count==5){p[0x100]=0;return result;}
 }
 e=e->next;
 }
 Entry2* f=*(Entry2**)(p+0xd4);
 while(f){
 if(!f->loaded){unsigned h=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,f->path,0);count++;f->handle=h;result=1; if(count==5){p[0x100]=0;return result;}}
 f=f->next;
 }
 if(*(signed char*)(p+0xd8)){*(unsigned*)(p+0xf4)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,(char*)p+0xd8,0);result=1;}
 p[0x100]=1;return result;
}
