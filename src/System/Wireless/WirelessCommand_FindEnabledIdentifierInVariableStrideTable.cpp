#include <globaldefs.h>
#pragma optimize_for_size off
#pragma optimization_level 2

extern "C" char* ReadGlobalOperationContextPointerAt4();
extern "C" int WirelessCommand_ReadInitializedStatus();
extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*, unsigned);

// The input header supplies a row count at +4, stride at +6, and rows at +10.
// Each row's identifier is the unsigned halfword at +4.
// Original: arm9/main @ 0x020D49C4; symbol: func_020d49c4; size: 0xE4.
extern "C" ARM char* WirelessCommand_FindEnabledIdentifierInVariableStrideTable(char* table, unsigned identifier)
{
    unsigned int rows[15];
    char* state = ReadGlobalOperationContextPointerAt4();
    if (WirelessCommand_ReadInitializedStatus()) return 0;
    if (identifier < 1 || identifier > 15) return 0;
    char* data = *(char**)(state + 4);
    _Z24InvalidateDataCacheRangePKvj(data + 0x182, 2);
    if (!(*(unsigned short*)(*(char**)(state + 4) + 0x182) & (1 << identifier))) return 0;
    if (!*(unsigned short*)(table + 4)) return 0;
    rows[0] = (unsigned int)table + 10;
    int index = 0;
    do {
        if (identifier == *(unsigned short*)((char*)rows[index] + 4))
            return (char*)rows[index];
        ++index;
        unsigned int* slot = rows + index;
        int stride = *(unsigned short*)(table + 6);
        rows[index] = stride + slot[-1];
    } while (index < *(volatile unsigned short*)(table + 4));
    return 0;
}
