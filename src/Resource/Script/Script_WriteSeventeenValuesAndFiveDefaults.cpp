#include <globaldefs.h>
#include <Resource/Script.h>
struct State {char pad[12];unsigned char* p;};extern "C" State data_02108ee8;
// Original: arm9/main @ 0x02082410; symbol: func_02082410; size: 0x6C.
extern "C" ARM int Script_WriteSeventeenValuesAndFiveDefaults(Script::Parameter* p){for(int i=0;i<17;i++){unsigned char v=p->ToInt();p++;(data_02108ee8.p+i)[60]=v;}for(int i=17;i<22;i++)(data_02108ee8.p+i)[60]=100;return 1;}
