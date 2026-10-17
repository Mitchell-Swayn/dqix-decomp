#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

extern "C" void InitializeFourWordsWithInvalidIndex(void*);

// Original: arm9/ov017 @ 0x021c17cc; symbol: func_ov017_021c17cc; size: 0x30.
extern "C" ARM void InitializeRecordType2F(unsigned char* record) {
    InitializeFourWordsWithInvalidIndex(record);
    record[0] = 0x2f;
    ((SafeAllocator*)(record + 8))->ResetAllocatorPointer();
    record[0x1c] = 0;
    *(unsigned int*)(record + 0x20) = 0;
    record[0x1d] = 0;
}
