#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void __clear(void*,unsigned);extern "C" char* strcat(char*,const char*);extern "C" int sprintf(char*,const char*,...);extern "C" char data_020f08f8[];extern "C" char data_020e80cc[][12];extern "C" char data_020f08fa[];
// Original: arm9/main @ 0x02068EA0; symbol: func_02068ea0; size: 0xA0.
extern "C" void Text_FormatUpToFourIndexedStringFragments(signed char* values,char* output){if(values[0]<0)return;char buffer[48];__clear(buffer,48);for(int i=0;i<4;i++){if(*values<0)break;if(i)strcat(buffer,data_020f08f8);strcat(buffer,data_020e80cc[*values++]);}sprintf(output,data_020f08fa,buffer);}
