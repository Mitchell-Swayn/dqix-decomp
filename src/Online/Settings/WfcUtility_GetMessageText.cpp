#include <globaldefs.h>
ARM
struct EntryTable { int *values; int base; };
// Original: arm9/ov031 @ 0x022276B4; symbol: func_ov031_022276b4; size: 0x18.
extern "C" int WfcUtility_GetMessageText(EntryTable *table, int index) {
    return table->base + table->values[(unsigned short)index];
}
