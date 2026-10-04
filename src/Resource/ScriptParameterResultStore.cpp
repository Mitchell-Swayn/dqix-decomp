#include "Resource/Script.h"

extern "C" unsigned char data_02109a28[];

extern "C" int func_02099c90(Script::Parameter* parameter)
{
    *(short*)(data_02109a28 + 0x28) = (short)parameter->ToInt();
    return 1;
}
