#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" const char data_ov001_02164d10[];
// Original: arm9/ov001 @ 0x02159CFC; symbol: func_ov001_02159cfc; size: 0x48.
extern "C" void Ov001_InitializeSessionRecord(char *record) {
    *(unsigned int *)record = 0;
    memset(record + 4, 0, 0x0c);
    *(unsigned int *)(record + 0x10) = 0;
    *(unsigned int *)(record + 0x14) = 0;
    *(unsigned int *)(record + 0x18) = 0;
    strcpy(record + 0x1c, data_ov001_02164d10);
    *(unsigned int *)(record + 0x3c) = 0;
}
