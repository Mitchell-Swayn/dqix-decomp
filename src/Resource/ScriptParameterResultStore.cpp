#include "Resource/Script.h"

extern "C" unsigned char data_02109a28[];

// Original: arm9/main @ 0x02099C90; symbol: func_02099c90; size: 0x1C.
extern "C" int Script_SetGlobalHalfwordAtOffset28(Script::Parameter* parameter)
{
    *(short*)(data_02109a28 + 0x28) = (short)parameter->ToInt();
    return 1;
}
