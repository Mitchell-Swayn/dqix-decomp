#include <globaldefs.h>
ARM
extern "C" int BattleScene_PresentActionResult(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
// Original: arm9/ov025 @ 0x021D8BFC; symbol: func_ov025_021d8bfc; size: 0x34.
extern "C" int BattleScene_DispatchStoredActionResult(unsigned value, unsigned* fields) {
    unsigned char* bytes = (unsigned char*)fields;
    return BattleScene_PresentActionResult(value, fields[0], fields[1], fields[2], *(unsigned*)(bytes + 0xc), *(unsigned*)(bytes + 0x10), bytes[0x14]);
}
