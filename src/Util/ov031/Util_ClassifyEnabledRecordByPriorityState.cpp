#include <globaldefs.h>
ARM
struct State {unsigned char pad[0xd0c];unsigned char type:4;unsigned char rest:4;};
extern "C" State* SelectStateWordByPriorityMask(unsigned);
extern "C" int Overlay_IsGeneratedRecordPrefixExpected(void*);
extern "C" int MatchesEightBytesAgainstGlobalRecord(void*);
// Original: arm9/ov031 @ 0x02213800; symbol: func_ov031_02213800; size: 0x94.
extern "C" int Util_ClassifyEnabledRecordByPriorityState(unsigned char* p){
 State* state=SelectStateWordByPriorityMask(16);
 if((state->type==0 || state->type==4) && ((*(unsigned short*)(p+0x2c)>>4)&1)==1 && MatchesEightBytesAgainstGlobalRecord(p+12)==1)return 6;
 if((state->type==0 || state->type==5) && ((*(unsigned short*)(p+0x2c)>>4)&1)==1 && Overlay_IsGeneratedRecordPrefixExpected(p+12)==1)return 7;
 return -1;
}
