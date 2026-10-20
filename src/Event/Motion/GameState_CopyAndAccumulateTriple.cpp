#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
// Original: arm9/ov001 @ 0x021587C4; symbol: func_ov001_021587c4; size: 0x64.
extern "C" int GameState_CopyAndAccumulateTriple(const char* source, char* state) {
    char* buffer = *(char**)(state + 0xa20);
    if (buffer == 0)
        return 0;
    memcpy(state + 0x58, buffer + 0x74, 0xc);
    *(int*)(state + 0x58) += *(int*)(source + 4);
    *(int*)(state + 0x5c) += *(int*)(source + 8);
    *(int*)(state + 0x60) += *(int*)(source + 0xc);
    return 1;
}
