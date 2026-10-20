#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void* Event_GetObjectSession(int);
extern "C" float Script_ReadParameterAsFloat(void*);
extern "C" unsigned _fmul(unsigned,float);
extern "C" int _ffix(unsigned);
extern "C" void Pool_AppendType16NodeWithTwoValues(void*,int,int);
// Original: arm9/ov001 @ 0x0215C8A4; symbol: Script_ApplyFixedAndIntegerParametersToRecord; size: 0x5C.
// Reads the record index, converts the float parameter at +8 to fixed point scaled by 4096, then applies the integer parameter at +0x10.
extern "C" int Script_QueueObjectRadiusInterpolation(void* parameters) {
    int index = Script_ReadParameterAsInteger(parameters);
    void* record = Event_GetObjectSession(index);
    if (record == 0) return 0;
    unsigned fixed = _ffix(_fmul(0x45800000, Script_ReadParameterAsFloat((char*)parameters + 8)));
    int value = Script_ReadParameterAsInteger((char*)parameters + 0x10);
    Pool_AppendType16NodeWithTwoValues(record, (int)fixed, value);
    return 1;
}
