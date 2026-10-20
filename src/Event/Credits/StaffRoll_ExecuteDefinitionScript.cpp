#include <globaldefs.h>
struct Record { short id,y; unsigned flags; char* text; };
struct List { float speed; Record* records; unsigned short used,capacity; };
struct Pair64 { unsigned lo,hi; inline Pair64& operator=(const Pair64& r) { lo=r.lo;hi=r.hi;return *this; } };
struct State { List list; unsigned char base[0x14]; unsigned char resource[0x20]; void* tiles; unsigned char alloc[0x14]; unsigned mainLayers,subLayers; int scroll,nextScroll; unsigned unk68; unsigned short index; unsigned char dirty,pad; int request; unsigned saved1,saved2,saved3; unsigned char phase,step,pad2[2]; Pair64 start,now; unsigned prior,elapsed; unsigned char toggle,pad3[3]; Pair64 epoch,delta; };
struct Sprite { unsigned char head[8]; void* tiles; unsigned char body[0x94]; unsigned fielda0,fielda4; unsigned short width,height,x,y; unsigned char tail[0x30]; };
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
extern "C" {
void StaffRoll_InitializeTextCanvas(Sprite*,void*); void StaffRoll_AdvanceScrollAccumulators(int*,float); void StaffRoll_ClearConsumedTileStrip(int*,void*); void StaffRoll_AppendRecord(List*,Record*);
// Original data: arm9/ov028 @ 0x21d9ac0; symbol: data_ov028_021d9ac0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000b0971d0265000000d8971d026600000098981d020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov028.md.
extern struct Pair { List* list;void* allocator; } StaffRollScriptSetScrollSpeed_UnknownRoleZeroInitializedStorage; extern unsigned char StaffRollExecuteDefinitionScript_UnknownRoleProcedureReferenceRecords[];
void _ZN6Script10InitializeEv(void*); void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*,void*);void _ZN6Script4LoadEPKvj(void*,const void*,unsigned);void _ZN6Script7ExecuteEv(void*);
unsigned _ZNK6Script9Parameter5ToIntEv(void*);const char* _ZNK6Script9Parameter8ToStringEv(void*);unsigned String_CountBytesUntilTerminator(const char*);void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);void StaffRoll_InitializeRecord(Record*);
void* memset(void*,int,unsigned);int sprintf(char*,const char*,...);
}
// Original: arm9/ov028 @ 0x021D98E0; symbol: func_ov028_021d98e0; size: 0x60.
extern "C" void StaffRoll_ExecuteDefinitionScript(List* p,void* a,const void* bytes,unsigned size){p->records=0;p->used=0;StaffRollScriptSetScrollSpeed_UnknownRoleZeroInitializedStorage.allocator=a;StaffRollScriptSetScrollSpeed_UnknownRoleZeroInitializedStorage.list=p;unsigned script[0x430/4];_ZN6Script10InitializeEv(script);_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script,StaffRollExecuteDefinitionScript_UnknownRoleProcedureReferenceRecords);_ZN6Script4LoadEPKvj(script,bytes,size);_ZN6Script7ExecuteEv(script);}
