#include <globaldefs.h>
struct Record { short id,y; unsigned flags; char* text; };
struct List { float speed; Record* records; unsigned short used,capacity; };
struct Pair64 { unsigned lo,hi; inline Pair64& operator=(const Pair64& r) { lo=r.lo;hi=r.hi;return *this; } };
struct State { List list; unsigned char base[0x14]; unsigned char resource[0x20]; void* tiles; unsigned char alloc[0x14]; unsigned mainLayers,subLayers; int scroll,nextScroll; unsigned unk68; unsigned short index; unsigned char dirty,pad; int request; unsigned saved1,saved2,saved3; unsigned char phase,step,pad2[2]; Pair64 start,now; unsigned prior,elapsed; unsigned char toggle,pad3[3]; Pair64 epoch,delta; };
struct Sprite { unsigned char head[8]; void* tiles; unsigned char body[0x94]; unsigned fielda0,fielda4; unsigned short width,height,x,y; };
extern "C" {
void func_ov028_021d98b8(List*); void func_ov028_021d8b90(State*); void func_ov028_021d8c20(State*); void func_ov028_021d8b44(State*,void*);
void func_ov028_021d9668(State*); void func_ov028_021d9188(State*); void func_ov028_021d9574(State*); int func_ov028_021d8d40(State*,int); void func_ov028_021d9624(State*);
void func_ov028_021d9494(State*); void func_ov028_021d9530(State*,void*); void func_ov028_021d94e4(State*);
void Object_InitializeThirtyOneByteRecordWithParameter(void*); void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*); void* _ZN13SafeAllocator16AllocateReversedEj(void*,unsigned); void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
unsigned long long _Z19GetCurrentTimestampv(); bool _Z27SetResourceMutexOperationalb(bool);
void _Z25CleanInvalidateCacheRangePKvj(void*,unsigned);void _Z15CleanCacheRangePKvj(void*,unsigned); void LoadToSubBG1CharacterData(void*,unsigned,unsigned);
void TextCanvas_InitializeLayoutAndTransferDefaults(Sprite*); void Object_ClearElement0AndClearElement2AndClearElement8(void*); void ConfigurePeriodicScanlineAlarmUnderIRQProtection(void*,int,int,void(*)(State*),State*); void Timer_CancelActiveRecordAtomically(void*);
extern State data_ov028_021d9b14; extern unsigned char data_ov028_021d9aec[];
}
// Original: arm9/ov028 @ 0x021D96BC; symbol: func_ov028_021d96bc; size: 0x58.
extern "C" void func_ov028_021d96bc(void* a){func_ov028_021d9494(&data_ov028_021d9b14);func_ov028_021d9530(&data_ov028_021d9b14,a);Object_ClearElement0AndClearElement2AndClearElement8(data_ov028_021d9aec);ConfigurePeriodicScanlineAlarmUnderIRQProtection(data_ov028_021d9aec,0xd7,0x1e,func_ov028_021d9668,&data_ov028_021d9b14);}
