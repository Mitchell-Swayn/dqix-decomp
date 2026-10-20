#include <globaldefs.h>
extern "C" void System_SendCommandSequenceAndWaitForSuccess(unsigned*,unsigned);
extern "C" int System_SetDisplayPowerAndWaitForIPC(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020CE45C; symbol: func_020ce45c; size: 0x8C.
extern "C" int PowerManagement_SendSleepStart(unsigned a,unsigned b) {unsigned words[2];words[0]=0x03006000;System_SendCommandSequenceAndWaitForSuccess(words,1);do{}while(System_SetDisplayPowerAndWaitForIPC(0,2,0,1)!=1);words[0]=(a&0xff)|0x02006200;words[1]=0x01010000|(b&0xffff);System_SendCommandSequenceAndWaitForSuccess(words,2);return 0;}
