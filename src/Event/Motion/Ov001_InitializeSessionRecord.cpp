#include <globaldefs.h>
#include <std_library_functions.h>
ARM
// Original data: arm9/ov001 @ 0x2164d10; symbol: data_ov001_02164d10.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" const char Ov001InitializeSessionRecord_UnknownRoleInitializedBytes[];
// Original: arm9/ov001 @ 0x02159CFC; symbol: func_ov001_02159cfc; size: 0x48.
extern "C" void Ov001_InitializeSessionRecord(char *record) {
    *(unsigned int *)record = 0;
    memset(record + 4, 0, 0x0c);
    *(unsigned int *)(record + 0x10) = 0;
    *(unsigned int *)(record + 0x14) = 0;
    *(unsigned int *)(record + 0x18) = 0;
    strcpy(record + 0x1c, Ov001InitializeSessionRecord_UnknownRoleInitializedBytes);
    *(unsigned int *)(record + 0x3c) = 0;
}
