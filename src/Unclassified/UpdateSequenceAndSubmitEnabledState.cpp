#include <globaldefs.h>
#pragma optimize_for_size on
extern "C" void ReadHalfwordFieldAtOffsetA();extern "C" unsigned char CountSetBitsInWord();extern "C" void IgnoreWirelessGameInfoResult();extern "C" int ValidateAndSubmitBounded112BytePayload(unsigned,void*,unsigned,unsigned,unsigned short,unsigned char);
// Original: arm9/main @ 0x0202BC00; symbol: func_0202bc00; size: 0x8C.
extern "C" ARM void UpdateSequenceAndSubmitEnabledState(unsigned char* self,int enabled){++*(unsigned short*)(self+4138);ReadHalfwordFieldAtOffsetA();unsigned char v=CountSetBitsInWord()-1;int active=enabled!=0;self[4137]=(self[4137]&~7)|(v&7);ValidateAndSubmitBounded112BytePayload((unsigned)IgnoreWirelessGameInfoResult,self+4116,36,1925,*(unsigned short*)(self+4),(unsigned char)active);}
