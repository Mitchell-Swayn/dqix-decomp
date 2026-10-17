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
struct CreditRecord { short id,y;unsigned type:4;unsigned alignment:2;unsigned gap:1;unsigned style:4;unsigned rest:21;char* text; };
extern "C" {
CreditRecord* func_ov028_021d99f8(List*,unsigned short);int TextLayout_ComputeWidthWithGlyphSpacing(char*,int);
void func_0204f41c(Sprite*,short,short,char*,unsigned char,unsigned char,short*,short*,int);
void Input_TestKeyMask(void*,int);extern unsigned char data_02114e30[];
}
typedef void (State::*CreditHandler)(int);
struct CreditHandlers { CreditHandler handlers[4]; };
extern "C" { extern const CreditHandlers data_ov028_021d9a34;extern const CreditHandler data_020e6d5c; }
// Original: arm9/ov028 @ 0x021D8D40; symbol: func_ov028_021d8d40; size: 0x90.
extern "C" int func_ov028_021d8d40(State* p,int ticks){ CreditHandlers local=data_ov028_021d9a34;local.handlers[3]=data_020e6d5c;if(!local.handlers[p->phase])return 1;(p->*local.handlers[p->phase])(ticks);return 0;}
