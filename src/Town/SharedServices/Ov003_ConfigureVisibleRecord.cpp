#include <globaldefs.h>
extern "C" void Ov003_ConfigureIndexedRecord(void*, unsigned, int, int, int, int, int);
// Original: arm9/ov003 @ 0x021702E4; symbol: func_ov003_021702e4; size: 0x58.
extern "C" ARM void Ov003_ConfigureVisibleRecord(void* object) {
    signed char mode = *(signed char*)((char*)object + 1);
    if (mode == 0) goto done;
    if (mode == 1) goto done;
    int type = *(short*)((char*)object + 0xc);
    int state = 4;
    int index = 7;
    if (type == 5) {
        state = 3;
        index = 6;
    }
    Ov003_ConfigureIndexedRecord((char*)object + 0x68, index, 0xcc, 0xb, -1, state, 3);
done:
    return;
}
