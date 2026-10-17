#include <globaldefs.h>
extern "C" unsigned char data_ov031_02290d20[];
extern "C" void func_ov031_02238b60();
// Original: arm9/ov031 @ 0x0223A760; symbol: func_ov031_0223a760; size: 0x34.
extern "C" ARM int Ov031_AdvanceContextFromFive() {
    unsigned char* context = *(unsigned char**)data_ov031_02290d20;
    if (context[0xa90] != 5) return 0;
    context[0xa90] = 6;
    func_ov031_02238b60();
    return 1;
}
