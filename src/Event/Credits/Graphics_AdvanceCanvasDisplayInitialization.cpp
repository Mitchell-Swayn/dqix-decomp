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
struct DrawConfig { unsigned words[7]; unsigned char kind:4;unsigned char mode:4;unsigned char tail[3]; };
extern "C" {
void* DisplayContext_GetGlobalInstance();void* _ZN16BackgroundLoader11GetInstanceEv();void BackgroundLoader_CancelEightTasksAndResetState(void*);void DisplayContext_IgnoreCommand(void*,int,int,int,int);bool DisplayContext_ReportRequestComplete(void*);void GameState_EnableGlobalFlag64();void Graphics_CacheFourMainBackgroundControlsOnce(void*);
int GameResources_GetPrimaryFlags(void*);int GameResources_GetSecondaryFlags(void*);int GameResources_GetTertiaryFlags(void*);void Graphics_DisableAndSaveSelectedVRAMBankMappings(void*,int);void VRAMBankConfig_ApplyMappings(void*,int,int,int,int,int,int,int);
void Graphics_InitializeCanvasTransferState(DrawConfig*);void Graphics_SetTextBackgroundScreenSize(DrawConfig*,int);void Graphics_InvokeTwoIndexTransferCallback(DrawConfig*,int,int);void Graphics_ParseTaggedLayerResource(DrawConfig*,void*);void Graphics_DispatchResourceByFourByteMagic(DrawConfig*,void*);
void* memcpy(void*,const void*,unsigned);void LoadToSubBGStandardPalette(void*,unsigned,unsigned);void LoadToSubBG1ScreenData(void*,unsigned,unsigned);
int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,char*,int);bool _ZN16BackgroundLoader13GetTaskStatusEi(void*,int);void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);void _ZN13SafeAllocator5ResetEv(void*);void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);bool _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern char Graphics_AdvanceCanvasDisplayInitialization_PathDataEvsptLv5StaffrollBin[];
}
// Original: arm9/ov028 @ 0x021D8DD0; symbol: func_ov028_021d8dd0; size: 0x3B8.
extern "C" void Graphics_AdvanceCanvasDisplayInitialization(State* p,int ticks) {
void* screen=DisplayContext_GetGlobalInstance();void* loader=_ZN16BackgroundLoader11GetInstanceEv();void* res=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
if(p->step==0){BackgroundLoader_CancelEightTasksAndResetState(screen);DisplayContext_IgnoreCommand(screen,0x7a,0x20b,0,0);p->step++;}
else if(p->step==1){if(DisplayContext_ReportRequestComplete(screen))p->step++;}
else if(p->step==2){GameState_EnableGlobalFlag64();Graphics_CacheFourMainBackgroundControlsOnce(p->base);p->saved1=GameResources_GetPrimaryFlags(res);p->saved2=GameResources_GetSecondaryFlags(res);p->saved3=GameResources_GetTertiaryFlags(res);GameResources_SetSecondaryFlags(res,0x90);
unsigned short* tiles=(unsigned short*)p->tiles;Graphics_DisableAndSaveSelectedVRAMBankMappings(p->resource,2);VRAMBankConfig_ApplyMappings(p->resource,2,0,0,0,0,0x180,0);
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&0x43)|0x1000;
DrawConfig config;Graphics_InitializeCanvasTransferState(&config);config.kind=1;config.mode=1;Graphics_SetTextBackgroundScreenSize(&config,0);Graphics_InvokeTwoIndexTransferCallback(&config,0,0);void* g=((void**)res)[11];Graphics_ParseTaggedLayerResource(&config,g);Graphics_DispatchResourceByFourByteMagic(&config,g);
unsigned short color=0x67f5;memcpy(tiles,&color,2);_Z25CleanInvalidateCacheRangePKvj(tiles,2);LoadToSubBGStandardPalette(tiles,10,2);
for(unsigned short i=0;i<0x400;i++)tiles[i]=i;_Z25CleanInvalidateCacheRangePKvj(tiles,0x800);LoadToSubBG1ScreenData(tiles,0,0x800);
memset(tiles,0x11111111,0x8000);_Z25CleanInvalidateCacheRangePKvj(tiles,0x8000);LoadToSubBG1CharacterData(tiles,0,0x8000);memset(p->tiles,0x11111111,0x8000);_Z25CleanInvalidateCacheRangePKvj(p->tiles,0x8000);
volatile unsigned short* control=(volatile unsigned short*)0x04001008;control[0]=(control[0]&~3)|1;control[1]=(control[1]&~3);control[2]=(control[2]&~3)|2;control[3]=(control[3]&~3)|3;
*(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x1100;*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x200;p->step++;
}
else if(p->step==3){p->request=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Graphics_AdvanceCanvasDisplayInitialization_PathDataEvsptLv5StaffrollBin,0);p->step++;}
else if(p->step==4){if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,p->request)){void* bytes;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,p->request,&bytes,&size);if(bytes && size){_ZN13SafeAllocator5ResetEv(p->alloc);StaffRoll_ExecuteDefinitionScript(&p->list,p->alloc,bytes,size);}_ZN16BackgroundLoader10RemoveTaskEi(loader,p->request);p->request=-1;p->step++;}}
else if(p->step==5){p->step++;_Z13SetBrightnessP13GameResourcesii(res,0,30);}
else if(p->step==6){if(!_Z28IsBrightnessTransitionActiveP13GameResources(res)){p->phase=1;p->step=0;}}
}