#include <globaldefs.h>
#include "Resource/Script.h"
extern "C" char data_020fdc4c[];extern "C" void AppendKeyedRecordWithResolvedIndex(void*,int,int,int,int);
// Original: arm9/main @ 0x0201F5A8; symbol: func_0201f5a8; size: 0x58.
extern "C" ARM int Script_InvokeOwnerWithFourIntegerParameters(Script::Parameter* p){int a=p[0].ToInt();int b=p[1].ToInt();int c=p[2].ToInt();int d=p[3].ToInt();AppendKeyedRecordWithResolvedIndex(*(void**)(data_020fdc4c+0x10),a,b,c,d);return 1;}
