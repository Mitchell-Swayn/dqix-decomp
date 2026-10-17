#include <globaldefs.h>
ARM
extern "C" int TestIndexedObjectPackedMode(void *, int, int, int);
extern "C" int _fflt(int);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" int _ffix();
// Original: arm9/ov024 @ 0x021D8E18; symbol: func_ov024_021d8e18; size: 0x48.
extern "C" int Resource_ScaleValueForMatchingIndexedObject(void **object, int unused1, int index, int unused3, int unused4, int value) {
    if (!TestIndexedObjectPackedMode(*object, (short)index, 11, 0)) return value;
    unsigned converted = _fflt(value);
    _fmul(0x3fa00000, converted);
    return _ffix();
}
