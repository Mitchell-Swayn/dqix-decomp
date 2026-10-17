#include <Resource/Script.h>
extern "C" void AllocateFortyEightByteRecordArrayAndResetCount(void*,void*,short); extern "C" void *data_02108ee0[2];
// Original: arm9/main @ 0x0207F12C; symbol: func_0207f12c; size: 0x2C.
 extern "C" int Script_InvokeGlobalPairWithIntegerValue(const Script::Parameter *param) { int signExtended=param->ToInt(); AllocateFortyEightByteRecordArrayAndResetCount(data_02108ee0[1],data_02108ee0[0],signExtended); return 1; }
