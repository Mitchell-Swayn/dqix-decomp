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
void StaffRoll_InitializeTextCanvas(Sprite*,void*); void StaffRoll_AdvanceScrollAccumulators(int*,float); void StaffRoll_ClearConsumedTileStrip(int*,void*); void StaffRoll_ExecuteDefinitionScript(List*,void*,const void*,unsigned);void StaffRoll_AppendRecord(List*,Record*);
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
extern "C" {
void* _ZN9GameState11GetInstanceEv();void* GameState_ReadPResources(void*);void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);void _ZN13SafeAllocator7DestroyEv(void*);
void Graphics_ApplyVRAMMappingsUnderTextureLock(void*);void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);void LoadToMainBG1CharacterData(void*,unsigned,unsigned);void StaffRoll_ResetRecordList(List*);
void GameResources_ClearPrimaryFlags(void*,int);void GameResources_ClearSecondaryFlags(void*,int);void GameResources_ClearTertiaryFlags(void*,int);void GameResources_SetPrimaryFlags(void*,int);void GameResources_SetSecondaryFlags(void*,int);void GameResources_SetTertiaryFlags(void*,int);
}
// Original: arm9/ov028 @ 0x021D8C20; symbol: func_ov028_021d8c20; size: 0x120.
extern "C" void Graphics_RestoreCanvasDisplayState(State* p) {
void* resources=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());_Z13SetBrightnessP13GameResourcesii(resources,-16,0);
*(volatile unsigned*)0x04000014=0;*(volatile unsigned*)0x04001014=0;
if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p->alloc))_ZN13SafeAllocator7DestroyEv(p->alloc);
Graphics_ApplyVRAMMappingsUnderTextureLock(p->resource);Graphics_ApplyMainBackgroundSnapshotAndClearPending(p->base);
if(p->tiles){memset(p->tiles,0,32);_Z25CleanInvalidateCacheRangePKvj(p->tiles,32);LoadToMainBG1CharacterData(p->tiles,0,32);}
StaffRoll_ResetRecordList(&p->list);
GameResources_ClearPrimaryFlags(resources,-1);GameResources_ClearSecondaryFlags(resources,-1);GameResources_ClearTertiaryFlags(resources,-1);
GameResources_SetPrimaryFlags(resources,p->saved1);GameResources_SetSecondaryFlags(resources,p->saved2);GameResources_SetTertiaryFlags(resources,p->saved3);
*(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|(p->mainLayers<<8);
*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|(p->subLayers<<8);
StaffRoll_InitializeDisplayState(p);
}