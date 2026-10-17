#include <globaldefs.h>
ARM

extern "C" void func_0205ac40(void *, void *);

// Original: arm9/ov023 @ 0x021E32CC; symbol: func_ov023_021e32cc; size: 0x38.
extern "C" void ConfigureAndSubmitIndexedRecord(char *object, int x, int y) {
    char *record = *(char **)(object + 0xcc);
    *(int *)(record + 0x154) = x << 12;
    *(int *)(record + 0x158) = y << 12;
    record[0x162] = 0x72;
    record[0x166] = 2;
    func_0205ac40(*(void **)(object + 0xc8), record + 0x140);
}
