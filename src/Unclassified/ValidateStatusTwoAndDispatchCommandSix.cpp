#include <globaldefs.h>
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int, int);
extern "C" void SetGlobalIndexedWordAtOffset18(int, int);
extern "C" int func_020d40bc(int, int);
// Original: arm9/main @ 0x020D4F3C; symbol: func_020d4f3c; size: 0x40.
extern "C" int ValidateStatusTwoAndDispatchCommandSix(int arg) {
    int result = TestCurrentStatusAgainstVariadicAllowedValues(1, 2);
    if (result != 0) return result;
    SetGlobalIndexedWordAtOffset18(6, arg);
    result = func_020d40bc(6, 0);
    if (result == 0) result = 2;
    return result;
}
