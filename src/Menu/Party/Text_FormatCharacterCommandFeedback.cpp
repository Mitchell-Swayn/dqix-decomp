#include <globaldefs.h>
ARM
struct Entry {char pad[8];unsigned amount:8,rest:24;};
extern "C" {
void* NetworkOwnership_GetRegistry();void NetworkOwnership_ReleaseForLocalPeer(int,int);void* _ZN9GameState11GetInstanceEv();unsigned TextContext_GetSharedInstance();void* Network_GetConnectionManager();void* ActionData_GetGlobalTables();void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);void TextLayout_ResetFormattingWorkspace(signed char*);void* Text_ClearNameDescriptor(void*);
char* GameState_GetObjectWithFlag100(void*,int);void TextContext_SetStringArgument(void*,int,const char*);void GameState_BuildTwelveByteDescriptorForPartyMember(void*,int);
char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);int Object_SubtractAmountWithConditionalScaling(void*,int);int Network_IsSessionActive(void*);void Network_QueueCurrentPartyMemberState(int,int,int,int);
void* ResourceStringTable_GetTextByKey(void*,void*);void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);int Text_AppendFormatString(char*,const char*);void TextContext_SetNumericArgument(unsigned*,int,unsigned);
char* _ZN9GameState20GetUnknownGameObjectEv(void*);int GameState_GetActivePartySlotCount(void*);
}
#define ACT (*(short*)(self+0x1c26))
#define TXT (*(char**)(self+0x1bd0))
// Original: arm9/ov002 @ 0x0215A0A4; symbol: func_ov002_0215a0a4; size: 0x5B4.
extern "C" void Text_FormatCharacterCommandFeedback(char* self,unsigned char* command,int success){
 NetworkOwnership_ReleaseForLocalPeer((int)NetworkOwnership_GetRegistry(),1);
 char* output;
 void* state=_ZN9GameState11GetInstanceEv();signed char* formatter=(signed char*)TextContext_GetSharedInstance();void* connection=Network_GetConnectionManager();
 char* entry=(char*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(),ACT);if(!entry)return;
 memset(TXT,0,0x960);memset(*(void**)(self+0x1bd4),0,0x960);TextLayout_ResetFormattingWorkspace(formatter);
 output=TXT;
 Text_ClearNameDescriptor(self+8);Text_ClearNameDescriptor(self+0x14);
 char* actor=GameState_GetObjectWithFlag100(state,*(signed char*)(command+2));
 if(actor){TextContext_SetStringArgument(formatter,0,*(char**)(actor+0x134));GameState_BuildTwelveByteDescriptorForPartyMember(self+8,*(signed char*)(command+2));*(void**)formatter=self+8;}
 TextContext_SetStringArgument(formatter,1,*(char**)entry);
 if(ACT==0x1e||ACT==0x1f||ACT==0x20||ACT==0x21||ACT==0x23||ACT==0x26||ACT==0x27){
 self[0x248a]=1;*(short*)(self+0x1c28)=0x232d;*(short*)(self+0x1c2a)=-1;
 char* target=_ZN9GameState21GetPartyMemberByIndexEi(state,*(signed char*)(self+0x1c21));int accepted=0;
 if(success&&target){
 if(ACT==0x1e||ACT==0x1f||ACT==0x20||ACT==0x21){*(short*)(self+0x2488)=0x232c;accepted=1;}
 else if(ACT==0x23){*(short*)(self+0x2488)=0x794b;accepted=1;}
 else if(ACT==0x27||ACT==0x26){*(short*)(self+0x2488)=0x2336;accepted=1;}
 }else if(!target){*(short*)(self+0x1c28)=0x232d;*(short*)(self+0x2488)=0x232b;}
 else if(**(unsigned**)(target+0x130)&1){if(ACT==0x26){*(short*)(self+0x2488)=0x2337;accepted=1;}else *(short*)(self+0x2488)=0x232b;}
 else if(command[8]==1){*(short*)(self+0x1c28)=0x232d;*(short*)(self+0x2488)=0x232b;}
 else{*(short*)(self+0x1c28)=0x2333;*(short*)(self+0x2488)=0x2334;}
 *(int*)(self+0x1bb8)=0x26;*(int*)(self+0x1bbc)=0x11;*(int*)(self+0x1bc0)=0;
 if(accepted){Object_SubtractAmountWithConditionalScaling(actor,((Entry*)entry)->amount);if(Network_IsSessionActive(connection))Network_QueueCurrentPartyMemberState(*(signed char*)(self+0x1c20),0,0,1);}
 return;
 }
 if(ACT!=0x22&&ACT!=0x310)return;
 if(success){
 void* format=ResourceStringTable_GetTextByKey(self+0x20,(void*)0x232d);
 TextMarkup_ExpandAndWrapText(formatter,12,format,output+0x860,0xe3,0,1);Text_AppendFormatString(TXT,output+0x860);
 unsigned char* outcomes=command+8;
 for(int i=0;i<command[3];i++){
 int message;if(outcomes[i*6]==3)message=0x232c;else message=0x233a;
 if(message<0)continue;
 char* target=GameState_GetObjectWithFlag100(state,*(signed char*)(command+4+i));if(!target)continue;
 TextLayout_ResetFormattingWorkspace(formatter);char* targetName=*(char* volatile*)(target+0x134);TextContext_SetStringArgument(formatter,2,targetName);GameState_BuildTwelveByteDescriptorForPartyMember(self+0x14,*(signed char*)(command+4+i));*(void**)(formatter+0x10)=self+0x14;
 TextContext_SetNumericArgument((unsigned*)formatter,9,*(short*)(target+4));
 void* format=ResourceStringTable_GetTextByKey(self+0x20,(void*)message);
 TextMarkup_ExpandAndWrapText(formatter,12,format,output+0x860,0xe3,0,1);
 Text_AppendFormatString(TXT,(char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)8));Text_AppendFormatString(TXT,output+0x860);
 }
 Object_SubtractAmountWithConditionalScaling(actor,((Entry*)entry)->amount);if(Network_IsSessionActive(connection))Network_QueueCurrentPartyMemberState(*(signed char*)(self+0x1c20),0,0,1);
 }else{
 char* target=_ZN9GameState20GetUnknownGameObjectEv(state);
 if(target){TextContext_SetStringArgument(formatter,2,*(char**)(target+0x134));GameState_BuildTwelveByteDescriptorForPartyMember(self+0x14,*(short*)(target+4));*(void**)(formatter+0x10)=self+0x14;}
 Text_AppendFormatString(output+0x860,(char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)0x2333));
 Text_AppendFormatString(output+0x860,(char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)8));
 if(GameState_GetActivePartySlotCount(state)==1)Text_AppendFormatString(output+0x860,(char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)0x2334));else Text_AppendFormatString(output+0x860,(char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)0x2335));
 TextMarkup_ExpandAndWrapText(formatter,12,output+0x860,TXT,0xe3,0,1);
 }
 self[0x1c31]=1;memcpy(*(void**)(self+0x1bd4),TXT,0x960);*(short*)(self+0x2488)=-1;self[0x248a]=0;
}
