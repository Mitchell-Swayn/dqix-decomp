#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#define W(o) (*(int*)(self+(o)))
#define B(o) (*(unsigned char*)(self+(o)))
#define P(o) (*(char**)(self+(o)))
extern "C" char *_ZN9GameState11GetInstanceEv();
extern "C" char *TextContext_GetSharedInstance();
extern "C" void Window_SetCanvasDisplayAttribute(void*,int,int);
extern "C" void *ResourceStringTable_GetTextByKey(void*,int);
extern "C" void Church_StartConfiguredMessage(void*,void*);
extern "C" void Window_SelectCanvasById(void*,unsigned);
extern "C" void Church_RefreshPartyStatusWindow(void*);
extern "C" int UpdateSelectionControllerState(void*);
extern "C" void Church_SetWindowEmphasisAndRefreshText(void*,int,int);
extern "C" void Church_AppendTwoMessageFragments(void*,int,int);
extern "C" char *GameState_GetObjectWithFlag100(void*,int);
extern "C" char *GameObject_GetLinkedIndexedState(void*);
extern "C" void TextContext_SetNumericArgument(void*,int,int);
extern "C" void TextContext_SetNumericArgumentWidth(void*,int,int);
extern "C" void GameState_BuildTwelveByteDescriptorForPartyMember(void*,int);
extern "C" void TextContext_SetStringArgument(void*,int,void*);
extern "C" int Church_PollYesNoPrompt(void*,int);
extern "C" int TryAddAmountWith9999999Cap(void*,int);
extern "C" void Bgm_RequestTemporarySequence(void*,unsigned short);
extern "C" int Bgm_IsTemporarySequencePendingOrPlaying(void*);
extern "C" void GameObject_ReviveAndRestoreHP(void*,int,int);
extern "C" void GameObject_TestAndClearStatusMask(void*,unsigned);
extern "C" char *GameState_GetIndexList(void*);
extern "C" int Inventory_AddItemQuantityToTypeGroup(void*,unsigned,int,unsigned);
extern "C" void GameObject_SetLinkedStatAndMarkChanged(void*,int,int);
extern "C" void *Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" void Network_QueuePartyMemberLinkedStats(int,int);
extern "C" void Network_QueuePartyMemberPackedAttributes(int,int);
extern "C" char *GameResources_GetInstance();
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);
extern "C" void Field_QueuePartyMemberEquipmentRefresh(void*,int,int,int,int);
extern "C" void Field_AdvanceCommandQueueAndDispatchFront(void*);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(void*);
extern "C" void GameResources_RequestPartyPortraitRefresh(int);
extern "C" void Network_QueueCurrentPartyMemberState(int,int,int,int);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/ov003 @ 0x217f39c; symbol: data_ov003_0217f39c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0001ffffff04050607080900.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" signed char ChurchAdvancePaidMemberTreatment_UnknownRoleInitializedBytes[];
struct RecordBits {unsigned unused[2];unsigned type:4;unsigned reserved:14;unsigned available:1;unsigned rest:13;};
// Original: arm9/ov003 @ 0x0215A740; symbol: ProcessSelectedMemberFlagPayment; size: 0x7c0.
// Drives a seven-stage selected-member payment and flag-clearing confirmation flow.
extern "C" void Church_AdvancePaidMemberTreatment(char *self,int unused,int message){
 char *game=_ZN9GameState11GetInstanceEv(),*owner=TextContext_GetSharedInstance();
 if(*(int*)(owner+0x9a0)==3)owner[0x19ae]=0;
 int state=B(0x580);
 if(state==0){
 Window_SetCanvasDisplayAttribute(self+0xf4,0,0);Window_SetCanvasDisplayAttribute(self+0xf4,1,1);Window_SetCanvasDisplayAttribute(self+0xf4,2,0);
 Church_StartConfiguredMessage(self,ResourceStringTable_GetTextByKey(self+0x64,(short)message));++B(0x580);
 }
 if(state==1){if(*(int*)(owner+0x9a0)!=3)return;Window_SelectCanvasById(self+0xf4,2);B(0x585)=0;Church_RefreshPartyStatusWindow(self);B(0x59f)|=4;++B(0x580);}
 if(state==2){
 int choice=UpdateSelectionControllerState(self);if(choice==-1)return;
 if(choice==-2){Church_SetWindowEmphasisAndRefreshText(self,1,0);memset(P(0x7c),0,0x960);Church_AppendTwoMessageFragments(self,0x424,0x42e);Church_StartConfiguredMessage(self,P(0x7c));B(0x580)=6;}
 else if(choice>=0){
 Church_SetWindowEmphasisAndRefreshText(self,1,1);Church_SetWindowEmphasisAndRefreshText(self,2,1);B(0x5a1)=choice;
 char *member=GameState_GetObjectWithFlag100(game,*(unsigned char*)(self+*(signed char*)(self+0x5a1)+0x591));char *stats=GameObject_GetLinkedIndexedState(member);
 int stat=*(int*)(stats+0x950);W(0x5a4)=*(int*)(member+0x134);int valid=0;W(0x5a8)=**(int**)(member+0x130);
 switch(message){
 case 0x406:if(**(unsigned**)(member+0x130)&1){int level=*(unsigned short*)(stats+0x16c+stat*2);W(0x5ac)=((level*level+20)/20)*10;valid=1;}break;
 case 0x410:if(W(0x5a8)&2){W(0x5ac)=5;valid=1;}break;
 case 0x41a:if(W(0x5a8)&4){W(0x5ac)=*(unsigned short*)(stats+0x16c+stat*2)*30;valid=1;}break;
 }
 if(valid){TextContext_SetNumericArgument(owner,0,W(0x5ac));TextContext_SetNumericArgumentWidth(owner,0,0);memset(P(0x7c),0,0x960);Church_AppendTwoMessageFragments(self,0x425,0x42e);Church_StartConfiguredMessage(self,P(0x7c));++B(0x580);}
 else{char descriptor[12];GameState_BuildTwelveByteDescriptorForPartyMember(descriptor,*(unsigned char*)(self+*(signed char*)(self+0x5a1)+0x591));*(void**)(owner+16)=descriptor;TextContext_SetStringArgument(owner,0,P(0x5a4));memset(P(0x7c),0,0x960);Church_AppendTwoMessageFragments(self,(unsigned short)(message+2),0x42e);Church_StartConfiguredMessage(self,P(0x7c));B(0x580)=6;}
 }
 }
 if(state==3){
 if(*(int*)(owner+0x9a0)!=3)return;
 int choice=Church_PollYesNoPrompt(self,0);
 Window_SetCanvasDisplayAttribute(self+0xf4,0,0);Window_SetCanvasDisplayAttribute(self+0xf4,1,1);Window_SetCanvasDisplayAttribute(self+0xf4,2,1);
 if(choice==-1)return;
 if(choice==-2||choice==1){memset(P(0x7c),0,0x960);Church_AppendTwoMessageFragments(self,0x426,0x42e);Church_StartConfiguredMessage(self,P(0x7c));B(0x580)=6;}
 else if(choice==0){
 if(!TryAddAmountWith9999999Cap(self,-W(0x5ac))){memset(P(0x7c),0,0x960);Church_AppendTwoMessageFragments(self,0x427,0x42e);Church_StartConfiguredMessage(self,P(0x7c));B(0x580)=6;}
 else{B(0x59f)|=16;char descriptor[12];GameState_BuildTwelveByteDescriptorForPartyMember(descriptor,*(unsigned char*)(self+*(signed char*)(self+0x5a1)+0x591));*(void**)(owner+16)=descriptor;Church_StartConfiguredMessage(self,ResourceStringTable_GetTextByKey(self+0x64,(short)(message+1)));++B(0x580);}
 }
 Window_SetCanvasDisplayAttribute(self+0xf4,0,0);Window_SetCanvasDisplayAttribute(self+0xf4,1,1);Window_SetCanvasDisplayAttribute(self+0xf4,2,0);
 }
 if(state==4){if(*(int*)(owner+0x9a0)!=3)return;Bgm_RequestTemporarySequence(Main_UnknownRoleZeroInitializedStorage_Variant2,59);++B(0x580);}
 if(state==5){
 if(*(int*)(owner+0x9a0)==3)owner[0x19ae]=0;
 if(Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2))return;
 int index=*(unsigned char*)(self+*(signed char*)(self+0x5a1)+0x591);char *member=GameState_GetObjectWithFlag100(game,index);
 switch(message){
 case 0x406:GameObject_ReviveAndRestoreHP(member,0,1);if(*(unsigned*)(member+0x18c)&1)*(unsigned*)(member+0x18c)&=~1;break;
 case 0x410:GameObject_TestAndClearStatusMask(member,2);break;
 case 0x41a:{GameObject_TestAndClearStatusMask(member,4);char *inventory=GameState_GetIndexList(game);int changed=0;
 for(int slot=0;slot<11;++slot){if(slot==2||slot==3||slot==4)continue;char *entry=*(char**)(member+0x150)+0x194+(unsigned char)slot*32;
 if(entry&&((RecordBits*)entry)->available){Inventory_AddItemQuantityToTypeGroup(inventory+0x1d4,*(short*)(entry+24),1,((RecordBits*)entry)->type);GameObject_SetLinkedStatAndMarkChanged(member,ChurchAdvancePaidMemberTreatment_UnknownRoleInitializedBytes[slot],-1);changed=1;}}
 if(changed){if(Network_IsSessionActive(Network_GetConnectionManager())){Network_QueuePartyMemberLinkedStats(index,1);Network_QueuePartyMemberPackedAttributes(index,-1);}
 char *resources=GameResources_GetInstance();void *a=*(void**)(resources+0x3700),*b=*(void**)(resources+0x3704),*loader=_ZN16BackgroundLoader11GetInstanceEv();Field_QueuePartyMemberEquipmentRefresh(resources,index,1,0,0);
 while(LinkedQueue_GetFrontKindOrInvalid(a)==19){_ZN16BackgroundLoader14RemoveAllLocksEv(loader);Field_AdvanceCommandQueueAndDispatchFront(a);if(LinkedQueue_GetFrontKindOrInvalid(b)==20)Field_AdvanceCommandQueueAndDispatchFront(b);}}
 break;}
 }
 B(0x59f)&=~16;B(0x583)=1;GameResources_RequestPartyPortraitRefresh(-1);Network_QueueCurrentPartyMemberState(index,1,0,1);
 Church_StartConfiguredMessage(self,ResourceStringTable_GetTextByKey(self+0x64,0x42e));*(signed char*)(self+0x585)=-1;Church_SetWindowEmphasisAndRefreshText(self,1,0);Church_SetWindowEmphasisAndRefreshText(self,2,0);++B(0x580);
 }
 if(state==6&&*(int*)(owner+0x9a0)==3){B(0x59f)&=~4;*(signed char*)(self+0x585)=-1;Church_SetWindowEmphasisAndRefreshText(self,1,0);Church_SetWindowEmphasisAndRefreshText(self,2,0);*(signed char*)(self+0x5a1)=-1;W(0x5a4)=0;W(0x5a8)=0;W(0x5ac)=0;B(0x588)=2;B(0x580)=0;}
}
