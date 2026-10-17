#include <globaldefs.h>
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned short);
extern "C" unsigned OV023_ReadHalfwordField04(void *);
extern "C" void WriteHalfwordAtOffset22(void *, unsigned short);
// Original: arm9/ov004 @ 0x02165EA4; symbol: func_ov004_02165ea4; size: 0x50.
extern "C" void *Ov004_FindTypeOneAndWriteHalfword(void *state, unsigned short type, unsigned short value) {
    void *object = func_ov023_021f6880(func_ov011_021849c8(state), type);
    if (object == 0) object = 0;
    else if (OV023_ReadHalfwordField04(object) != 1) object = 0;
    if (object == 0) return 0;
    WriteHalfwordAtOffset22(object, value);
    return object;
}
