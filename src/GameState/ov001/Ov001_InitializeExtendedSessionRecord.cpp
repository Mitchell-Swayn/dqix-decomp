#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" const char data_ov001_02164d10[];
// Original: arm9/ov001 @ 0x02158828; symbol: func_ov001_02158828; size: 0x58.
extern "C" void Ov001_InitializeExtendedSessionRecord(char *record) {
    *(unsigned int *)record = 0;
    memset(record + 4, 0, 0x0c);
    memset(record + 0x10, 0, 0x0c);
    *(unsigned int *)(record + 0x1c) = 0;
    *(unsigned int *)(record + 0x20) = 0;
    *(unsigned int *)(record + 0x24) = 0;
    strcpy(record + 0x28, data_ov001_02164d10);
    *(unsigned int *)(record + 0x48) = 0;
}
