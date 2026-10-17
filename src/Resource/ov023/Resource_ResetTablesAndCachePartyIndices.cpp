#include <globaldefs.h>
ARM
extern "C" void* GetGlobalStatePointer();
extern "C" void SetWordMaskBits_Main020466E4(unsigned*,unsigned);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13ZoneState27545ResetEv(void*);
extern "C" void ClearResourceTableHeaderFields(char*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" void GameState_CollectPresentPartyMemberIndices(signed char*,signed char*);
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov023 @ 0x021E2DD8; symbol: func_ov023_021e2dd8; size: 0x160.
extern "C" void Resource_ResetTablesAndCachePartyIndices(char* self) {
 SetWordMaskBits_Main020466E4((unsigned*)GetGlobalStatePointer(),15);
 *(int*)(self)=0;*(int*)(self+4)=0;*(int*)(self+0xc)=0;*(int*)(self+0x10)=0;*(int*)(self+0x14)=0;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x2c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x40);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x54);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x68);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x7c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x90);
 _ZN13ZoneState27545ResetEv(self+0xa4);
 *(short*)(self+0xbc)=0;*(short*)(self+0xbe)=0;
 *(int*)(self+0xc0)=0;*(int*)(self+0xc4)=0;*(int*)(self+0xc8)=0;*(int*)(self+0xcc)=0;*(int*)(self+0xd0)=0;
 ClearResourceTableHeaderFields(self+0xd4);
 *(int*)(self+0x128)=0;*(int*)(self+0x12c)=0;*(int*)(self+0x134)=0;
 *(char*)(self+0x4e6)=0;*(char*)(self+0x4e7)=0;
 *(int*)(self+0x120)=0;*(int*)(self+0x124)=0;*(int*)(self+0x4e8)=0;
 void* state=_ZN9GameState11GetInstanceEv();
 signed char count=0; signed char indices[4];
 for(int i=0;i<4;i++)indices[i]=-1;
 GameState_CollectPresentPartyMemberIndices(indices,&count);
 for(int i=0;i<4;i++) {int index=indices[i];*(int*)(self+0x4ec+i*4)=index;GameState_GetObjectWithFlag100(state,index);}
 *(int*)(self+0x4e8)=count;*(char*)(self+0x4e4)=1;
 *(int*)(self+0x630)=0;
 memset(self+0x634,0,2);
 *(char*)(self+0x636)=0;
 *(int*)(self+0x638)=0;*(int*)(self+0x63c)=0;*(int*)(self+0x640)=0;*(int*)(self+0x644)=0;
}
