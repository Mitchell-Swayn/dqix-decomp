#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* ReadGlobalAt02108E10();
extern "C" int func_ov000_021540fc(void*, unsigned, unsigned, unsigned);
// Original: arm9/ov000 @ 0x021540C8; symbol: func_ov000_021540c8; size: 0x34.
extern "C" int ProcessEmbeddedRecord(void* output, unsigned char* record, unsigned argument) {
    _ZN9GameState11GetInstanceEv();
    ReadGlobalAt02108E10();
    return (int)func_ov000_021540fc(output, *(unsigned short*)(*(unsigned*)(record + 0x10) + 0x20), *(unsigned short*)record, argument);
}
