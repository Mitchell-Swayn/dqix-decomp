#include <globaldefs.h>
ARM
extern "C" unsigned ReadSharedHalfwordOrBusy8000(); extern "C" void SetGlobalValueExceptModesNineAndTen(int); extern "C" char data_021015a0[];
extern "C" int MergeLowestSequenceAndLevelMask(); extern "C" int SubmitFiveHalfwordOperation1EPayload(void *,unsigned short,unsigned short,unsigned short,unsigned short);
// Original: arm9/main @ 0x0202D788; symbol: func_0202d788; size: 0xB8.
extern "C" unsigned short Network_SelectAvailableChannelAndStartRequest(unsigned short value) { unsigned flags=ReadSharedHalfwordOrBusy8000(); if(flags==0x8000) { SetGlobalValueExceptModesNineAndTen(3); *(int *)(data_021015a0+16)=9; return 3; } if(flags==0) { SetGlobalValueExceptModesNineAndTen(22); *(int *)(data_021015a0+16)=9; return 24; } while(!(flags&(1U<<(value-1)))) { ++value; if(value>16) return 24; } return SubmitFiveHalfwordOperation1EPayload((void *)MergeLowestSequenceAndLevelMask,3,17,value,30); }
