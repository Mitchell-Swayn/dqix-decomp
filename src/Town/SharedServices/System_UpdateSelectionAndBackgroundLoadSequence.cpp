#include <globaldefs.h>
ARM
extern "C" char* TextContext_GetSharedInstance(...);
extern "C" char* SystemState_GetGlobalFlags(...);
extern "C" char* Network_GetConnectionManager(...);
extern "C" char* _ZN9GameState11GetInstanceEv(...);
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(...);
extern "C" char* _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" char* GameState_GetSerializedProgressState(...);
extern "C" char* ResourceStringTable_GetTextByKey(...);
extern "C" int Network_IsSessionActive(...);
extern "C" int Network_IsClientSession(...);
extern "C" int TextWindow_GetChoiceResult(...);
extern "C" int CountAllocatorEntriesWithKindOneAndMatchingId(...);
extern "C" int Script_ExecuteFirstSatisfiedTriggerGroup(...);
extern "C" int Church_PollYesNoPrompt(...);
extern "C" int SaveData_AdvanceStagedSaveWrite(...);
extern "C" int _ZN16BackgroundLoader17GetNumQueuedTasksEv(...);
extern "C" void Window_SetCanvasDisplayAttribute(...);
extern "C" void Church_StartConfiguredMessage(...);
extern "C" void Church_AppendTwoMessageFragments(...);
extern "C" void Script_DispatchResultCommandsToWorld(...);
extern "C" void SystemState_SetFlags(...);
extern "C" void Field_QueueMemberProfileFragments(...);
extern "C" void Field_QueueMemberProfileRequest(...);
extern "C" void Bgm_RequestTemporarySequence(...);
extern "C" void SaveData_ResetTransferProgress(...);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(...);
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv(...);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv(...);
extern "C" void Bgm_CancelPendingTemporaryPlayback(...);
extern "C" void TextLayout_ResetFormattingWorkspace(...);
extern "C" void TextContext_SetStringArgument(...);
extern "C" void Text_AppendFormatString(...);
extern "C" void SystemState_ClearFlags(...);
extern "C" void Window_PopCanvasesAndResetSelection(...);
extern "C" void* memset(void*,int,unsigned);
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
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[],Main_UnknownRoleZeroInitializedStorage_Variant6[];
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define ENABLE3() do {Window_SetCanvasDisplayAttribute(self+0xf4,0,1);Window_SetCanvasDisplayAttribute(self+0xf4,1,1);Window_SetCanvasDisplayAttribute(self+0xf4,2,1);} while(0)
#define MESSAGE(key) Church_StartConfiguredMessage(self,ResourceStringTable_GetTextByKey(self+0x64,key))
// Original: arm9/ov003 @ 0x02159D0C; symbol: System_UpdateSelectionAndBackgroundLoadSequence; size: 0x8a8.
// Advances a menu selection and background-resource loading sequence using byte state 580 and connection status.
extern "C" void System_UpdateSelectionAndBackgroundLoadSequence(char* self){
 char* owner=TextContext_GetSharedInstance();char* global=SystemState_GetGlobalFlags();char* connection=Network_GetConnectionManager();if(W(owner,0x9a0)==3)B(owner,0x19ae)=0;int state=B(self,0x580);
 if(state==0){if(B(self,0x5b4)){if(B(self,0x59d))return;memset(P(self,0x7c),0,2400);Church_AppendTwoMessageFragments(self,1000,100);Church_StartConfiguredMessage(self,P(self,0x7c));B(self,0x5b3)=5;B(self,0x580)=2;return;}
 ENABLE3();int key=0x3f2;if(Network_IsSessionActive(connection)&&Network_IsClientSession(connection))key+=8;MESSAGE(key);++B(self,0x580);
 }
 if(state==1){if(W(owner,0x9a0)!=3)return;int result=Church_PollYesNoPrompt(self,0);if(result==-1)return;if(result==-2||result==1){memset(P(self,0x7c),0,2400);Church_AppendTwoMessageFragments(self,0x3f4,0x3f5);Church_StartConfiguredMessage(self,P(self,0x7c));B(self,0x580)=4;}else if(result==0)++B(self,0x580);ENABLE3();}
 if(state==2){if(B(self,0x5b4)){if(!W(owner,0x998)){B(self,0x588)=11;B(self,0x580)=0;return;}int previous=B(self,0x5b3);unsigned char mode=W(owner,0x9a0);int active=1;if(previous==6&&mode==5){if(!TextWindow_GetChoiceResult(owner))active=0;}B(self,0x5b3)=W(owner,0x9a0);if(active)return;}
 B(self,0x59f)|=16;unsigned output[13];if(Script_ExecuteFirstSatisfiedTriggerGroup(GameState_GetSerializedProgressState(),12,output))Script_DispatchResultCommandsToWorld(output);if(!B(self,0x5b4)){MESSAGE(100);}SystemState_SetFlags(global,128);W(self,0x598)=15;if(Network_IsSessionActive(connection)){Field_QueueMemberProfileFragments(-1,1,1,2);Field_QueueMemberProfileRequest(-1,1,0);}B(self,0x580)=100;
 }
 if(state==100){if(Network_IsSessionActive(connection)){char* game=_ZN9GameState11GetInstanceEv();char* record=game+0x74c0;for(int i=0;i<3;++i,record+=10){if(*(signed char*)(record+6)>=4){if(B(record,7)||B(record,8))return;if(*(signed char*)(record+9)>=0)return;}}}Bgm_RequestTemporarySequence(Main_UnknownRoleZeroInitializedStorage_Variant2,60);B(self,0x59f)|=2;++B(self,0x580);}
 if(state==101){if(W(owner,0x9a0)!=3)return;if(!CountAllocatorEntriesWithKindOneAndMatchingId(60))return;if(W(owner,0x9a0)==3)B(owner,0x19ae)=0;if(!B(self,0x59c))B(self,0x59c)=1;SaveData_ResetTransferProgress(self+0x5b8);B(self,0x580)=102;}
 if(state==102){unsigned flags=1;if(Network_IsClientSession(connection))flags|=20;_ZN16BackgroundLoader13AddLockGlobalEv();_ZN16BackgroundLoader21FreeAllocationsGlobalEv();if(SaveData_AdvanceStagedSaveWrite(self+0x5b8,Main_UnknownRoleZeroInitializedStorage_Variant6,flags,0)==1)B(self,0x580)=3;_ZN16BackgroundLoader16RemoveLockGlobalEv();}
 if(state==3){if(W(owner,0x9a0)==3)B(owner,0x19ae)=0;Bgm_CancelPendingTemporaryPlayback(Main_UnknownRoleZeroInitializedStorage_Variant2);if(_ZN16BackgroundLoader17GetNumQueuedTasksEv(_ZN16BackgroundLoader11GetInstanceEv())>0)return;B(self,0x59f)&=~2;memset(P(self,0x7c),0,2400);if(B(self,0x5b4)){char* object=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());TextLayout_ResetFormattingWorkspace(owner);TextContext_SetStringArgument(owner,0,P(object,0x134));Text_AppendFormatString(P(self,0x7c),ResourceStringTable_GetTextByKey(self+0x64,0x3f3));}else Church_AppendTwoMessageFragments(self,0x3f3,0x3f5);Church_StartConfiguredMessage(self,P(self,0x7c));SystemState_ClearFlags(global,128);B(self,0x59f)&=~16;if(B(self,0x5b4)){B(self,0x580)=7;return;}++B(self,0x580);}
 if(state==4){if(W(owner,0x9a0)!=3)return;int result=Church_PollYesNoPrompt(self,0);if(result==-1)return;if(result==-2||result==1){if(!B(self,0x59c)){ENABLE3();MESSAGE(0x3f7);++B(self,0x580);return;}if(Network_IsSessionActive(connection)){ENABLE3();MESSAGE(0x3f9);B(self,0x580)=6;return;}Window_PopCanvasesAndResetSelection(self+0xf4,1);MESSAGE(0x3f6);B(self,0x59f)|=16;B(self,0x588)=9;B(self,0x580)=0;return;}if(result==0){Window_PopCanvasesAndResetSelection(self+0xf4,1);MESSAGE(0x442);B(self,0x580)=7;}}
 if(state==5){if(W(owner,0x9a0)!=3)return;int result=Church_PollYesNoPrompt(self,1);if(result==-1)return;if(result==-2||result==1){ENABLE3();MESSAGE(0x3f8);B(self,0x580)=1;return;}if(result==0){if(Network_IsSessionActive(connection)){ENABLE3();MESSAGE(0x3f9);B(self,0x580)=6;return;}Window_PopCanvasesAndResetSelection(self+0xf4,1);MESSAGE(0x3f6);B(self,0x59f)|=16;B(self,0x588)=9;B(self,0x580)=0;return;}}
 if(state==6){if(W(owner,0x9a0)!=3)return;int result=Church_PollYesNoPrompt(self,1);if(result==-1)return;if(result==-2||result==1){Window_PopCanvasesAndResetSelection(self+0xf4,1);MESSAGE(0x442);B(self,0x580)=7;return;}if(result==0){Window_PopCanvasesAndResetSelection(self+0xf4,1);MESSAGE(0x3f6);B(self,0x59f)|=16;B(self,0x588)=9;B(self,0x580)=0;return;}}
 if(state==7&&!W(owner,0x998)){B(self,0x588)=11;B(self,0x580)=0;}
}
