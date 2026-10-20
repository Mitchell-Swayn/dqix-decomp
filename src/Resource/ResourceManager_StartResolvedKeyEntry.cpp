#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int ResourceManager_GetIndexedHeaderTable24Entry(unsigned int);
extern "C" int ResourceManager_InitializeAndStartPriorityFileEntry(void*, int, unsigned int, unsigned int, unsigned int, unsigned int, int, int, int, int);
// Original: arm9/main @ 0x020BEBB4; symbol: func_020bebb4; size: 0x5C.
extern "C" int ResourceManager_StartResolvedKeyEntry(void* first, unsigned int key, unsigned int third, unsigned int unused) {
    int entry = ResourceManager_GetIndexedHeaderTable24Entry(key);
    if (entry == 0) return 0;
    return ResourceManager_InitializeAndStartPriorityFileEntry(first, entry, *(unsigned char*)(entry + 6), *(unsigned char*)(entry + 5), key, third, 0, 0, 0, 0);
}
