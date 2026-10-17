#include <globaldefs.h>
extern "C" void func_ov023_021e761c(void*), ClearEachIndexedEntryResource(void*), ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*), Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void func_0205da88(void*, int, int, int);
extern "C" void func_ov023_021e67f4(void*), func_ov023_021e68cc(void*), func_ov023_021e6a14(void*), func_ov023_021e6a90(void*), func_ov023_021e6b04(void*);
// Initialize shared profile-screen components and configure UI transitions.
// Original: arm9/ov012 @ 0x02185A24; symbol: func_ov012_02185a24; size: 0x94.
extern "C" void func_ov012_02185a24(unsigned char* screen) {
    func_ov023_021e761c(screen + 0xd28);
    ClearEachIndexedEntryResource(screen + 0xac);
    ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(screen + 0xac);
    func_0205da88(screen + 0xac, 1, 2, 1);
    func_0205da88(screen + 0xac, 1, 3, 1);
    func_0205da88(screen + 0xac, 2, 3, 0);
    Graphics_ResetCountedThirtyTwoByteTransfers(screen + 0xac);
    func_ov023_021e67f4(screen);
    func_ov023_021e68cc(screen);
    func_ov023_021e6a14(screen);
    func_ov023_021e6a90(screen);
    func_ov023_021e6b04(screen);
}
