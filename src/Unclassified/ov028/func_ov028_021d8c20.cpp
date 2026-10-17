#include <globaldefs.h>
struct Record { short id,y; unsigned flags; char* text; };
struct List { float speed; Record* records; unsigned short used,capacity; };
struct Pair64 { unsigned lo,hi; inline Pair64& operator=(const Pair64& r) { lo=r.lo;hi=r.hi;return *this; } };
struct State { List list; unsigned char base[0x14]; unsigned char resource[0x20]; void* tiles; unsigned char alloc[0x14]; unsigned mainLayers,subLayers; int scroll,nextScroll; unsigned unk68; unsigned short index; unsigned char dirty,pad; int request; unsigned saved1,saved2,saved3; unsigned char phase,step,pad2[2]; Pair64 start,now; unsigned prior,elapsed; unsigned char toggle,pad3[3]; Pair64 epoch,delta; };
struct Sprite { unsigned char head[8]; void* tiles; unsigned char body[0x94]; unsigned fielda0,fielda4; unsigned short width,height,x,y; unsigned char tail[0x30]; };
extern "C" {
void func_ov028_021d98b8(List*); void func_ov028_021d8b90(State*); void func_ov028_021d8c20(State*); void func_ov028_021d8b44(State*,void*);
void func_ov028_021d9188(State*); void func_ov028_021d9574(State*); int func_ov028_021d8d40(State*,int); void func_ov028_021d9624(State*);
void func_ov028_021d9494(State*); void func_ov028_021d9530(State*,void*); void func_ov028_021d94e4(State*);
void Object_InitializeThirtyOneByteRecordWithParameter(void*); void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*); void* _ZN13SafeAllocator16AllocateReversedEj(void*,unsigned); void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
unsigned long long _Z19GetCurrentTimestampv(); bool _Z27SetResourceMutexOperationalb(bool);
void _Z25CleanInvalidateCacheRangePKvj(void*,unsigned);void _Z15CleanCacheRangePKvj(void*,unsigned); void LoadToSubBG1CharacterData(void*,unsigned,unsigned);
void TextCanvas_InitializeLayoutAndTransferDefaults(Sprite*); void Object_ClearElement0AndClearElement2AndClearElement8(void*); void ConfigurePeriodicScanlineAlarmUnderIRQProtection(void*,int,int,void(*)(State*),State*); void Timer_CancelActiveRecordAtomically(void*);
extern State data_ov028_021d9b14; extern unsigned char data_ov028_021d9aec[];
}
extern "C" {
void func_ov028_021d8a40(Sprite*,void*); void func_ov028_021d8a74(int*,float); void func_ov028_021d8ad4(int*,void*); void func_ov028_021d98e0(List*,void*,const void*,unsigned);void func_ov028_021d999c(List*,Record*);
extern struct Pair { List* list;void* allocator; } data_ov028_021d9bc4; extern unsigned char data_ov028_021d9ac0[];
void _ZN6Script10InitializeEv(void*); void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*,void*);void _ZN6Script4LoadEPKvj(void*,const void*,unsigned);void _ZN6Script7ExecuteEv(void*);
unsigned _ZNK6Script9Parameter5ToIntEv(void*);const char* _ZNK6Script9Parameter8ToStringEv(void*);unsigned String_CountBytesUntilTerminator(const char*);void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);void func_ov028_021d987c(Record*);
void* memset(void*,int,unsigned);int sprintf(char*,const char*,...);
}
extern "C" {
void* _ZN9GameState11GetInstanceEv();void* GameState_ReadPResources(void*);void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);void _ZN13SafeAllocator7DestroyEv(void*);
void Graphics_ApplyVRAMMappingsUnderTextureLock(void*);void ProcessActiveObjectAndClearActiveFlag(void*);void LoadToMainBG1CharacterData(void*,unsigned,unsigned);void func_ov028_021d98d4(List*);
void Flags_ClearWordMask(void*,int);void ClearWordAtOffset4MaskedBits(void*,int);void ClearMaskedFlagsAtOffset8(void*,int);void SetWordMaskBits_Main0203B4A0(void*,int);void Object_SetUnsignedIntAtOffset4(void*,int);void SetWordAtOffset8MaskedBits(void*,int);
}
// Original: arm9/ov028 @ 0x021D8C20; symbol: func_ov028_021d8c20; size: 0x120.
extern "C" void func_ov028_021d8c20(State* p) {
void* resources=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());_Z13SetBrightnessP13GameResourcesii(resources,-16,0);
*(volatile unsigned*)0x04000014=0;*(volatile unsigned*)0x04001014=0;
if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p->alloc))_ZN13SafeAllocator7DestroyEv(p->alloc);
Graphics_ApplyVRAMMappingsUnderTextureLock(p->resource);ProcessActiveObjectAndClearActiveFlag(p->base);
if(p->tiles){memset(p->tiles,0,32);_Z25CleanInvalidateCacheRangePKvj(p->tiles,32);LoadToMainBG1CharacterData(p->tiles,0,32);}
func_ov028_021d98d4(&p->list);
Flags_ClearWordMask(resources,-1);ClearWordAtOffset4MaskedBits(resources,-1);ClearMaskedFlagsAtOffset8(resources,-1);
SetWordMaskBits_Main0203B4A0(resources,p->saved1);Object_SetUnsignedIntAtOffset4(resources,p->saved2);SetWordAtOffset8MaskedBits(resources,p->saved3);
*(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|(p->mainLayers<<8);
*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|(p->subLayers<<8);
func_ov028_021d8b90(p);
}