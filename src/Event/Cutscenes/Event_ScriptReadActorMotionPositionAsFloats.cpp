#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct IntegerParameterView;
extern "C" char* Event_GetObjectSession(int i);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
extern "C" void Script_WriteFloatReferenceOutput(unsigned* p,unsigned v);
extern "C" unsigned int _fdiv(unsigned int, unsigned int);
extern "C" int _fflt(int);
// Original: arm9/ov001 @ 0x0215FF10; symbol: func_ov001_0215ff10; size: 0xB0.
extern "C" int Event_ScriptReadActorMotionPositionAsFloats(char *params, int count) {
    char *first = params;
    params += 8;
    char *record = Event_GetObjectSession(Script_ReadParameterAsInteger((IntegerParameterView *)first));
    if (!record) return 0;
    unsigned x = _fdiv(_fflt(*(int *)(record + 0x74)),0x45800000);
    unsigned y = _fdiv(_fflt(*(int *)(record + 0x78)),0x45800000);
    unsigned z = _fdiv(_fflt(*(int *)(record + 0x7c)),0x45800000);
    if (count >= 2) { Script_WriteFloatReferenceOutput((unsigned *)params,x); params += 8; }
    if (count >= 3) { Script_WriteFloatReferenceOutput((unsigned *)params,y); params += 8; }
    if (count >= 4) Script_WriteFloatReferenceOutput((unsigned *)params,z);
    return 1;
}
