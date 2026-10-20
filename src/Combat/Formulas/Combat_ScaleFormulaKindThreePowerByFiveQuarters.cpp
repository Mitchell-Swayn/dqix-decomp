#include <globaldefs.h>
ARM
extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
// Original: arm9/ov024 @ 0x021D8AB4; symbol: Math_ScaleIntegerByFiveQuarters_ov024_021D8AB4; size: 0x24.
// Temporary address disambiguator: the matching 1.25 wrapper at 0x021D8BEC has the same behavior; semantic distinction is unknown, so name refinement remains pending.
// Converts the sixth argument to float, multiplies by 1.25, and converts it back to integer.
extern "C" int Combat_ScaleFormulaKindThreePowerByFiveQuarters(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int unused, int value) {
    return _ffix(_fmul(0x3fa00000, _fflt(value)));
}
