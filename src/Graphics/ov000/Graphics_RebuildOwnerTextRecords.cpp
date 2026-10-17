#include <globaldefs.h>
ARM
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void* memset(void*, int, unsigned);
extern "C" void Text_AppendSixObjectRecordLabels(unsigned char*, char*, int);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02176498; symbol: func_ov000_02176498; size: 0x68.
extern "C" void Graphics_RebuildOwnerTextRecords(void* self, int prefix) {
    if (*(void**)((char*)self + 0x38) == 0) return;
    char* buffer = *(char**)((char*)ReadWordFieldAtOffset1C() + 0x5C);
    memset(buffer, 0, 0x960);
    Text_AppendSixObjectRecordLabels((unsigned char*)self, buffer, prefix);
    LoadMatchingReadyRecordAndRefreshOwner(*(void**)((char*)self + 0x38), 0xD, buffer, 1, 0);
}
