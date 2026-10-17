#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

extern "C" void InitializeFourWordsWithInvalidIndex(void*);

// Original: arm9/ov017 @ 0x021ac2ec; symbol: func_ov017_021ac2ec; size: 0x40.
extern "C" ARM void InitializeRecordType30(unsigned char* record) {
    InitializeFourWordsWithInvalidIndex(record);
    record[0] = 0x1e;
    *(unsigned int*)(record + 8) = 0;
    *(unsigned int*)(record + 0xc) = 0;
    ((SafeAllocator*)(record + 0x10))->ResetAllocatorPointer();
    *(unsigned int*)(record + 0x24) = 0xffffffff;
    record[0x28] = 0;
    record[0x29] = 0;
}
