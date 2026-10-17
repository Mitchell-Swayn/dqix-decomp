#include <globaldefs.h>
ARM
extern "C" void FreeWithGlobalSafeAllocator(void*);
struct Owner { char pad[0x70];void* pair[2];};
struct Virtual { void (**vtable)(void*); };
// Original: arm9/ov016 @ 0x0218EDAC; symbol: func_ov016_0218edac; size: 0x168.
extern "C" void Memory_ReleaseOwnedResources(char* p){
Virtual* v=*(Virtual**)p;
if(v){v->vtable[6](v);v=*(Virtual**)p;if(v)v->vtable[1](v);}
FreeWithGlobalSafeAllocator(*(void**)(p+0x34));
if(*(void**)(p+0x5c)){
unsigned i=0;
if(*(unsigned*)(p+0xa8)>i)do{FreeWithGlobalSafeAllocator((*(void***)(p+0x5c))[i]);i++;}while(i<*(unsigned*)(p+0xa8));
FreeWithGlobalSafeAllocator(*(void**)(p+0x5c));
}
if(*(void**)(p+0x60)){
unsigned i=0;
if(*(unsigned*)(p+0xa8)>i)do{FreeWithGlobalSafeAllocator((*(void***)(p+0x60))[i]);i++;}while(i<*(unsigned*)(p+0xa8));
FreeWithGlobalSafeAllocator(*(void**)(p+0x60));
}
if(*(void**)(p+0x64))FreeWithGlobalSafeAllocator(*(void**)(p+0x64));
if(*(void**)(p+0x68))FreeWithGlobalSafeAllocator(*(void**)(p+0x68));
if(*(void**)(p+0x6c))FreeWithGlobalSafeAllocator(*(void**)(p+0x6c));
int i=0;do{
if(((Owner*)p)->pair[i])FreeWithGlobalSafeAllocator(((Owner*)p)->pair[i]);
((Owner*)p)->pair[i]=0;
i++;
}while(i<2);
if(*(void**)(p+0x94))FreeWithGlobalSafeAllocator(*(void**)(p+0x94));
if(*(void**)(p+0x58))FreeWithGlobalSafeAllocator(*(void**)(p+0x58));
*(void**)p=0;*(void**)(p+0x5c)=0;*(void**)(p+0x60)=0;*(void**)(p+0x68)=0;*(void**)(p+0x6c)=0;*(void**)(p+0x64)=0;*(void**)(p+0x58)=0;*(void**)(p+0x94)=0;
}
