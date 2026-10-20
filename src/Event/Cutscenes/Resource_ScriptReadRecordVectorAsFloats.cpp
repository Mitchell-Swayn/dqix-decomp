#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" unsigned int _fdiv(unsigned int, unsigned int);
extern "C" int _fflt(int);
extern "C" char* Event_GetObjectSession(int i);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
extern "C" void Script_WriteFloatReferenceOutput(unsigned* p,unsigned v);
struct Param { unsigned words[2]; };
// Original: arm9/ov001 @ 0x0215FFC0; symbol: func_ov001_0215ffc0; size: 0xB0.
extern "C" int Resource_ScriptReadRecordVectorAsFloats(Param *params, int count) {
    char *record = Event_GetObjectSession(Script_ReadParameterAsInteger((IntegerParameterView*)params++));
    if (!record) return 0;
    unsigned x = _fdiv(_fflt(*(int*)(record + 0x80)), 0x45800000);
    unsigned y = _fdiv(_fflt(*(int*)(record + 0x84)), 0x45800000);
    unsigned z = _fdiv(_fflt(*(int*)(record + 0x88)), 0x45800000);
    if (count >= 2) Script_WriteFloatReferenceOutput((unsigned*)params++, x);
    if (count >= 3) Script_WriteFloatReferenceOutput((unsigned*)params++, y);
    if (count >= 4) Script_WriteFloatReferenceOutput((unsigned*)params, z);
    return 1;
}
