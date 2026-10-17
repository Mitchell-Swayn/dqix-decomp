#include <globaldefs.h>
ARM
extern "C" void Party_InitializeTwelveValuePairRecord(void*);
extern "C" void InitializePartyIndexedRecordAndCopyDerivedHalfwords(unsigned char*,int,int,unsigned char);
extern "C" unsigned _ffltu(unsigned);
// Original: arm9/ov023 @ 0x021DBC58; symbol: func_ov023_021dbc58; size: 0xB8.
extern "C" void GameState_ReadPartyDerivedFloatValues(int index,unsigned* output,int value) {
unsigned char record[0x7c];
Party_InitializeTwelveValuePairRecord(record);
InitializePartyIndexedRecordAndCopyDerivedHalfwords(record,index,value,1);
output[0]=_ffltu(*(unsigned short*)(record+0x3e));
output[1]=_ffltu(*(unsigned short*)(record+0x42));
output[2]=*(unsigned*)(record+0x48);
output[3]=*(unsigned*)(record+0x50);
output[4]=*(unsigned*)(record+0x58);
output[5]=0;
output[6]=_ffltu(*(unsigned short*)(record+0x66));
output[7]=_ffltu(*(unsigned short*)(record+0x6a));
output[8]=_ffltu(*(unsigned short*)(record+0x6e));
output[9]=_ffltu(*(unsigned short*)(record+0x72));
output[10]=_ffltu(*(unsigned short*)(record+0x76));
output[11]=_ffltu(*(unsigned short*)(record+0x7a));
}
