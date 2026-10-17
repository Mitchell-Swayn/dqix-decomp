#include <globaldefs.h>
ARM
extern "C" void func_ov031_0220321c();
extern "C" void Unclassified_SetRecordByte8To10AndClearWord44();
extern "C" void func_ov031_022031bc(int, int, int);
extern "C" int func_ov031_0220419c();
extern "C" int func_ov031_02204368(int, int);
extern "C" void func_ov031_02203250();
// Original: arm9/ov031 @ 0x022046B8; symbol: func_ov031_022046b8; size: 0x58.
extern "C" int Overlay_TryProcessFourPendingEntries() {
    func_ov031_0220321c();
    Unclassified_SetRecordByte8To10AndClearWord44();
    func_ov031_022031bc(0x44, 0x43, -1);
    int result;
    int index = 0;
    do {
        int value = func_ov031_0220419c();
        result = func_ov031_02204368(value, index);
        if (result == 1) break;
        ++index;
    } while (index < 4);
    func_ov031_02203250();
    return result == 1;
}
