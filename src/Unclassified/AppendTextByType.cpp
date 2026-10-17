#include <globaldefs.h>
ARM
extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);extern "C" const char data_020eff4d[],data_020eff57[],data_020eff61[],data_020eff6b[];
// Original: arm9/main @ 0x02041DD0; symbol: func_02041dd0; size: 0xA0.
extern "C" int AppendTextByType(char* text,unsigned type) { char* end=text+String_CountBytesUntilTerminator(text);switch(type) {case 0:end+=sprintf(end,data_020eff4d);break;case 1:break;case 2:break;case 3:break;case 5:end+=sprintf(end,data_020eff57);break;case 4:end+=sprintf(end,data_020eff61);break;case 6:end+=sprintf(end,data_020eff6b);break;}return end-text; }
