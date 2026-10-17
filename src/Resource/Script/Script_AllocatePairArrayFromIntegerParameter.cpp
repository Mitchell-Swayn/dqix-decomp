#include <globaldefs.h>
ARM
#include <Resource/Script.h>
extern "C" void* data_020fdd30[2];
extern "C" void AllocateAndClearPairArray(void*,void*,int);
// Original: arm9/main @ 0x02027FBC; symbol: func_02027fbc; size: 0x24.
extern "C" int Script_AllocatePairArrayFromIntegerParameter(const Script::Parameter* parameter) {
 int index=parameter->ToInt();
 AllocateAndClearPairArray(data_020fdd30[0],data_020fdd30[1],index);
 return 1;
}
