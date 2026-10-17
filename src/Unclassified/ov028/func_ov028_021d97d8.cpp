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
// Original: arm9/ov028 @ 0x021D97D8; symbol: func_ov028_021d97d8; size: 0xA4.
extern "C" int func_ov028_021d97d8(void* args){Record rec;func_ov028_021d987c(&rec);rec.id=_ZNK6Script9Parameter5ToIntEv(args);rec.flags=_ZNK6Script9Parameter5ToIntEv((char*)args+8);rec.y=_ZNK6Script9Parameter5ToIntEv((char*)args+16);const char* text=_ZNK6Script9Parameter8ToStringEv((char*)args+24);if(text){unsigned n=String_CountBytesUntilTerminator(text);char* copy=(char*)_ZN13SafeAllocator8AllocateEj(data_ov028_021d9bc4.allocator,n+1);if(copy){memset(copy,0,n);sprintf(copy,text);rec.text=copy;}}func_ov028_021d999c(data_ov028_021d9bc4.list,&rec);return 1;}
