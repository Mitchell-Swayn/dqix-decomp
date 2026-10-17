#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct Counter {char pad[6];unsigned short value;};
extern "C" Counter data_02109404;
// Original: arm9/main @ 0x020954E8; symbol: func_020954e8; size: 0x30.
extern "C" int Script_IncrementGlobalCounterForNonzeroNonFFParameter(Script::Parameter* p) {
    int value=p->ToInt();
    if(value==255 || value==0)return 1;
    ++data_02109404.value;
    return 1;
}
