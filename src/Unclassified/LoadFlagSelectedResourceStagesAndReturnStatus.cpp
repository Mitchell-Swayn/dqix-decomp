#include <globaldefs.h>

extern "C" void *GetBoundedRelocatedBlobIndexEntryFromHeader8(void);
extern "C" int func_020bded0(unsigned int, unsigned int, int, int, int);
extern "C" int ReadIndexedSixteenByteTableWord14(unsigned int);
extern "C" int ResourceManager_GetOrCreatePrimaryCachedValue(unsigned int, int, int);

// Original: arm9/main @ 0x020BDDEC; symbol: func_020bddec; size: 0x84.
extern "C" int LoadFlagSelectedResourceStagesAndReturnStatus(int, unsigned int flags, int a, int b, int *out) {
    unsigned int *record=(unsigned int *)GetBoundedRelocatedBlobIndexEntryFromHeader8();
    if (record == 0) return 2;
    int result=func_020bded0(*(unsigned short *)(record+1),flags,a,b,0);
    if (result != 0) return result;
    if ((flags & 1) != 0) {
        result=ResourceManager_GetOrCreatePrimaryCachedValue(*record,a,b);
        if (result == 0) return 6;
    } else {
        result=ReadIndexedSixteenByteTableWord14(*record);
    }
    if (out != 0) *out=result;
    return 0;
}
