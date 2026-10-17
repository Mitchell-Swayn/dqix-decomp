#include <globaldefs.h>
#include <Resource/Script.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" unsigned int data_020fdd30;
extern "C" void Object_AppendHalfwordPairWithinCapacity(int, unsigned short *);
// Original: arm9/main @ 0x0202800C; symbol: func_0202800c; size: 0x3C.
extern "C" int Script_ConvertTwoParametersToHalfwordPair(Script::Parameter *param_1, unsigned int unused2, unsigned int unused3, unsigned int param_4) {
    unsigned int first = (unsigned int)param_1->ToInt();
    unsigned short second = (unsigned short)((Script::Parameter *)((char *)param_1 + 8))->ToInt();
    unsigned short local[2];
    local[1] = second;
    unsigned int target = data_020fdd30;
    local[0] = (unsigned short)first;
    Object_AppendHalfwordPairWithinCapacity(target, local);
    return 1;
}
