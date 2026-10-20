#include <globaldefs.h>
ARM
extern "C" char* strcpy(char*,const char*);
extern "C" void __clear(void*,unsigned);
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" void Field_UpdateMemberJoinNameAndCache(unsigned char*,int,const char*);
extern "C" void Resource_UpdateIndexedStateFlag(unsigned char*,unsigned);
extern "C" void Field_RemoveRemoteMemberAndRefreshParty(char*,int);
extern "C" void Field_AcknowledgeMemberJoinRoster(void*,unsigned);
extern "C" void Field_AcknowledgeMemberJoinPreparation(unsigned char*,unsigned);
extern "C" void Field_MarkJoinPreparationComplete(void*);
extern "C" void Field_RequestPartyMemberSnapshotTransfer(unsigned char*);
extern "C" void Field_RequestPartyJoinFinalization(unsigned char*);
extern "C" void Resource_SetFlagAndMarkReady(unsigned char*,unsigned);
extern "C" void Field_SetPartyJoinCompletionStatus(void*,unsigned);
// Original: arm9/ov017 @ 0x021D0BD4; symbol: func_ov017_021d0bd4; size: 0x184.
// Dispatches text slot updates and resource state/flag commands from a halfword opcode.
extern "C" void DispatchTextAndResourceStatePacket(unsigned index,unsigned char *record,void*,unsigned char *owner,char *connection){
 unsigned char *node=*(unsigned char**)(owner+0x3b30);
 switch(*(unsigned short*)(record+4)){
 case 0:{Resource_UpdateIndexedStateFlag(owner,*(unsigned short*)(record+6));
 struct Text {unsigned char index,active;char chars[13];};Text text;text.index=*(unsigned short*)(record+6);text.active=1;strcpy(text.chars,(char*)record+8);
 Field_UpdateMemberJoinNameAndCache(owner,*(unsigned short*)(record+6),(char*)&text);
 char *dst=(char*)owner+0x435c+*(unsigned short*)(record+6)*0x30;
 if(dst){unsigned char decoded[48];__clear(decoded,48);Text_MapInputBytesToVariableLengthOutputSequences(record+8,decoded,1);strcpy(dst,(char*)decoded);}break;}
 case 1:if(!Network_GetLocalMemberId(connection))Field_AcknowledgeMemberJoinRoster(node,(unsigned char)index);break;
 case 2:if(!Network_GetLocalMemberId(connection))Field_AcknowledgeMemberJoinPreparation(node,(unsigned char)index);break;
 case 3:if(node[9]==2)Field_MarkJoinPreparationComplete(node);break;
 case 4:Field_RequestPartyMemberSnapshotTransfer(node);break;
 case 5:Field_RequestPartyJoinFinalization(node);break;
 case 6:Resource_SetFlagAndMarkReady(node,(unsigned char)index);break;
 case 7:Field_SetPartyJoinCompletionStatus(node,2);break;
 case 8:Field_SetPartyJoinCompletionStatus(node,1);break;
 case 9:Field_RemoveRemoteMemberAndRefreshParty((char*)owner,index);break;
 }
}
