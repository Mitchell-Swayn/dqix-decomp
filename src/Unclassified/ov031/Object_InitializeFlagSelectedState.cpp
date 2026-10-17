#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" unsigned char data_ov031_02291e3c[];
// Original: arm9/ov031 @ 0x02243518; symbol: func_ov031_02243518; size: 0x178.
extern "C" int Object_InitializeFlagSelectedState(char* self,int flags) {
 _ZN9GameState11GetInstanceEv();
 self[0x2c]=0;
 self[0x34]=1;
 self[0x35]=0;
 self[0x37]=0;
 self[0x36]=0;
 self[0x374]=flags;
 unsigned char mask=flags;
 if(mask&2) {self[0x374]=2;self[0x2c]=0;}
 else if(mask&0x20) {self[0x374]=0x20;self[0x2c]=0;self[0x34]=7;}
 else if(mask&1) self[0x2c]=0;
 else if(mask&4) self[0x2c]=0;
 self[0x44]=0;
 *(int*)(self+0x38)=0;
 *(int*)(self+0x3c)=0;
 *(int*)(self+0x40)=0;
 *(int*)(self+0x48)=0;
 *(int*)(self+0x4c)=0;
 VectorizedMemset(self+0x50,0,0x2c0);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(data_ov031_02291e3c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x14);
 *(int*)(self+0x28)=0;
 *(int*)(self+0x37c)=0;
 *(int*)(self+0x380)=0;
 *(int*)(self+0x384)=0;
 *(int*)(self+0x388)=0;
 *(int*)(self+0x38c)=0;
 *(unsigned char*)(self+0x390)=0;
 *(unsigned char*)(self+0x391)=0;
 *(int*)(self+0x394)=0;
 *(unsigned char*)(self+0x398)=0;
 *(unsigned char*)(self+0x399)=0;
 *(unsigned char*)(self+0x39a)=0;
 *(unsigned char*)(self+0x39b)=0;
 *(int*)(self+0x30)=0;
 *(int*)(self+0x39c)=-1;
 *(int*)(self+0x3a0)=-1;
 *(int*)(self+0x3a4)=0;
 *(int*)(self+0x3a8)=0;
 *(int*)(self+0x3ac)=0;
 *(int*)(self+0x3b0)=0;
 *(int*)(self+0x3b4)=0;
 *(int*)(self+0x3b8)=0;
 *(int*)(self+0x3bc)=0;
 *(int*)(self+0x3c0)=0;
 *(int*)(self+0x3c4)=0;
 *(int*)(self+0x3c8)=0;
 *(int*)(self+0x3cc)=0;
 *(unsigned char*)(self+0x3d0)=0;
 VectorizedMemset(self+0x3d4,0,0x58);
 *(int*)(self+0x42c)=-1;
 *(int*)(self+0x430)=0;
 *(int*)(self+0x434)=0;
 self[0x438]=0;
 self[0x439]=0;
 memset(self+0x43c,0,0x600);
 return 1;
}
