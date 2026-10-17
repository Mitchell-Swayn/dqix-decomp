#include <globaldefs.h>
#include <System/Cache.h>
#pragma optimize_for_size off
extern "C" void Object_InvokeLockMutex();
extern "C" void UnlockGlobalCommandMutex();
// Original: arm9/main @ 0x020D2C98; symbol: func_020d2c98; size: 0x48.
extern "C" void ClearLinkedCommandNodesAndFlushEachHeader(char* object) {
    Object_InvokeLockMutex();
    char* node = *(char**)(object + 0x18);
    if (node != 0) {
        do {
            char* next = *(char**)(node + 4);
            *(int*)node = 0;
            *(int*)(node + 4) = 0;
            CleanCacheRange(node, 8);
            node = next;
        } while (node != 0);
    }
    UnlockGlobalCommandMutex();
}
