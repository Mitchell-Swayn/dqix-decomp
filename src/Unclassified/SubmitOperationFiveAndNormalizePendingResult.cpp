#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int, int);
extern "C" void SetGlobalIndexedWordAtOffset18(int, unsigned int);
extern "C" int func_020d40bc(int, int);
// Original: arm9/main @ 0x020D4EFC; symbol: func_020d4efc; size: 0x40.
extern "C" int SubmitOperationFiveAndNormalizePendingResult(unsigned int value) {
    int result = TestCurrentStatusAgainstVariadicAllowedValues(1, 1);
    if (result != 0)
        return result;
    SetGlobalIndexedWordAtOffset18(5, value);
    result = func_020d40bc(5, 0);
    if (result == 0)
        result = 2;
    return result;
}
