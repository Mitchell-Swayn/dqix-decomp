#include <globaldefs.h>
ARM
extern "C" void MenuRecord_ResetHeader(void*);
// Original: arm9/ov023 @ 0x021FD1E0; symbol: func_ov023_021fd1e0; size: 0x54.
extern "C" int MenuDisplayCommand_InitializeRecord(void* record, unsigned unused, unsigned short value1, unsigned short value2, const unsigned* words, const unsigned char* bytes) {
    MenuRecord_ResetHeader(record);
    *(unsigned short*)((char*)record + 4) = 0xd;
    *(unsigned short*)((char*)record + 6) = value1;
    *(unsigned short*)((char*)record + 8) = value2;
    *(unsigned*)((char*)record + 0x20) = words[0];
    *(unsigned*)((char*)record + 0x24) = words[1];
    *(unsigned char*)((char*)record + 0x28) = bytes[0];
    *(unsigned char*)((char*)record + 0x29) = bytes[1];
    return 1;
}
