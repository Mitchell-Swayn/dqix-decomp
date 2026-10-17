#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned short data_02109970[8][4];
// Original: arm9/main @ 0x02099B7C; symbol: func_02099b7c; size: 0x5C.
extern "C" int Script_SetEightByFourGlobalIntegerTable(Script::Parameter* p){for(int i=0;i<8;i++)for(int j=0;j<4;j++)data_02109970[i][j]=(p++)->ToInt();return 1;}
