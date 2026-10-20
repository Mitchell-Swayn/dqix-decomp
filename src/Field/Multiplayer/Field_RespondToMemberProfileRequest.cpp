#include <globaldefs.h>
ARM
struct Packed {unsigned char member:7;unsigned char mode:1;};
extern "C" int Network_GetLocalMemberId(char*);
extern "C" int Network_IsSessionActive(void*);
extern "C" void GameState_CopyElapsedTimeIntoTwoConfigurationRecords(int);
extern "C" void Field_QueueMemberProfileFragments(int,unsigned char,int,int);
extern "C" unsigned char* NavigationMessage_GetGlobalInstance();
extern "C" int NavigationMessage_EnqueueWithFormattedMemberName(unsigned char*,short,int,signed char);
// Original: arm9/ov017 @ 0x021D1078; symbol: ApplyPackedMemberClassification; size: 0xa0.
// Matches packed member index or applies explicit mode flags, and records classification20000.
extern "C" void Field_RespondToMemberProfileRequest(int index,unsigned char* record,int unused1,int unused2,char* context){
 int current=Network_GetLocalMemberId(context);Packed* bits=(Packed*)(record+4);
 if(!bits->mode){if(current!=bits->member)return;
 GameState_CopyElapsedTimeIntoTwoConfigurationRecords(Network_IsSessionActive(context)!=0);Field_QueueMemberProfileFragments(index,255,0,0);
 NavigationMessage_EnqueueWithFormattedMemberName(NavigationMessage_GetGlobalInstance(),20000,-1,(signed char)index);
 }else{unsigned char flags=1;if(record[5]==1)flags|=4;Field_QueueMemberProfileFragments(index,flags,1,record[5]);}
}
