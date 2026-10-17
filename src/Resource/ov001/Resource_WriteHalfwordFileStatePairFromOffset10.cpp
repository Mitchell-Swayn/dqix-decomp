#include <globaldefs.h>
ARM
extern "C" char data_02108760[];
extern "C" char data_ov001_0216587c[];
extern "C" int WriteOrApplyHalfwordFileStatePair(char *p, int a, int b, void *file);
// Original: arm9/ov001 @ 0x02159990; symbol: func_ov001_02159990; size: 0x28.
extern "C" int Resource_WriteHalfwordFileStatePairFromOffset10(void *object) {
    WriteOrApplyHalfwordFileStatePair(data_02108760, *(int *)((char *)object + 0x10), 0, data_ov001_0216587c);
    return 0;
}
