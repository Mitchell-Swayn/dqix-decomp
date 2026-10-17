#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" char data_020fdc4c[];
// Original: arm9/main @ 0x0201F600; symbol: func_0201f600; size: 0x34.
extern "C" ARM int Script_SetFixedPointFieldAtOffset38(Script::Parameter* p){float value=p->ToFloat();int result=(int)(4096.0f*value);*(int*)(*(char**)(data_020fdc4c+16)+56)=result;return 1;}
