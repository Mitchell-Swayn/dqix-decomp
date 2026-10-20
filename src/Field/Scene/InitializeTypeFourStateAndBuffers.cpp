#include <globaldefs.h>
ARM
struct GameResources;
extern "C" void* memset(void*,int,unsigned);
extern "C" void LinkedQueue_InitializeNodeStatus(signed char*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" int GameResources_GetMaskedPrimaryFlags(GameResources*,unsigned);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void Field_ResetEventCommandScratchRecord(unsigned*);
struct Bits {unsigned char first:1;unsigned char rest:7;};
// Original: arm9/ov017 @ 0x021BAEDC; symbol: func_ov017_021baedc; size: 0x1AC.
// Initializes type-four state, optional persistent fields, allocators and buffers.
extern "C" void InitializeTypeFourStateAndBuffers(unsigned char *p,int preserve){
 LinkedQueue_InitializeNodeStatus((signed char*)p);p[0]=4;
 *(short*)(p+8)=0;*(short*)(p+10)=0;*(int*)(p+0x90)=0;*(short*)(p+0x11a)=0;*(short*)(p+0x14e)=-1;
 p[0x9c]=0;p[0x98]=0;p[0x99]=0;p[0x9a]=0;p[0x9b]=0;p[0xcc]=0;p[0xcd]=0;*(signed char*)(p+0xa0)=-1;*(int*)(p+0x110)=-1;
 p[0xfe]=0;p[0x100]=0;p[0x101]=0;p[0x102]=0;p[0x103]=0;p[0x104]=0;p[0x106]=0;p[0x107]=0;p[0x108]=0;p[0x109]=0;p[0x10a]=0;p[0x10b]=0;p[0x10c]=0;
 if(!preserve)p[0x105]=0;
 if(!preserve)*(short*)(p+0x11c)=0;
 memset(p+12,0,0x68);*(short*)(p+0x114)=0;Field_ResetEventCommandScratchRecord((unsigned*)(p+0xd0));
 if(!GameResources_GetMaskedPrimaryFlags(GameResources_GetInstance(),0x1000))_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x7c);
 *(int*)(p+0x120)=0;_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x124);
 memset(p+0x13c,0,0x12);memset(p+0x150,0,10);
 *(int*)(p+0x15c)=0;p[0xfd]=0;*(signed char*)(p+0x116)=-1;*(int*)(p+0x160)=0;p[0x164]=1;*(int*)(p+0x170)=0;*(int*)(p+0x168)=0;*(int*)(p+0x16c)=0;*(int*)(p+0x138)=0;
 p[0xff]=0;p[0x174]=0;p[0x175]=0;
 ((Bits*)(p+0x178))->first=0;((Bits*)(p+0x178))->rest=0;
 p[0x179]=0;p[0x17a]=0;p[0x17b]=0;*(float*)(p+0x17c)=-1.0f;*(short*)(p+0x184)=0;
 memset(p+0x188,0,0x30);memset(p+0x1b8,0,0x10);
}
