#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" const char data_ov023_021fe144[];
// Original: arm9/ov023 @ 0x021F229C; symbol: func_ov023_021f229c; size: 0x68.
extern "C" void Filesystem_FormatInlinePathRecord(void* destination, const void* source) {
    if (source == 0) return;
    volatile const unsigned* sourceWords = (volatile const unsigned*)source;
    unsigned first = sourceWords[0];
    *(unsigned*)destination = first;
    unsigned pathWord = sourceWords[1];
    *(volatile unsigned*)((char*)destination + 4) = pathWord;
    unsigned third = sourceWords[2];
    *(unsigned*)((char*)destination + 4) = (unsigned)((char*)destination + 0x44);
    *(unsigned*)((char*)destination + 8) = third;
    char* path = (char*)sourceWords[1];
    if (path == 0) return;
    memset((char*)destination + 0x44, 0, 0x200);
    sprintf((char*)destination + 0x44 + String_CountBytesUntilTerminator((const signed char*)((char*)destination + 0x44)), data_ov023_021fe144, path);
}
