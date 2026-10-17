#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" unsigned data_02109be0[];
extern "C" void Object_AppendIntegerWithinByteCapacity(unsigned*,int*);
// Original: arm9/main @ 0x0209CB94; symbol: func_0209cb94; size: 0x24.
extern "C" int Script_DispatchConvertedIntegerByPointer(Script::Parameter* param) { int value=param->ToInt(); Object_AppendIntegerWithinByteCapacity(data_02109be0,&value);return 1; }
