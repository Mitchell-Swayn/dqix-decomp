#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int ReadWordAtOffset0(void);
extern "C" void ClearWord98And1024ByteBuffer(int);
// Original: arm9/main @ 0x0209CE14; symbol: func_0209ce14; size: 0x20.
extern "C" int ProcessResolvedGlobalStateWhenPresent(void) {
    int value = ReadWordAtOffset0();
    if (value != 0) {
        ClearWord98And1024ByteBuffer(value);
        return 1;
    }
    return 0;
}
