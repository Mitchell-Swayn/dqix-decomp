#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct LoaderTaskOwner;struct Record;struct GameState;struct GameResources;struct Catalog;struct Item;struct Layout;struct Input;
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void _ZN13SafeAllocator5ResetEv(void*);


int ResourceFile_CountActiveStrideRecords(Record*);
char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
int Graphics_DispatchDataByResourceMagic(int,void*,int,int);

void* _ZN9GameState11GetInstanceEv();


GameResources* GameResources_GetInstance();void GameResources_SetSecondaryFlags(int,unsigned);
void Graphics_WriteHalfwordRegister35CAndDisplayControl(int,int,int,unsigned short);void G3X_SetClearColor(unsigned,unsigned,unsigned short,unsigned,int);

// Original data: arm9/ov014 @ 0x2189800; symbol: data_ov014_02189800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern const char Graphics_AdvanceLayoutResourceLoading_PathDataAniLaySmlLia[],Graphics_AdvanceLayoutResourceLoading_PathDataAniObjSmiPac[];extern void* BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[];
}
struct Owner;struct FilterNode;struct FilterList;struct ScriptBundle;
extern "C" {
GameResources* GameState_ReadPResources(GameState*);
unsigned DisplayContext_GetGlobalInstance();void BackgroundLoader_CancelEightTasksAndResetState(LoaderTaskOwner*);void DisplayContext_IgnoreHook(void*);void DisplayContext_IgnoreRequest(void*,int,int);int DisplayContext_ReportRequestComplete();
unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
int BestiaryList_LoadAndResolveEntries(unsigned*,void*,unsigned char*,unsigned);
int ResourceStringTable_CopySerializedData(unsigned*,void*,unsigned char*,unsigned);
unsigned BestiaryList_GetEntryCount(Record*);void* BestiaryList_GetEntries(void*);
void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
void BackgroundLoader_QueueThreeNamedGP2Files(unsigned*,unsigned,const char*,unsigned);
int PollAndExecuteLoadedScriptBundles(ScriptBundle*);void TextCanvas_SetEntryTextAlignmentMode(char*,int,int);
void ResourceStringLoader_Reset(char*);
int Bestiary_MarkListedMonstersAfterPrerequisiteOnce(void*);int GameState_Copy4D0ByteStateBufferToOutput(void*);
void BestiaryScreen_MarkDefeatedMonsterEntries(Owner*);
void ColorEffect_ConfigureAlphaBlend(int,unsigned,unsigned,unsigned,unsigned);
void DisplayLayout_AttachBackwardLinkedCanvases(unsigned char*,char*,unsigned char);
FilterNode* Util_FilterAndRebuildNodeList(FilterList*,int,int,int,short,short*);
extern const char Graphics_AdvanceSelectionResourceInitialization_PathDataPrmMonListGp2[],Graphics_AdvanceSelectionResourceInitialization_MarkupMonListLGNat[],Graphics_AdvanceSelectionResourceInitialization_PathDataBinMenuBmSmlGp2[],Graphics_AdvanceSelectionResourceInitialization_TextBmSml[],Graphics_AdvanceSelectionResourceInitialization_PathDataAniObjSml2Pac[],Graphics_AdvanceSelectionResourceInitialization_PathDataBinMenuStrSmlGp2[],Graphics_AdvanceSelectionResourceInitialization_MarkupStrSmlLGNat[];
}
#define F(t,o) (*(t*)(p+(o)))
static inline void SetPriority(volatile unsigned short* reg,unsigned priority) { *reg=(*reg&~3)|priority; }
// Original: arm9/ov014 @ 0x02187568; symbol: func_ov014_02187568; size: 0x5D0.
// Sequences display resources, formats loaded text entries and constructs filtered selection lists.
extern "C" void Graphics_AdvanceSelectionResourceInitialization(unsigned char* p) {
 GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv());
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(p[0x17b]==0) {
  GameResources_SetSecondaryFlags((int)GameResources_GetInstance(),0x609fe);
  Graphics_WriteHalfwordRegister35CAndDisplayControl(0,0,0,0);G3X_SetClearColor(0,0,0x7fff,0,0);
  unsigned ctx=DisplayContext_GetGlobalInstance();BackgroundLoader_CancelEightTasksAndResetState((LoaderTaskOwner*)ctx);DisplayContext_IgnoreHook((void*)ctx);DisplayContext_IgnoreRequest((void*)ctx,0x6a,0);
  ++p[0x17b];
 } else if(p[0x17b]==1) {
  DisplayContext_GetGlobalInstance();if(DisplayContext_ReportRequestComplete())++p[0x17b];
 } else if(p[0x17b]==2) {
  F(int,0x168)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,Graphics_AdvanceSelectionResourceInitialization_PathDataPrmMonListGp2,Graphics_AdvanceSelectionResourceInitialization_MarkupMonListLGNat,0);++p[0x17b];
 } else if(p[0x17b]==3) {
  if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,F(int,0x168))) {
   void* data;unsigned size;
   _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,F(int,0x168),&data,&size);
   if(data) {_ZN13SafeAllocator5ResetEv(F(void*,0xb4));BestiaryList_LoadAndResolveEntries((unsigned*)(p+0xa4),F(void*,0xb4),(unsigned char*)data,size);}
   _ZN16BackgroundLoader10RemoveTaskEi(loader,F(int,0x168));F(int,0x168)=-1;++p[0x17b];
  }
 } else if(p[0x17b]==4) {
  int count=BestiaryList_GetEntryCount((Record*)(p+0xa4));unsigned char* entries=(unsigned char*)BestiaryList_GetEntries(p+0xa4);
  for(int i=0;i<count;i++,entries+=0x20) {
   char text[128]={0};Text_FormatAndConditionallyUppercaseOutput(*(char**)(entries+8),text,0);sprintf(*(char**)(entries+8),text);
  }
  volatile unsigned short* reg=(volatile unsigned short*)0x04001008;
  reg[0]=(reg[0]&0x43)|0x1d00;reg[1]=(reg[1]&0x43)|0x1e00;reg[2]=(reg[2]&0x43)|0x1f08;
  p[0x17e]|=0x10;++p[0x17b];
 } else if(p[0x17b]==5) {
  if(!(p[0x17e]&0x10)) {
   unsigned char* alloc=F(unsigned char*,0xb4);_ZN13SafeAllocator5ResetEv(alloc+0x28);
   BackgroundLoader_QueueThreeNamedGP2Files(F(unsigned*,0xc0),(unsigned)(alloc+0x28),Graphics_AdvanceSelectionResourceInitialization_PathDataBinMenuBmSmlGp2,(unsigned)Graphics_AdvanceSelectionResourceInitialization_TextBmSml);++p[0x17b];
  }
 } else if(p[0x17b]==6) {
  int result=PollAndExecuteLoadedScriptBundles(F(ScriptBundle*,0xc0));if(!result)++p[0x17b];if(result<0)p[0x17a]=6;
 } else if(p[0x17b]==7) {
  TextCanvas_SetEntryTextAlignmentMode(F(char*,0xc0),6,1);p[0x148]=1;F(unsigned,0x138)=F(unsigned,0xd4);F(short,0x144)=8;F(unsigned,0x134)=F(unsigned,0xd8);
  F(int,0x168)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Graphics_AdvanceSelectionResourceInitialization_PathDataAniObjSml2Pac,0);++p[0x17b];
 } else if(p[0x17b]==8) {
  if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,F(int,0x168))) {
   char* block;char* data;unsigned size;unsigned blockSize;
   _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,F(int,0x168),(void**)&data,&size);
   unsigned char* alloc;int count=ResourceFile_CountActiveStrideRecords((Record*)data);alloc=F(unsigned char*,0xb4);_ZN13SafeAllocator5ResetEv(alloc+0x3c);
   for(int i=0;i<count;i++) {char* entry=ResourceFile_GetPayloadByIndex(data,i,&block,&blockSize);if(entry)Graphics_DispatchDataByResourceMagic((int)(p+0xf8),entry,blockSize,(int)(alloc+0x3c));}
   _ZN16BackgroundLoader10RemoveTaskEi(loader,F(int,0x168));F(int,0x168)=-1;++p[0x17b];
  }
 } else if(p[0x17b]==9) {
  ResourceStringLoader_Reset((char*)p+0xe0);F(int,0x168)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,Graphics_AdvanceSelectionResourceInitialization_PathDataBinMenuStrSmlGp2,Graphics_AdvanceSelectionResourceInitialization_MarkupStrSmlLGNat,0);++p[0x17b];
 } else if(p[0x17b]==10) {
  if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,F(int,0x168))) {
   void* data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,F(int,0x168),&data,&size);
   if(data) {unsigned char* alloc=F(unsigned char*,0xb4);_ZN13SafeAllocator5ResetEv(alloc+0x50);ResourceStringTable_CopySerializedData((unsigned*)(p+0xe0),alloc+0x50,(unsigned char*)data,size);}
   _ZN16BackgroundLoader10RemoveTaskEi(loader,F(int,0x168));F(int,0x168)=-1;p[0x17b]+=3;
  }
 } else if(p[0x17b]==11)++p[0x17b];
 else if(p[0x17b]==12)++p[0x17b];
 else if(p[0x17b]==13) {
  Bestiary_MarkListedMonstersAfterPrerequisiteOnce(p+0xa4);GameState_Copy4D0ByteStateBufferToOutput(F(void*,0xdc));BestiaryScreen_MarkDefeatedMonsterEntries((Owner*)p);
  volatile unsigned short* regs=(volatile unsigned short*)0x04001008;
  SetPriority(regs,0);SetPriority(regs+1,1);SetPriority(regs+2,2);SetPriority(regs+3,3);
  volatile unsigned* display=(volatile unsigned*)0x04001000;*display=(*display&~0x1f00)|0x1700;
  ColorEffect_ConfigureAlphaBlend(0x04001050,2,4,10,6);
  unsigned char* service=F(unsigned char*,0xc0);*(void**)(service+0x2c)=F(void*,0xc4);service[0x38]=2;
  DisplayLayout_AttachBackwardLinkedCanvases(F(unsigned char*,0xc0),F(char*,0xc8),4);
  F(unsigned char*,0xc0)[0x3a]=0;
  Util_FilterAndRebuildNodeList((FilterList*)(p+0xa4),-1,-1,0,0,(short*)(p+0x180));
  short count=0;
  FilterNode* list=Util_FilterAndRebuildNodeList((FilterList*)(p+0xa4),F(signed char,0x17d),-1,(p[0x17e]&8)?1:0,16,&count);
  F(FilterNode*,0xb8)=list;F(FilterNode*,0xbc)=list;p[0x17a]=1;p[0x17b]=0;
 }
}
