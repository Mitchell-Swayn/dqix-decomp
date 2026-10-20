#include "globaldefs.h"
#include "std_library_functions.h"
// Original: arm9/ov017 @ 0x021a7e14; symbol: AdvancePartyRecordResourcesAndSelection.
extern "C" unsigned AllocatorUnion_AllocateFourByteAligned(...);
extern "C" unsigned Text_AppendFormatString(...);
extern "C" unsigned Text_ClearNameDescriptor(...);
extern "C" unsigned TextLayout_ResetFormattingWorkspace(...);
extern "C" unsigned ResourceStringLoader_Reset(...);
extern "C" unsigned Filesystem_ExtractLocalizedGp2FileToScratch(...);
extern "C" unsigned Filesystem_FreeCachedTableIfAllocationNeedsSpace(...);
extern "C" unsigned ZoneState2754_FindPrimaryRecordByKey(...);
extern "C" unsigned Text_LoadItemNameRecord(...);
extern "C" unsigned GameResources_GetInstance(...);
extern "C" unsigned GameState_AddItemsAndDistributeOverflow(...);
extern "C" unsigned GameState_BuildTwelveByteDescriptorForPartyMember(...);
extern "C" unsigned GameState_GetIndexList(...);
extern "C" unsigned GameState_GetObjectWithFlag100(...);
extern "C" unsigned GameState_ReadProtagonistObjectIndex(...);
extern "C" unsigned Text_InitializeNameDescriptor(...);
extern "C" unsigned Text_LookupStandardString(...);
extern "C" unsigned GameObject_DisableMovementInput(...);
extern "C" unsigned Network_GetConnectionManager(...);
extern "C" unsigned DisplayContext_GetGlobalInstance(...);
extern "C" unsigned PartyInventory_GetTotalItemQuantity(...);
extern "C" unsigned Network_TestMemberDisconnectFlag(...);
extern "C" unsigned TextContext_GetSharedInstance(...);
extern "C" unsigned TextWindow_GetChoiceResult(...);
extern "C" unsigned TextWindow_ResetGlyphBuffersAndFrameContexts(...);
extern "C" unsigned World_ResetZoneStateAndClearThreeWords(...);
extern "C" unsigned ResourceStringTable_GetTextByKey(...);
extern "C" unsigned Resource_DestroyAndResetTypeSixtyFiveRecord(...);
extern "C" unsigned GameObject_RequestMovementInputEnable(...);
extern "C" unsigned TextContext_SetNumericArgument(...);
extern "C" unsigned Network_QueueFieldActionResponse(...);
extern "C" unsigned TextContext_SetNumericArgumentWidth(...);
extern "C" unsigned _ZN13SafeAllocator11CreateTypeAEPvj(...);
extern "C" unsigned _ZN13SafeAllocator21ResetAllocatorPointerEv(...);
extern "C" unsigned _ZN13SafeAllocator5ResetEv(...);
extern "C" unsigned _ZN13SafeAllocator8AllocateEj(...);
extern "C" unsigned _ZN13ZoneState275411BuildForKeyEP13SafeAllocatorPvjs(...);
extern "C" unsigned _ZN13ZoneState27545ResetEv(...);
extern "C" unsigned _ZN13ZoneState2754C1Ev(...);
extern "C" unsigned _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" unsigned _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" unsigned _ZN16BackgroundLoader13AddLockGlobalEv(...);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(...);
extern "C" unsigned _ZN16BackgroundLoader16RemoveLockGlobalEv(...);
extern "C" unsigned _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(...);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState20GetUnknownGameObjectEv(...);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(...);
extern "C" unsigned TextWindow_StartFormattedMessage(...);
extern "C" unsigned FileCache_RestoreRomTablesIfSpaceAvailable(...);
extern "C" unsigned ResourceStringTable_CopySerializedData(...);
extern "C" unsigned ItemTrade_TickIncomingOfferTimeout(...);
#define W(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
// Original data: arm9/main @ 0x20f2a0c; symbol: data_020f2a0c.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex b62a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2a18; symbol: data_020f2a18.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 062b0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Kind{unsigned value:4;unsigned rest:28;};extern unsigned ItemTradeAdvanceIncomingOffer_UnknownRoleDataReferences_Variant2,ItemTradeAdvanceIncomingOffer_UnknownRoleDataReferences;extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[],ItemTrade_AdvanceIncomingOffer_PathDataBinMenuStrTrdGp2[],ItemTrade_AdvanceIncomingOffer_MarkupStrTrdLGNat[];
extern "C" ARM void ItemTrade_AdvanceIncomingOffer(unsigned self){
 unsigned state=_ZN9GameState11GetInstanceEv(),loader=_ZN16BackgroundLoader11GetInstanceEv(),owner=TextContext_GetSharedInstance();DisplayContext_GetGlobalInstance();GameResources_GetInstance();unsigned connection=Network_GetConnectionManager(),object=_ZN9GameState20GetUnknownGameObjectEv(state);int protagonist=GameState_ReadProtagonistObjectIndex(state);GameObject_DisableMovementInput(object,1);H(object,0xb2)=0;int flag=0;
 if(W(self,0x24)==0){Filesystem_FreeCachedTableIfAllocationNeedsSpace(0x2000);unsigned memory=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,0x2000);if(!memory){FileCache_RestoreRomTablesIfSpaceAvailable();B(self,1)=1;return;}_ZN13SafeAllocator11CreateTypeAEPvj(self+8,memory,0x2000);_ZN13SafeAllocator5ResetEv(self+8);W(self,0x1c)=_ZN13SafeAllocator8AllocateEj(self+8,24);if(!W(self,0x1c)){Resource_DestroyAndResetTypeSixtyFiveRecord(self);FileCache_RestoreRomTablesIfSpaceAvailable();B(self,1)=1;return;}W(self,0x28)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,ItemTrade_AdvanceIncomingOffer_PathDataBinMenuStrTrdGp2,ItemTrade_AdvanceIncomingOffer_MarkupStrTrdLGNat,0);W(self,0x24)=1;return;}
 else if(W(self,0x24)==1){if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x28)))return;unsigned file,size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x28),&file,&size);W(self,0x1c)=_ZN13SafeAllocator8AllocateEj(self+8,24);ResourceStringLoader_Reset(W(self,0x1c));ResourceStringTable_CopySerializedData(W(self,0x1c),self+8,file,size);_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x28));W(self,0x28)=-1;W(self,0x20)=W(owner,0x5c);W(self,0x24)=2;return;}
 else if(W(self,0x24)==2){_ZN16BackgroundLoader13AddLockGlobalEv();unsigned size;unsigned file=Filesystem_ExtractLocalizedGp2FileToScratch(ItemTradeAdvanceIncomingOffer_UnknownRoleDataReferences_Variant2,ItemTradeAdvanceIncomingOffer_UnknownRoleDataReferences,&size);W(self,0x2c)=_ZN13SafeAllocator8AllocateEj(self+8,24);_ZN13ZoneState27545ResetEv(W(self,0x2c));if(file)_ZN13ZoneState275411BuildForKeyEP13SafeAllocatorPvjs(W(self,0x2c),self+8,file,size,S(self,0x30));W(self,0x3c)=_ZN13SafeAllocator8AllocateEj(self+8,12);W(self,0x48)=_ZN13SafeAllocator8AllocateEj(self+8,64);W(self,0x4c)=_ZN13SafeAllocator8AllocateEj(self+8,64);if(W(self,0x3c)&&W(self,0x48)&&W(self,0x4c)){Text_ClearNameDescriptor(W(self,0x3c));memset((void*)W(self,0x48),0,64);memset((void*)W(self,0x4c),0,64);W(W(self,0x3c),0)=W(self,0x48);W(W(self,0x3c),4)=W(self,0x4c);Text_LoadItemNameRecord(S(self,0x30),W(self,0x3c));}_ZN16BackgroundLoader16RemoveLockGlobalEv();W(self,0x40)=_ZN13SafeAllocator8AllocateEj(self+8,12);W(self,0x44)=_ZN13SafeAllocator8AllocateEj(self+8,12);unsigned party=GameState_GetObjectWithFlag100(state,W(self,0x34));unsigned record=ZoneState2754_FindPrimaryRecordByKey(W(self,0x2c),S(self,0x30));if(!record||!party||!W(self,0x3c)||!W(self,0x48)||!W(self,0x4c)||!W(self,0x40)||!W(self,0x44)){Network_QueueFieldActionResponse(5,W(self,0x34),protagonist,S(self,0x30));W(self,0x24)=7;return;}
 Text_ClearNameDescriptor(W(self,0x40));GameState_BuildTwelveByteDescriptorForPartyMember(W(self,0x40),W(self,0x34));Text_ClearNameDescriptor(W(self,0x44));unsigned resource=Text_LookupStandardString((short)W(W(party,0x150),0x950));Text_InitializeNameDescriptor(W(self,0x44),resource,0,0,0,0,0,0,0,0,0,0);TextLayout_ResetFormattingWorkspace(owner);TextContext_SetNumericArgument(owner,0,1);TextContext_SetNumericArgumentWidth(owner,0,1);W(owner,0)=W(self,0x40);W(owner,0x18)=W(self,0x3c);W(owner,0x28)=W(self,0x44);unsigned text=W(owner,0x5c);memset((void*)text,0,0x960);Text_AppendFormatString(text,ResourceStringTable_GetTextByKey(W(self,0x1c),100));Text_AppendFormatString(text,ResourceStringTable_GetTextByKey(W(self,0x1c),120));if(PartyInventory_GetTotalItemQuantity(GameState_GetIndexList(state),S(self,0x30))==99){Text_AppendFormatString(text,ResourceStringTable_GetTextByKey(W(self,0x1c),112));H(self,0x3a)|=1;}else Text_AppendFormatString(text,ResourceStringTable_GetTextByKey(W(self,0x1c),110));W(owner,0x998)=1;TextWindow_StartFormattedMessage(owner,text,0,227);W(self,0x24)=3;return;}
 else if(W(self,0x24)==3){if(W(owner,0x9a0)!=3&&W(owner,0x9a0)!=0)return;B(owner,0x19ae)=0;unsigned choice=TextWindow_GetChoiceResult(owner);if(choice==0){if(H(self,0x3a)&1){Network_QueueFieldActionResponse(8,W(self,0x34),protagonist,S(self,0x30));H(self,0x3a)&=~1;W(self,0x24)=7;return;}Network_QueueFieldActionResponse(6,W(self,0x34),protagonist,S(self,0x30));W(self,0x24)=4;H(self,0x38)=3600;return;}if(choice==1){Network_QueueFieldActionResponse(7,W(self,0x34),protagonist,S(self,0x30));W(self,0x24)=7;}return;}
 else if(W(self,0x24)==4){B(owner,0x19ae)=0;if(Network_TestMemberDisconnectFlag(connection,0)||Network_TestMemberDisconnectFlag(connection,W(self,0x34)))flag=1;unsigned ticks=_ZNK9GameState12GetTickCountEv(state);if(!ticks)ticks=1;if(!ItemTrade_TickIncomingOfferTimeout(self,ticks))flag=1;if(flag){TextWindow_StartFormattedMessage(owner,ResourceStringTable_GetTextByKey(W(self,0x1c),113),0,227);W(self,0x24)=7;}return;}
 else if(W(self,0x24)==5){B(owner,0x19ae)=0;unsigned ticks=_ZNK9GameState12GetTickCountEv(state);if(!ticks)ticks=1;if(ItemTrade_TickIncomingOfferTimeout(self,ticks)||W(owner,0x9a0)!=3)return;if(Network_TestMemberDisconnectFlag(connection,0)||Network_TestMemberDisconnectFlag(connection,W(self,0x34))){TextWindow_StartFormattedMessage(owner,ResourceStringTable_GetTextByKey(W(self,0x1c),113),0,227);W(self,0x24)=7;return;}unsigned record=ZoneState2754_FindPrimaryRecordByKey(W(self,0x2c),S(self,0x30));unsigned char temporary[56];_ZN13SafeAllocator21ResetAllocatorPointerEv(temporary);_ZN13ZoneState2754C1Ev(temporary+20);World_ResetZoneStateAndClearThreeWords(temporary);World_ResetZoneStateAndClearThreeWords(temporary);*(unsigned*)(temporary+44)=W(self,0x2c);if((unsigned char)((Kind*)(record+8))->value==8)GameState_AddItemsAndDistributeOverflow(temporary,S(self,0x30),1,0);TextLayout_ResetFormattingWorkspace(owner);TextContext_SetNumericArgument(owner,0,1);TextContext_SetNumericArgumentWidth(owner,0,1);W(owner,0)=W(self,0x40);W(owner,0x18)=W(self,0x3c);W(owner,0x28)=W(self,0x44);TextWindow_StartFormattedMessage(owner,ResourceStringTable_GetTextByKey(W(self,0x1c),111),0,227);W(self,0x24)=7;return;}
 else if(W(self,0x24)==6){TextWindow_ResetGlyphBuffersAndFrameContexts(owner);W(owner,0x998)=1;TextWindow_StartFormattedMessage(owner,ResourceStringTable_GetTextByKey(W(self,0x1c),101),0,227);W(self,0x24)=7;return;}
 else if(W(self,0x24)==7){if(!W(owner,0x998))flag=1;if(flag){TextWindow_ResetGlyphBuffersAndFrameContexts(owner);GameObject_RequestMovementInputEnable(object);Resource_DestroyAndResetTypeSixtyFiveRecord(self);FileCache_RestoreRomTablesIfSpaceAvailable();B(self,1)=1;}}
}
