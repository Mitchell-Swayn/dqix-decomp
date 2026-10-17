#include <globaldefs.h>
ARM
extern "C" void func_ov024_021f0810(int, int, int, int, int);
// Original: arm9/ov024 @ 0x021F090C; symbol: func_ov024_021f090c; size: 0x14.
extern "C" void Ov024_ForwardFifthArgument(int a, int b, int c, int d, int fifth) {
    func_ov024_021f0810(a, b, c, d, fifth);
}
