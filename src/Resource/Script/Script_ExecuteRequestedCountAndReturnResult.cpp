#include <globaldefs.h>
ARM
extern "C" volatile unsigned char data_02109404[];extern "C" volatile unsigned short data_020f13d8;extern "C" char data_020f13fc[];extern "C" void _ZN6Script10InitializeEv(void*);extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*,void*);extern "C" void _ZN6Script4LoadEPKvj(void*,const void*,unsigned);extern "C" void _ZN6Script7ExecuteEv(void*);
// Original: arm9/main @ 0x02095870; symbol: func_02095870; size: 0x8C.
extern "C" bool Script_ExecuteRequestedCountAndReturnResult(int unused,const void* script,unsigned size,int n,unsigned char* result){*(volatile unsigned short*)(data_02109404+6)=0;data_02109404[1]=0;data_02109404[2]=0;data_020f13d8=n;if(n<=0)return true;unsigned buffer[268];_ZN6Script10InitializeEv(buffer);_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buffer,data_020f13fc);_ZN6Script4LoadEPKvj(buffer,script,size);_ZN6Script7ExecuteEv(buffer);*result=data_02109404[2];return false;}
