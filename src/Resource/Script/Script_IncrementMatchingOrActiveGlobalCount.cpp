#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct State{unsigned char active;unsigned char pad[15];int count;int pad14[2];int id;};extern "C" State data_02108d70;
// Original: arm9/main @ 0x02071004; symbol: func_02071004; size: 0x40.
extern "C" int Script_IncrementMatchingOrActiveGlobalCount(Script::Parameter* p){int id=p->ToInt();if(data_02108d70.id==id||data_02108d70.active)data_02108d70.count++;return 1;}
