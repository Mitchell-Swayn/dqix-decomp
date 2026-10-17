#include <globaldefs.h>
ARM
#include <Resource/Script.h>
extern "C" unsigned data_02109fe0[]; extern "C" void Object_Allocate44ByteArrayForPositiveCount(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020A7F5C; symbol: func_020a7f5c; size: 0x2C.
 extern "C" int Script_ApplyHalfwordValueToGlobalPairContext(Script::Parameter* p) { unsigned value=p->ToInt(); Object_Allocate44ByteArrayForPositiveCount(data_02109fe0[1],data_02109fe0[0],(unsigned short)value); return 1; }
