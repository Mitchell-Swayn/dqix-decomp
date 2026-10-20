#include <globaldefs.h>
ARM
struct Packed { unsigned char value:7; unsigned char flag:1; };
extern "C" int Network_GetLocalMemberId(char*);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(char**);
extern "C" char* Inn_GetServiceSceneController(void*);
extern "C" void TagMode_ReceiveAndStageGuestProfile(void*,void*,void*,int,int);
// Original: arm9/ov017 @ 0x021D0F94; symbol: DispatchMatchingIndexType42Record; size: 0x7c.
// Dispatches a packed record when its index matches and the indirect type is 42.
extern "C" void Field_ApplyTargetedGuestProfileFragment(void* a,unsigned char* record,void* unused,char* state,char* index) {
 if(record[4]==Network_GetLocalMemberId(index) && LinkedQueue_GetFrontKindOrInvalid(*(char***)(state+0x36fc))==42) {
 char* p=Inn_GetServiceSceneController(*(void**)(state+0x3b40));
 if(p) TagMode_ReceiveAndStageGuestProfile(p+0x7e0,a,record+7,((Packed*)(record+6))->value,record[5]);
 }
}
