#include <globaldefs.h>
ARM
struct Entry {char pad[8];unsigned amount:8,rest:24;};
extern "C" {
void* ReadGlobalValueAt02153637();void DispatchTwoValuesWithActiveByteMode(int,int);void* _ZN9GameState11GetInstanceEv();unsigned ReadWordFieldAtOffset1C();void* Object_GetGlobalConnectionState();void* ReadGlobalAt02108E10();char* TryTransformFirstOrSecondEmbeddedRecord(void*,void*);
void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*);void* ClearMemoryRange12_Main020E46C4(void*);
char* GameState_GetObjectWithFlag100(void*,int);void CopyBoundedNameToIndexedSlot(void*,int,const char*);void GameState_BuildTwelveByteDescriptorForPartyMember(void*,int);
char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);int Object_SubtractAmountWithConditionalScaling(void*,int);int IsFirstWordNonzero(void*);void QueueCharacterStatePacketTypeFour(int,int,int,int);
void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,void*,void*,int,int,unsigned);int AppendFormatText(char*,const char*);void SetOneOfSixteenWordFieldsAtOffset8B0(unsigned*,int,unsigned);
char* _ZN9GameState20GetUnknownGameObjectEv(void*);int GameState_ReadOffset5721ByteBufferLength(void*);
}
#define ACT (*(short*)(self+0x1c26))
#define TXT (*(char**)(self+0x1bd0))
// Original: arm9/ov002 @ 0x0215A0A4; symbol: func_ov002_0215a0a4; size: 0x5B4.
extern "C" void Text_FormatCharacterCommandFeedback(char* self,unsigned char* command,int success){
 DispatchTwoValuesWithActiveByteMode((int)ReadGlobalValueAt02153637(),1);
 char* output;
 void* state=_ZN9GameState11GetInstanceEv();signed char* formatter=(signed char*)ReadWordFieldAtOffset1C();void* connection=Object_GetGlobalConnectionState();
 char* entry=TryTransformFirstOrSecondEmbeddedRecord(ReadGlobalAt02108E10(),(void*)ACT);if(!entry)return;
 memset(TXT,0,0x960);memset(*(void**)(self+0x1bd4),0,0x960);ClearOwnerBuffersAndResetSignedByteSentinels(formatter);
 output=TXT;
 ClearMemoryRange12_Main020E46C4(self+8);ClearMemoryRange12_Main020E46C4(self+0x14);
 char* actor=GameState_GetObjectWithFlag100(state,*(signed char*)(command+2));
 if(actor){CopyBoundedNameToIndexedSlot(formatter,0,*(char**)(actor+0x134));GameState_BuildTwelveByteDescriptorForPartyMember(self+8,*(signed char*)(command+2));*(void**)formatter=self+8;}
 CopyBoundedNameToIndexedSlot(formatter,1,*(char**)entry);
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
 if(accepted){Object_SubtractAmountWithConditionalScaling(actor,((Entry*)entry)->amount);if(IsFirstWordNonzero(connection))QueueCharacterStatePacketTypeFour(*(signed char*)(self+0x1c20),0,0,1);}
 return;
 }
 if(ACT!=0x22&&ACT!=0x310)return;
 if(success){
 void* format=ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)0x232d);
 ProcessSixStagesUsingSharedWordScratchBuffer(formatter,12,format,output+0x860,0xe3,0,1);AppendFormatText(TXT,output+0x860);
 unsigned char* outcomes=command+8;
 for(int i=0;i<command[3];i++){
 int message;if(outcomes[i*6]==3)message=0x232c;else message=0x233a;
 if(message<0)continue;
 char* target=GameState_GetObjectWithFlag100(state,*(signed char*)(command+4+i));if(!target)continue;
 ClearOwnerBuffersAndResetSignedByteSentinels(formatter);char* targetName=*(char* volatile*)(target+0x134);CopyBoundedNameToIndexedSlot(formatter,2,targetName);GameState_BuildTwelveByteDescriptorForPartyMember(self+0x14,*(signed char*)(command+4+i));*(void**)(formatter+0x10)=self+0x14;
 SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)formatter,9,*(short*)(target+4));
 void* format=ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)message);
 ProcessSixStagesUsingSharedWordScratchBuffer(formatter,12,format,output+0x860,0xe3,0,1);
 AppendFormatText(TXT,(char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)8));AppendFormatText(TXT,output+0x860);
 }
 Object_SubtractAmountWithConditionalScaling(actor,((Entry*)entry)->amount);if(IsFirstWordNonzero(connection))QueueCharacterStatePacketTypeFour(*(signed char*)(self+0x1c20),0,0,1);
 }else{
 char* target=_ZN9GameState20GetUnknownGameObjectEv(state);
 if(target){CopyBoundedNameToIndexedSlot(formatter,2,*(char**)(target+0x134));GameState_BuildTwelveByteDescriptorForPartyMember(self+0x14,*(short*)(target+4));*(void**)(formatter+0x10)=self+0x14;}
 AppendFormatText(output+0x860,(char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)0x2333));
 AppendFormatText(output+0x860,(char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)8));
 if(GameState_ReadOffset5721ByteBufferLength(state)==1)AppendFormatText(output+0x860,(char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)0x2334));else AppendFormatText(output+0x860,(char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)0x2335));
 ProcessSixStagesUsingSharedWordScratchBuffer(formatter,12,output+0x860,TXT,0xe3,0,1);
 }
 self[0x1c31]=1;memcpy(*(void**)(self+0x1bd4),TXT,0x960);*(short*)(self+0x2488)=-1;self[0x248a]=0;
}
