#include <globaldefs.h>
struct Argument { unsigned kind; const char* value; };
extern "C" void* func_ov017_021b2164();
extern "C" int func_ov011_021849d8(void*);
extern "C" void func_ov011_021849d0(void*,unsigned);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" const char data_ov011_02188b6c[];
extern "C" int sprintf(char*,const char*,...);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
// Original: arm9/ov011 @ 0x0218554C; symbol: func_ov011_0218554c; size: 0x80.
extern "C" unsigned func_ov011_0218554c(Argument* self) {
 char filename[80];
 const char* value=self->kind==2 ? self->value : 0;
 if(!value) return 0;
 void* owner=func_ov017_021b2164();
 if(func_ov011_021849d8(owner)>=0) return 0;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 sprintf(filename,data_ov011_02188b6c,value);
 unsigned ticket=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,filename,0);
 func_ov011_021849d0(owner,ticket);
 return 1;
}
