#include <globaldefs.h>
ARM
extern "C" int TextCanvas_ShowDisplayPart(...);
extern "C" int SaveData_ResetTransferProgress(...);
extern "C" int Text_LookupNameTableEntry(...);
extern "C" int KrakPot_GrantAlchemyResultAndConsumeIngredients(...);
extern "C" int GameState_InterpolateProtagonistAttributePercent(...);
extern "C" int GameState_TestFlagOrNewHalfwordMask(...);
extern "C" int SystemState_GetGlobalFlags(...);
extern "C" int Graphics_ConfigureDisplayPartSevenAndResetLinkedOwner(...);
extern "C" int Graphics_InitializeAndActivateRenderRecord(...);
extern "C" int Graphics_ToggleFourTextureEntries(...);
extern "C" int QueueTwoGP2FilesBehindLoaderFence(...);
extern "C" int Graphics_UpdateSelectionAndFinalizeInputResult(...);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(...);
extern "C" int Network_GetConnectionManager(...);
extern "C" int TextCanvas_SetGroupPalette(...);
extern "C" int TextCanvas_HideDisplayPart(...);
extern "C" int KrakPot_QueueAlternateAlchemyEffect(...);
extern "C" int Bgm_RequestTemporarySequence(...);
extern "C" int SystemState_ClearFlags(...);
extern "C" int TextCanvas_ResetDisplayPartByKey(...);
extern "C" int KrakPot_QueueResultItemSprite(...);
extern "C" int TextCanvas_SetEntryTextPointer(...);
extern "C" int TextCanvas_EnableEntryUppercaseFormatting(...);
extern "C" int SystemState_SetFlags(...);
extern "C" int String_ReplaceBracketedNamesByRowColumnTable(...);
extern "C" int Network_IsClientSession(...);
extern "C" int _Z11GetBTRandomv(...);
extern "C" int _Z13NextRandomMaxP6Randomi(...);
extern "C" int _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" int _ZN16BackgroundLoader13AddLockGlobalEv(...);
extern "C" int _ZN16BackgroundLoader16RemoveLockGlobalEv(...);
extern "C" int _ZN16BackgroundLoader17GetNumQueuedTasksEv(...);
extern "C" int _ZN16BackgroundLoader21FreeAllocationsGlobalEv(...);
extern "C" int SaveData_AdvanceStagedSaveWrite(...);
extern "C" int MergeTwoPackedKeysAndIncrementPlacementCounters(...);
extern "C" int KrakPot_RebuildAvailableIngredientInventory(...);
extern "C" int CompleteLoadedRecordGroup(...);
extern "C" int KrakPot_PollResultItemSpriteLoad(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov006 @ 0x0215E69C; symbol: AdvanceRandomizedPlacementAndDisplayTransition.
extern "C" void KrakPot_AdvanceRecipeAlchemyResult(char*self){
struct Section{char pad[0x94];unsigned short flags;inline unsigned short Read(){return *(volatile unsigned short*)&flags;}inline void Write(unsigned short value){flags=value;}inline void Set(unsigned short m){Write(Read()|m);}inline void Clear(unsigned short m){Write(Read()&~m);}inline int Test(){return (Read()&64)!=0;}inline short Percent(){return *(short*)((char*)this+0x82);}};struct OwnerSection{char pad[0xe2];unsigned short flags;inline unsigned short Read(){return *(volatile unsigned short*)&flags;}inline void Write(unsigned short value){flags=value;}inline void Set(unsigned short m){Write(Read()|m);}inline void Clear(unsigned short m){Write(Read()&~m);}};char*owner=P(self,16);_ZN16BackgroundLoader11GetInstanceEv();
if(B(self,0x390)==0){W(self,0x3b4)=0;if(GameState_TestFlagOrNewHalfwordMask(self)){TextCanvas_ResetDisplayPartByKey(P(self,20),0);TextCanvas_ResetDisplayPartByKey(P(self,20),1);TextCanvas_SetGroupPalette(P(self,20),9,0);((Section*)(self+0x300))->Clear(64);if(S(P(self,52),20)>=0){H(self+0x300,0x82)=GameState_InterpolateProtagonistAttributePercent((unsigned char**)(self+116),S(P(self,52),20));H(self+0x300,0x7e)=13;B(self,0x392)=0;((Section*)(self+0x300))->Set(32);B(self,0x390)++;unsigned random=(unsigned)_Z13NextRandomMaxP6Randomi(_Z11GetBTRandomv(),10000)/100;if(random<(unsigned)((Section*)(self+0x300))->Percent())((Section*)(self+0x300))->Set(64);QueueTwoGP2FilesBehindLoaderFence(self,((Section*)(self+0x300))->Test());}else{((OwnerSection*)(owner+0xa00))->Clear(64);B(self,0x42d)=0;B(self,0x42e)=100;B(self,0x390)=150;Graphics_ToggleFourTextureEntries(self,P(self,20),0,self+0x397);}}}
else if(B(self,0x390)==1){if(GameState_TestFlagOrNewHalfwordMask(self)&&W(self,0x428)==-1){if(CompleteLoadedRecordGroup(self,((Section*)(self+0x300))->Test()))KrakPot_QueueResultItemSprite(self,self+0x17c);}else if(W(self,0x428)!=-1&&KrakPot_PollResultItemSpriteLoad(self)){H(self+0x300,0x7e)=B(self,0x396)+14;B(self,0x392)=0;B(self,0x390)++;}}
else if(B(self,0x390)==2){if(GameState_TestFlagOrNewHalfwordMask(self)){short message=16;short percent=(*(volatile short*)(self+0x382));if(percent>=3&&percent<10)message=17;else if((percent=(*(volatile short*)(self+0x382)))>=10&&percent<=99)message=18;else if((*(volatile short*)(self+0x382))==100)message=B(self,0x396)+22;H(self+0x300,0x7e)=message;B(self,0x392)=0;B(self,0x390)++;}}
else if(B(self,0x390)==3){if(GameState_TestFlagOrNewHalfwordMask(self)){B(self,0x390)++;short message=19;if(((Section*)(self+0x300))->Percent()==100){B(self,0x390)=6;message=24;}H(self+0x300,0x7e)=message;B(self,0x392)=0;}}
else if(B(self,0x390)==4){if(GameState_TestFlagOrNewHalfwordMask(self)){H(self+0x300,0x7e)=20;B(self,0x392)=0;B(self,0x390)++;}}
else if(B(self,0x390)==5){if(GameState_TestFlagOrNewHalfwordMask(self)){H(self+0x300,0x7e)=21;B(self,0x392)=0;B(self,0x390)++;}}
else if(B(self,0x390)==6){Graphics_ConfigureDisplayPartSevenAndResetLinkedOwner(self);B(self,0x390)++;}
else if(B(self,0x390)==7){int result=Graphics_UpdateSelectionAndFinalizeInputResult(self);if(result!=-1){if(result==1){if(((Section*)(self+0x300))->Test())MergeTwoPackedKeysAndIncrementPlacementCounters(self+116,S(P(self,52),20),S(P(self,52),0),self+332);else MergeTwoPackedKeysAndIncrementPlacementCounters(self+116,S(P(self,52),0),-1,self+332);KrakPot_GrantAlchemyResultAndConsumeIngredients(self+380,P(self,52),B(self,0x387));unsigned char saved0=B(self,0x388),saved1=B(self,0x389);KrakPot_RebuildAvailableIngredientInventory(self);B(self,0x388)=saved0;B(self,0x389)=saved1;B(self,0x390)++;}}else{H(self+0x300,0x7e)=25;B(self,0x392)=0;H(self+0x300,0x94)=(H(self+0x300,0x94)|32)&~64;B(self,0x390)=90;}}
else if(B(self,0x390)==90){if(GameState_TestFlagOrNewHalfwordMask(self)){TextCanvas_ShowDisplayPart(P(self,20),0);H(self+0x300,0x7e)=1;B(self,0x392)=0;((Section*)(self+0x300))->Set(32);B(self,0x390)=121;}}
else if(B(self,0x390)==8){if(_ZN16BackgroundLoader17GetNumQueuedTasksEv(_ZN16BackgroundLoader11GetInstanceEv())<=0)B(self,0x390)++;}
else if(B(self,0x390)==9){H(self+0x300,0x7e)=54;B(self,0x392)=0;TextCanvas_HideDisplayPart(P(self,20),0);B(self,0x390)++;}
else if(B(self,0x390)==10){((Section*)(self+0x300))->Set(512);if(_ZN16BackgroundLoader17GetNumQueuedTasksEv(_ZN16BackgroundLoader11GetInstanceEv())<=0){SystemState_SetFlags(SystemState_GetGlobalFlags(),128);SaveData_ResetTransferProgress(self+60);B(self,0x390)++;}}
else if(B(self,0x390)==11){_ZN16BackgroundLoader13AddLockGlobalEv();_ZN16BackgroundLoader21FreeAllocationsGlobalEv();int count=8;if(Network_IsClientSession(Network_GetConnectionManager()))count=20;if(SaveData_AdvanceStagedSaveWrite(self+60,Main_UnknownRoleZeroInitializedStorage_Variant6,count,0)==1){SystemState_ClearFlags(SystemState_GetGlobalFlags(),128);B(self,0x390)++;((Section*)(self+0x300))->Clear(512);}_ZN16BackgroundLoader16RemoveLockGlobalEv();}
else if(B(self,0x390)==12){H(self+0x300,0x7e)=55;B(self,0x392)=0;B(self,0x390)++;}
else if(B(self,0x390)==13){if(GameState_TestFlagOrNewHalfwordMask(self)){H(self+0x300,0x7e)=26;B(self,0x392)=0;((Section*)(self+0x300))->Set(32);B(self,0x390)++;}}
else if(B(self,0x390)==14){B(self,0x42c)=0;if(GameState_TestFlagOrNewHalfwordMask(self)){Graphics_ToggleFourTextureEntries(self,P(self,20),0,self+0x397);((OwnerSection*)(owner+0xa00))->Clear(64);B(self,0x42d)=0;B(self,0x42e)=15;B(self,0x390)=150;}}
else if(B(self,0x390)==15){((OwnerSection*)(owner+0xa00))->Set(256);B(self,0x390)++;}
else if(B(self,0x390)==16){((OwnerSection*)(owner+0xa00))->Set(512);B(self,0x390)++;}
else if(B(self,0x390)==17){W(self,0x3b4)=1;char*record=C(Text_LookupNameTableEntry(self+368,S(self+256,236)));if(record){memset(P(P(self,4),0),0,128);String_ReplaceBracketedNamesByRowColumnTable(P(record,0),P(P(self,4),0),1,0,0,0);TextCanvas_SetEntryTextPointer(P(self,20),127,P(P(self,4),0));}TextCanvas_EnableEntryUppercaseFormatting(P(self,20),127);TextCanvas_CreateAndConfigureDisplayPart(P(self,20),18);((OwnerSection*)(owner+0xa00))->Set(1024);B(self,0x42f)=1;int value=62;if(((Section*)(self+0x300))->Test()){value=63;Graphics_InitializeAndActivateRenderRecord(P(self,16));}Bgm_RequestTemporarySequence(Main_UnknownRoleZeroInitializedStorage_Variant2,value);TextCanvas_HideDisplayPart(P(self,20),0);H(self+0x300,0x7e)=12;B(self,0x392)=0;B(self,0x390)++;}
else if(B(self,0x390)==18){if(GameState_TestFlagOrNewHalfwordMask(self)){if(((Section*)(self+0x300))->Test())KrakPot_QueueAlternateAlchemyEffect(owner);H(self+0x300,0x7e)=56;B(self,0x392)=0;B(self,0x390)++;}}
else if(B(self,0x390)==19){if(GameState_TestFlagOrNewHalfwordMask(self)){TextCanvas_ResetDisplayPartByKey(P(self,20),18);W(self,0x3b4)=0;((OwnerSection*)(owner+0xa00))->Clear(2048);short message=31;if(((Section*)(self+0x300))->Test())message=B(self,0x396)+27;((Section*)(self+0x300))->Set(32);H(self+0x300,0x7e)=message;B(self,0x392)=0;B(self,0x390)++;}}
else if(B(self,0x390)==20){if(GameState_TestFlagOrNewHalfwordMask(self)){short message=32;if(((Section*)(self+0x300))->Test())message=B(self,0x396)+29;H(self+0x300,0x7e)=message;B(self,0x392)=0;B(self,0x390)=120;}}
else if(B(self,0x390)==100){((OwnerSection*)(owner+0xa00))->Set(256);B(self,0x390)++;}
else if(B(self,0x390)==101){((OwnerSection*)(owner+0xa00))->Set(512);B(self,0x390)++;}
else if(B(self,0x390)==102){MergeTwoPackedKeysAndIncrementPlacementCounters(self+116,S(P(self,52),0),-1,self+332);KrakPot_GrantAlchemyResultAndConsumeIngredients(self+380,P(self,52),B(self,0x387));unsigned char saved0=B(self,0x388),saved1=B(self,0x389);KrakPot_RebuildAvailableIngredientInventory(self);B(self,0x388)=saved0;B(self,0x389)=saved1;W(self,0x3b4)=1;char*record=C(Text_LookupNameTableEntry(self+368,S(self+256,236)));if(record){memset(P(P(self,4),0),0,128);String_ReplaceBracketedNamesByRowColumnTable(P(record,0),P(P(self,4),0),1,0,0,0);TextCanvas_SetEntryTextPointer(P(self,20),127,P(P(self,4),0));}TextCanvas_EnableEntryUppercaseFormatting(P(self,20),127);TextCanvas_CreateAndConfigureDisplayPart(P(self,20),18);((OwnerSection*)(owner+0xa00))->Set(1024);B(self,0x42f)=1;Bgm_RequestTemporarySequence(Main_UnknownRoleZeroInitializedStorage_Variant2,62);H(self+0x300,0x7e)=12;B(self,0x392)=0;B(self,0x390)++;}
else if(B(self,0x390)==103){if(GameState_TestFlagOrNewHalfwordMask(self)){H(self+0x300,0x7e)=56;B(self,0x392)=0;B(self,0x390)=120;}}
else if(B(self,0x390)==120){if(B(self,0x42f))B(self,0x42c)=0;else{char*state=owner+0x12a0;if((!state||!B(state,20))&&GameState_TestFlagOrNewHalfwordMask(self)){TextCanvas_ResetDisplayPartByKey(P(self,20),18);W(self,0x3b4)=0;((OwnerSection*)(owner+0xa00))->Clear(2048);H(self+0x300,0x7e)=1;B(self,0x392)=0;((Section*)(self+0x300))->Set(32);B(self,0x390)++;}}}
else if(B(self,0x390)==121){if(GameState_TestFlagOrNewHalfwordMask(self)){Graphics_ToggleFourTextureEntries(self,P(self,20),1,self+0x397);TextCanvas_ResetDisplayPartByKey(P(self,20),0);TextCanvas_ResetDisplayPartByKey(P(self,20),1);B(self,0x38f)=10;B(self,0x390)=0;}}
else if(B(self,0x390)==150){unsigned short*active=(unsigned short*)(owner+0xae2);((OwnerSection*)(owner+0xa00))->Set(8192);if(++B(self,0x42d)>=10){B(self,0x42d)=0;*active&=~8192;*active|=128;B(self,0x390)=B(self,0x42e);}}

}
