#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* ActionData_GetGlobalTables();
extern "C" int Combat_ResolvePartyCommandTargets(void*, unsigned, unsigned, unsigned);
// Original: arm9/ov000 @ 0x021540C8; symbol: func_ov000_021540c8; size: 0x34.
extern "C" int ProcessEmbeddedRecord(void* output, unsigned char* record, unsigned argument) {
    _ZN9GameState11GetInstanceEv();
    ActionData_GetGlobalTables();
    return (int)Combat_ResolvePartyCommandTargets(output, *(unsigned short*)(*(unsigned*)(record + 0x10) + 0x20), *(unsigned short*)record, argument);
}
