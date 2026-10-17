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
struct DrawConfig { unsigned words[7]; unsigned char kind:4;unsigned char mode:4;unsigned char tail[3]; };
extern "C" {
void* Object_ReadGlobalDisplayContextWord();void* _ZN16BackgroundLoader11GetInstanceEv();void BackgroundLoader_CancelEightTasksAndResetState(void*);void DisplayContext_IgnoreCommand(void*,int,int,int,int);bool ReturnOne_Main02094B4C(void*);void GameState_EnableGlobalFlag64();void Graphics_CacheFourMainBackgroundControlsOnce(void*);
int ReadValue_Main0203B498(void*);int ReadWordFieldAtOffset4(void*);int Object_ReadWordAtOffset8(void*);void Graphics_DisableAndSaveSelectedVRAMBankMappings(void*,int);void Object_InvokeLockStagedTextureVRAMCopying(void*,int,int,int,int,int,int,int);
void Graphics_InitializeCanvasTransferState(DrawConfig*);void SetWordField18AndClearFormatByte1F(DrawConfig*,int);void Graphics_InvokeTwoIndexTransferCallback(DrawConfig*,int,int);void DispatchResourceParserByFourByteMagic(DrawConfig*,void*);void Graphics_DispatchResourceByFourByteMagic(DrawConfig*,void*);
void* memcpy(void*,const void*,unsigned);void LoadToSubBGStandardPalette(void*,unsigned,unsigned);void LoadToSubBG1ScreenData(void*,unsigned,unsigned);
int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,char*,int);bool _ZN16BackgroundLoader13GetTaskStatusEi(void*,int);void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);void _ZN13SafeAllocator5ResetEv(void*);void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);bool _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern char data_ov028_021d9aa0[];
}
// Original: arm9/ov028 @ 0x021D8DD0; symbol: func_ov028_021d8dd0; size: 0x3B8.
extern "C" void func_ov028_021d8dd0(State* p,int ticks) {
void* screen=Object_ReadGlobalDisplayContextWord();void* loader=_ZN16BackgroundLoader11GetInstanceEv();void* res=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
if(p->step==0){BackgroundLoader_CancelEightTasksAndResetState(screen);DisplayContext_IgnoreCommand(screen,0x7a,0x20b,0,0);p->step++;}
else if(p->step==1){if(ReturnOne_Main02094B4C(screen))p->step++;}
else if(p->step==2){GameState_EnableGlobalFlag64();Graphics_CacheFourMainBackgroundControlsOnce(p->base);p->saved1=ReadValue_Main0203B498(res);p->saved2=ReadWordFieldAtOffset4(res);p->saved3=Object_ReadWordAtOffset8(res);Object_SetUnsignedIntAtOffset4(res,0x90);
unsigned short* tiles=(unsigned short*)p->tiles;Graphics_DisableAndSaveSelectedVRAMBankMappings(p->resource,2);Object_InvokeLockStagedTextureVRAMCopying(p->resource,2,0,0,0,0,0x180,0);
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&0x43)|0x1000;
DrawConfig config;Graphics_InitializeCanvasTransferState(&config);config.kind=1;config.mode=1;SetWordField18AndClearFormatByte1F(&config,0);Graphics_InvokeTwoIndexTransferCallback(&config,0,0);void* g=((void**)res)[11];DispatchResourceParserByFourByteMagic(&config,g);Graphics_DispatchResourceByFourByteMagic(&config,g);
unsigned short color=0x67f5;memcpy(tiles,&color,2);_Z25CleanInvalidateCacheRangePKvj(tiles,2);LoadToSubBGStandardPalette(tiles,10,2);
for(unsigned short i=0;i<0x400;i++)tiles[i]=i;_Z25CleanInvalidateCacheRangePKvj(tiles,0x800);LoadToSubBG1ScreenData(tiles,0,0x800);
memset(tiles,0x11111111,0x8000);_Z25CleanInvalidateCacheRangePKvj(tiles,0x8000);LoadToSubBG1CharacterData(tiles,0,0x8000);memset(p->tiles,0x11111111,0x8000);_Z25CleanInvalidateCacheRangePKvj(p->tiles,0x8000);
volatile unsigned short* control=(volatile unsigned short*)0x04001008;control[0]=(control[0]&~3)|1;control[1]=(control[1]&~3);control[2]=(control[2]&~3)|2;control[3]=(control[3]&~3)|3;
*(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x1100;*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x200;p->step++;
}
else if(p->step==3){p->request=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,data_ov028_021d9aa0,0);p->step++;}
else if(p->step==4){if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,p->request)){void* bytes;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,p->request,&bytes,&size);if(bytes && size){_ZN13SafeAllocator5ResetEv(p->alloc);func_ov028_021d98e0(&p->list,p->alloc,bytes,size);}_ZN16BackgroundLoader10RemoveTaskEi(loader,p->request);p->request=-1;p->step++;}}
else if(p->step==5){p->step++;_Z13SetBrightnessP13GameResourcesii(res,0,30);}
else if(p->step==6){if(!_Z28IsBrightnessTransitionActiveP13GameResources(res)){p->phase=1;p->step=0;}}
}