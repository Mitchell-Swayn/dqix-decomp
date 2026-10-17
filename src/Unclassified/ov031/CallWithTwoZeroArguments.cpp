#include <globaldefs.h>
ARM
extern "C" void func_ov031_02206150(int, int, int, int, int, int);
// Original: arm9/ov031 @ 0x02207380; symbol: func_ov031_02207380; size: 0x24.
extern "C" void CallWithTwoZeroArguments(int first, int second, int third, int fourth) {
    func_ov031_02206150(first, second, third, 0, 0, fourth);
}
