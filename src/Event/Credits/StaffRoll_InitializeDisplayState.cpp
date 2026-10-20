#include <globaldefs.h>
struct Record { short id,y; unsigned flags; char* text; };
struct List { float speed; Record* records; unsigned short used,capacity; };
struct Pair64 { unsigned lo,hi; inline Pair64& operator=(const Pair64& r) { lo=r.lo;hi=r.hi;return *this; } };
struct State { List list; unsigned char base[0x14]; unsigned char resource[0x20]; void* tiles; unsigned char alloc[0x14]; unsigned mainLayers,subLayers; int scroll,nextScroll; unsigned unk68; unsigned short index; unsigned char dirty,pad; int request; unsigned saved1,saved2,saved3; unsigned char phase,step,pad2[2]; Pair64 start,now; unsigned prior,elapsed; unsigned char toggle,pad3[3]; Pair64 epoch,delta; };
struct Sprite { unsigned char head[8]; void* tiles; unsigned char body[0x94]; unsigned fielda0,fielda4; unsigned short width,height,x,y; };
extern "C" {
void StaffRoll_InitializeRecordList(List*); void StaffRoll_InitializeDisplayState(State*); void Graphics_RestoreCanvasDisplayState(State*); void StaffRoll_AllocateTileBufferAndScriptArena(State*,void*);
void StaffRoll_UploadTilesAndApplyScroll(State*); void StaffRoll_UpdateTimedPhase(State*); int StaffRoll_DispatchPhase(State*,int); void StaffRoll_AdvanceInitialization(State*);
void StaffRoll_InitializeStateAndTiming(State*); void StaffRoll_AllocateBuffersAndStartClock(State*,void*); void StaffRoll_ResetTimingAndRestoreDisplay(State*);
void VRAMBankConfig_Initialize(void*); void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*); void* _ZN13SafeAllocator16AllocateReversedEj(void*,unsigned); void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
unsigned long long _Z19GetCurrentTimestampv(); bool _Z27SetResourceMutexOperationalb(bool);
void _Z25CleanInvalidateCacheRangePKvj(void*,unsigned);void _Z15CleanCacheRangePKvj(void*,unsigned); void LoadToSubBG1CharacterData(void*,unsigned,unsigned);
void TextCanvas_InitializeLayoutAndTransferDefaults(Sprite*); void OS_CreateVAlarm(void*); void ConfigurePeriodicScanlineAlarmUnderIRQProtection(void*,int,int,void(*)(State*),State*); void OS_CancelVAlarm(void*);
// Original data: arm9/ov028 @ 0x21d9aec; symbol: data_ov028_021d9aec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov028.md.
// Original data: arm9/ov028 @ 0x21d9b14; symbol: data_ov028_021d9b14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 176 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov028.md.
extern State StaffRollStopAndRestoreDisplay_UnknownRoleZeroInitializedStorage_Variant2; extern unsigned char StaffRollStopAndRestoreDisplay_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov028 @ 0x021D8B90; symbol: func_ov028_021d8b90; size: 0x90.
extern "C" void StaffRoll_InitializeDisplayState(State* p){StaffRoll_InitializeRecordList(&p->list);p->base[0x14-4]=0;p->base[0x14-3]=0;VRAMBankConfig_Initialize(p->resource);p->tiles=0;_ZN13SafeAllocator21ResetAllocatorPointerEv(p->alloc);p->mainLayers=(*(volatile unsigned*)0x04000000&0x1f00)>>8;p->subLayers=(*(volatile unsigned*)0x04001000&0x1f00)>>8;p->scroll=0;p->nextScroll=0;p->index=0;p->unk68=0;p->dirty=0;p->request=-1;p->saved1=0;p->saved2=0;p->saved3=0;p->phase=0;p->step=0;}
