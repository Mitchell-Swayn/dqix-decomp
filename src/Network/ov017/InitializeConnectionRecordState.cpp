#include <globaldefs.h>
ARM

struct Pool;
extern "C" void *Object_GetGlobalConnectionState();
extern "C" void SetWordMaskBits_Main0203B4A0(unsigned int *word, unsigned int mask);
extern "C" void ClearResolvedBitInByteField100E(unsigned char *p, int key);
extern "C" void *ReadGlobalAt02100044();
extern "C" void InitializeRecordPoolAndPopulateFreeList(Pool *p);

// Original: arm9/ov017 @ 0x02195618; symbol: func_ov017_02195618; size: 0x40.
extern "C" void InitializeConnectionRecordState(unsigned int *object) {
    void *connection = Object_GetGlobalConnectionState();
    SetWordMaskBits_Main0203B4A0(object, 2);
    *(unsigned char *)((char *)object + 0x42e2) = 1;
    ClearResolvedBitInByteField100E((unsigned char *)connection, 0);
    InitializeRecordPoolAndPopulateFreeList((Pool *)ReadGlobalAt02100044());
}
