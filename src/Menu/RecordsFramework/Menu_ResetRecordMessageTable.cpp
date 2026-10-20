#include <globaldefs.h>
ARM
extern "C" void MessageTextTable_Reset(char* p);
// Original: arm9/ov023 @ 0x021FA588; symbol: func_ov023_021fa588; size: 0x10.
extern "C" void Menu_ResetRecordMessageTable(char* p) {
    MessageTextTable_Reset(p + 0x20);
}
