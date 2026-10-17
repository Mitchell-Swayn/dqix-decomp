#include <globaldefs.h>
ARM
extern unsigned char data_020ee82c[],data_020ee848[],data_020ee856[],data_020ee83a[];extern "C" void BuildRecordsWithCumulativeHalfProductOffsets(void*,int,const void*,const void*,const void*,const void*);extern "C" void ClearTwoWordsAndFollowingByte(void*);extern "C" void WriteFirstWordValue(void*,int);extern "C" void Object_SetWord4AndByte8(void*,void*,int);extern "C" int func_0205b234(void*,int,int,void*,int,int);
// Original: arm9/main @ 0x020E0DF8; symbol: func_020e0df8; size: 0xCC.
extern "C" void BuildSevenEntriesAndRenderFormattedValues(unsigned char* object,int a,int b){unsigned char entries[84];unsigned state[3];BuildRecordsWithCumulativeHalfProductOffsets(entries,7,data_020ee82c,data_020ee848,data_020ee856,data_020ee83a);ClearTwoWordsAndFollowingByte(state);WriteFirstWordValue(state,a+b);Object_SetWord4AndByte8(state,entries,7);int last=func_0205b234(state,6,2,object+0x5b4,15,0);func_0205b234(state,(short)(last+9),2,object+0x5f4,15,0);}
