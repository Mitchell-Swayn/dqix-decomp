#include <globaldefs.h>
ARM
#pragma always_inline on
struct GameState; struct Table;
extern "C" {
void* memset(void*,int,unsigned);
void* _ZN9GameState11GetInstanceEv();
int GameState_ReadProtagonistObjectIndex(GameState*);
void* Network_GetConnectionManager();
bool Network_IsClientSession(unsigned*);
void* _ZN16BackgroundLoader11GetInstanceEv();
void _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
void _ZN16BackgroundLoader13AddLockGlobalEv();
void _ZN16BackgroundLoader16RemoveLockGlobalEv();
int _ZN16BackgroundLoader17GetNumQueuedTasksEv(void*);
void SystemState_SetFlags(unsigned*,unsigned);
void SystemState_ClearFlags(unsigned*,unsigned);
void* _Z11GetBTRandomv();
int _Z13NextRandomMaxP6Randomi(void*,int);
void TextCanvas_ResetDisplayPartByKey(unsigned char*,int);
void TextCanvas_EnableEntryUppercaseFormatting(unsigned char*,int);
void TextCanvas_HideDisplayPart(unsigned char*,int);
void TextCanvas_ShowDisplayPart(unsigned char*,int);
void TextCanvas_SetEntryTextPointer(char*,int,int);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
void Bgm_RequestTemporarySequence(int,unsigned short);
void SaveData_ResetTransferProgress(unsigned char*);
int SaveData_AdvanceStagedSaveWrite(void*,void*,int,int);
void* SystemState_GetGlobalFlags();
int Equipment_GetPartyRestrictionMask(int,void*);
void String_ReplaceBracketedNamesByRowColumnTable(const signed char*,signed char*,int,unsigned,unsigned,int);
void* Text_LookupNameTableEntry(void*,int);
void MergeTwoPackedKeysAndIncrementPlacementCounters(Table*,short,short,unsigned char*);
int GameState_InterpolateProtagonistAttributePercent(unsigned char**,int);
int KrakPot_HasPendingItemPreviewLoads(unsigned char*);
void Graphics_InitializeAndActivateRenderRecord(char*);
void KrakPot_QueueAlternateAlchemyEffect(void*);
void KrakPot_GrantAlchemyResultAndConsumeIngredients(char*,char*,unsigned);
int GameState_TestFlagOrNewHalfwordMask();
void KrakPot_RebuildAvailableIngredientInventory(unsigned char*);
void RestoreLastPendingGroupedEntry(unsigned char*);
void Graphics_ConfigureDisplayPartSevenAndResetLinkedOwner(unsigned char*);
int Graphics_UpdateSelectionAndFinalizeInputResult(unsigned char*);
void QueueTwoGP2FilesBehindLoaderFence(void*);
int CompleteLoadedRecordGroup(unsigned char*,int);
void* KrakPot_FindRecipeForSelectedIngredients(char*,short*,unsigned char*,unsigned char*);
void KrakPot_QueueResultItemSprite(unsigned char*,unsigned char*);
int KrakPot_PollResultItemSpriteLoad(unsigned char*);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage_Variant6[],Main_UnknownRoleZeroInitializedStorage_Variant2[];
}
#define B(o) self[o]
#define H(o) (*(short*)(self+(o)))
#define U(o) (*(unsigned short*)(self+(o)))
#define W(o) (*(int*)(self+(o)))
#define P(o) (*(unsigned char**)(self+(o)))
#define KEY(o) (*(short*)(P(0x34)+(o)))
struct PlacementSource { char pad[0x34]; unsigned char* record; inline int HasPositive(){int result=0;if(record && *(short*)(record+0x14)>0) result=1;return result;} };
struct Section { char pad[0x94]; unsigned short flags;
 inline unsigned short Read(){return *(volatile unsigned short*)&flags;}
 inline int Test(){return (Read()&0x40)!=0;}
 inline short Percent(){return *(volatile short*)((char*)this+0x82);}
};
// Original: arm9/ov006 @ 0x0215CC70; symbol: func_ov006_0215cc70; size: 0xE80.
// Advances proportional record placement, background loads and result display states.
extern "C" void AdvanceProportionalRecordPlacement(unsigned char* self) {
 unsigned char* owner=P(0x10);
 _ZN16BackgroundLoader11GetInstanceEv();
 if(B(0x390)==0) {
  W(0x3b4)=0; B(0x387)=0;
  P(0x34)=(unsigned char*)KrakPot_FindRecipeForSelectedIngredients((char*)self,(short*)(self+0x378),self+0x38c,self+0x387);
  if(P(0x34)) {H(0x382)=GameState_InterpolateProtagonistAttributePercent((unsigned char**)(self+0x74),KEY(0));++B(0x390);}
  else {RestoreLastPendingGroupedEntry(self);RestoreLastPendingGroupedEntry(self);RestoreLastPendingGroupedEntry(self);B(0x390)=0x78;U(0x394)|=0x20;H(0x37e)=0xb;B(0x392)=0;}
 } else if(B(0x390)==1) {((void(*)(void*,int))QueueTwoGP2FilesBehindLoaderFence)(self,0);++B(0x390);}
 else if(B(0x390)==2) {
  if(W(0x428)==-1) {if(CompleteLoadedRecordGroup(self,0)) KrakPot_QueueResultItemSprite(self,self+0x17c);}
  else if(KrakPot_PollResultItemSpriteLoad(self)) {
   int flags=Equipment_GetPartyRestrictionMask((signed char)GameState_ReadProtagonistObjectIndex((GameState*)_ZN9GameState11GetInstanceEv()),self+0x17c);
   B(0x390)=5;
   if(flags&0x10) {U(0x394)|=0x20;H(0x37e)=B(0x396)+4;B(0x392)=0;++B(0x390);}
  }
 } else if(B(0x390)==3) {Graphics_ConfigureDisplayPartSevenAndResetLinkedOwner(self);++B(0x390);}
 else if(B(0x390)==4) {
  int result=Graphics_UpdateSelectionAndFinalizeInputResult(self);
  if(result!=-1) {if(result==1) ++B(0x390);}
  else {RestoreLastPendingGroupedEntry(self);RestoreLastPendingGroupedEntry(self);RestoreLastPendingGroupedEntry(self);B(0x390)=0x78;}
 } else if(B(0x390)==5) {
  if(!KrakPot_HasPendingItemPreviewLoads(owner)) {
   U(0x394)&=~0x40;
   int positive=((PlacementSource*)self)->HasPositive();
   if(positive) {
    H(0x382)=GameState_InterpolateProtagonistAttributePercent((unsigned char**)(self+0x74),KEY(0x14));
    H(0x37e)=0xd;B(0x392)=0;U(0x394)|=0x20;++B(0x390);
    unsigned random=(unsigned)_Z13NextRandomMaxP6Randomi(_Z11GetBTRandomv(),10000)/100;
    if(random<(unsigned)H(0x382)) U(0x394)|=0x40;
    ((void(*)(void*,int))QueueTwoGP2FilesBehindLoaderFence)(self,((Section*)(self+0x300))->Test());
   } else {
    TextCanvas_HideDisplayPart(P(0x14),0x10);TextCanvas_HideDisplayPart(P(0x14),0x11);TextCanvas_HideDisplayPart(P(0x14),1);TextCanvas_HideDisplayPart(P(0x14),0);
    *(unsigned short*)(P(0x10)+0xae2)|=0x10;B(0x432)=1;B(0x42d)=0;B(0x42e)=100;B(0x390)=150;
   }
  }
 } else if(B(0x390)==6) {
  if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self) && W(0x428)==-1) {if(CompleteLoadedRecordGroup(self,((Section*)(self+0x300))->Test())) KrakPot_QueueResultItemSprite(self,self+0x17c);}
  else if(W(0x428)!=-1 && KrakPot_PollResultItemSpriteLoad(self)) {U(0x394)|=0x20;H(0x37e)=B(0x396)+14;B(0x392)=0;++B(0x390);}
 } else if(B(0x390)==7) {
  if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)) {
   short message=16;
   short percent=((Section*)(self+0x300))->Percent();
   if(percent>=3 && percent<10) message=17;
   else if((percent=((Section*)(self+0x300))->Percent())>=10 && percent<=99) message=18;
   else if(((Section*)(self+0x300))->Percent()==100) message=B(0x396)+22;
   U(0x394)|=0x20;H(0x37e)=message;B(0x392)=0;++B(0x390);
  }
 } else if(B(0x390)==8) {
  if(!KrakPot_HasPendingItemPreviewLoads(owner) && ((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)) {
   ++B(0x390); short message=19;
   if(H(0x382)==100) {B(0x390)=11;message=24;}
   U(0x394)|=0x20;H(0x37e)=message;B(0x392)=0;
  }
 } else if(B(0x390)==9) {if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)){U(0x394)|=0x20;H(0x37e)=20;B(0x392)=0;++B(0x390);}}
 else if(B(0x390)==10) {if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)){U(0x394)|=0x20;H(0x37e)=21;B(0x392)=0;++B(0x390);}}
 else if(B(0x390)==11) {Graphics_ConfigureDisplayPartSevenAndResetLinkedOwner(self);++B(0x390);}
 else if(B(0x390)==12) {
  int result=Graphics_UpdateSelectionAndFinalizeInputResult(self);
  if(result!=-1) {
   if(result==1) {
    if(((Section*)(self+0x300))->Test()) MergeTwoPackedKeysAndIncrementPlacementCounters((Table*)(self+0x74),KEY(0x14),KEY(0),self+0x14c);
    else MergeTwoPackedKeysAndIncrementPlacementCounters((Table*)(self+0x74),KEY(0),-1,self+0x14c);
    KrakPot_GrantAlchemyResultAndConsumeIngredients((char*)self+0x17c,(char*)P(0x34),B(0x387));
    KrakPot_RebuildAvailableIngredientInventory(self);H(0x364)=-1;++B(0x390);
   }
  } else {
   RestoreLastPendingGroupedEntry(self);RestoreLastPendingGroupedEntry(self);RestoreLastPendingGroupedEntry(self);
   U(0x394)=(U(0x394)|0x20)&~0x40;
   TextCanvas_ShowDisplayPart(P(0x14),0);
   H(0x37e)=25;B(0x392)=0;U(0x394)|=0x20;B(0x390)=90;
  }
 } else if(B(0x390)==90) {
  if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)) {TextCanvas_ShowDisplayPart(P(0x14),0);H(0x37e)=0x24;B(0x392)=0;U(0x394)|=0x120;B(0x38f)=5;B(0x390)=0;}
 } else if(B(0x390)==13) {H(0x37e)=0x36;B(0x392)=0;TextCanvas_HideDisplayPart(P(0x14),0);++B(0x390);}
 else if(B(0x390)==14) {
  U(0x394)|=0x200;
  if(_ZN16BackgroundLoader17GetNumQueuedTasksEv(_ZN16BackgroundLoader11GetInstanceEv())<=0) {SystemState_SetFlags((unsigned*)SystemState_GetGlobalFlags(),0x80);SaveData_ResetTransferProgress(self+0x3c);++B(0x390);}
 } else if(B(0x390)==15) {
  _ZN16BackgroundLoader13AddLockGlobalEv();_ZN16BackgroundLoader21FreeAllocationsGlobalEv();
  int count=8;if(Network_IsClientSession((unsigned*)Network_GetConnectionManager())) count=20;
  if(SaveData_AdvanceStagedSaveWrite(self+0x3c,Main_UnknownRoleZeroInitializedStorage_Variant6,count,0)==1) {SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),0x80);++B(0x390);U(0x394)&=~0x200;}
  _ZN16BackgroundLoader16RemoveLockGlobalEv();
 } else if(B(0x390)==16) {H(0x37e)=0x37;B(0x392)=0;++B(0x390);}
 else if(B(0x390)==17) {if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)){H(0x37e)=0x1a;B(0x392)=0;U(0x394)|=0x20;TextCanvas_ShowDisplayPart(P(0x14),0);++B(0x390);}}
 else if(B(0x390)==18) {
  B(0x42c)=0;
  if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)) {
   TextCanvas_HideDisplayPart(P(0x14),0x10);TextCanvas_HideDisplayPart(P(0x14),0x11);TextCanvas_HideDisplayPart(P(0x14),1);TextCanvas_HideDisplayPart(P(0x14),0);
   *(unsigned short*)(P(0x10)+0xae2)|=0x10;B(0x432)=1;B(0x42d)=0;B(0x42e)=19;B(0x390)=150;
  }
 } else if(B(0x390)==19) {*(unsigned short*)(owner+0xae2)|=0x100;++B(0x390);}
 else if(B(0x390)==20) {*(unsigned short*)(owner+0xae2)|=0x200;++B(0x390);}
 else if(B(0x390)==21) {
  W(0x3b4)=1;
  unsigned char* record=(unsigned char*)Text_LookupNameTableEntry(self+0x170,H(0x1ec));
  if(record) {
   memset(*(void**)P(4),0,0x80);
   String_ReplaceBracketedNamesByRowColumnTable(*(signed char**)record,*(signed char**)P(4),1,0,0,0);
   TextCanvas_SetEntryTextPointer((char*)P(0x14),0x7f,**(int**) (self+4));
  }
  TextCanvas_EnableEntryUppercaseFormatting(P(0x14),0x7f);TextCanvas_CreateAndConfigureDisplayPart((char*)P(0x14),0x12);
  *(unsigned short*)(owner+0xae2)|=0x400; B(0x42f)=1;
  unsigned short value=0x3e;
  if(((Section*)(self+0x300))->Test()) {value=0x3f;Graphics_InitializeAndActivateRenderRecord((char*)P(0x10));}
  Bgm_RequestTemporarySequence((int)Main_UnknownRoleZeroInitializedStorage_Variant2,value);
  H(0x37e)=0xc;B(0x392)=0;++B(0x390);
 } else if(B(0x390)==22) {if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)){H(0x37e)=0x38;B(0x392)=0;++B(0x390);}}
 else if(B(0x390)==23) {
  if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)) {
   TextCanvas_ResetDisplayPartByKey(P(0x14),0x12);W(0x3b4)=0;*(unsigned short*)(owner+0xae2)&=~0x800;
   short message=0x1f;
   if(((Section*)(self+0x300))->Test()) {KrakPot_QueueAlternateAlchemyEffect(P(0x10));message=B(0x396)+0x1b;}
   U(0x394)|=0x20;H(0x37e)=message;B(0x392)=0;++B(0x390);
  }
 } else if(B(0x390)==24) {
  if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)) {
   short message=0x20;if(((Section*)(self+0x300))->Test()) message=B(0x396)+0x1d;
   U(0x394)|=0x20;H(0x37e)=message;B(0x392)=0;B(0x390)=0x78;U(0x394)&=~0x40;
  }
 } else if(B(0x390)==100) {*(unsigned short*)(owner+0xae2)|=0x100;++B(0x390);}
 else if(B(0x390)==101) {*(unsigned short*)(owner+0xae2)|=0x200;++B(0x390);}
 else if(B(0x390)==102) {
  if(P(0x34)) {
   W(0x3b4)=1;
   unsigned char* record=(unsigned char*)Text_LookupNameTableEntry(self+0x170,H(0x1ec));
   if(record) {
    memset(*(void**)P(4),0,0x80);
    String_ReplaceBracketedNamesByRowColumnTable(*(signed char**)record,*(signed char**)P(4),1,0,0,0);
    TextCanvas_SetEntryTextPointer((char*)P(0x14),0x7f,**(int**)(self+4));
   }
   TextCanvas_EnableEntryUppercaseFormatting(P(0x14),0x7f);TextCanvas_CreateAndConfigureDisplayPart((char*)P(0x14),0x12);
   MergeTwoPackedKeysAndIncrementPlacementCounters((Table*)(self+0x74),KEY(0),-1,self+0x14c);
   KrakPot_GrantAlchemyResultAndConsumeIngredients((char*)self+0x17c,(char*)P(0x34),B(0x387));KrakPot_RebuildAvailableIngredientInventory(self);H(0x364)=-1;
   B(0x42f)=1;Bgm_RequestTemporarySequence((int)Main_UnknownRoleZeroInitializedStorage_Variant2,0x3e);
   *(unsigned short*)(owner+0xae2)|=0x400;TextCanvas_HideDisplayPart(P(0x14),0);
   H(0x37e)=0xc;B(0x392)=0;++B(0x390);
  } else {
   RestoreLastPendingGroupedEntry(self);RestoreLastPendingGroupedEntry(self);RestoreLastPendingGroupedEntry(self);
   U(0x394)|=0x20;H(0x37e)=0xb;B(0x392)=0;B(0x390)=0x78;
  }
 } else if(B(0x390)==103) {if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)){H(0x37e)=0x38;B(0x392)=0;B(0x390)=0x78;}}
 else if(B(0x390)==120) {
  if(B(0x42f)) B(0x42c)=0;
  else if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)) {
   TextCanvas_ResetDisplayPartByKey(P(0x14),0x12);*(unsigned short*)(owner+0xae2)&=~0x800;TextCanvas_ShowDisplayPart(P(0x14),0);
   U(0x394)|=0x20;H(0x37e)=0x24;B(0x392)=0;U(0x394)|=0x100;B(0x38f)=5;B(0x390)=0;
  }
 } else if(B(0x390)==150) {
  unsigned short* active=(unsigned short*)(owner+0xae2);
  *(unsigned short*)(owner+0xae2)|=0x2000;
  if(++B(0x42d)>=10) {B(0x42d)=0;*active&=~0x2000;*active|=0x80;B(0x390)=B(0x42e);}
 }
}
