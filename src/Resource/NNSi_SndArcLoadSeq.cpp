#include <globaldefs.h>

extern "C" void *NNS_SndArcGetSeqInfo(void);
extern "C" int NNSi_SndArcLoadBank(unsigned int, unsigned int, int, int, int);
extern "C" int NNS_SndArcGetFileAddress(unsigned int);
extern "C" int ResourceManager_GetOrCreatePrimaryCachedValue(unsigned int, int, int);

// Original: arm9/main @ 0x020BDDEC; symbol: func_020bddec; size: 0x84.
extern "C" int NNSi_SndArcLoadSeq(int, unsigned int flags, int a, int b, int *out) {
    unsigned int *record=(unsigned int *)NNS_SndArcGetSeqInfo();
    if (record == 0) return 2;
    int result=NNSi_SndArcLoadBank(*(unsigned short *)(record+1),flags,a,b,0);
    if (result != 0) return result;
    if ((flags & 1) != 0) {
        result=ResourceManager_GetOrCreatePrimaryCachedValue(*record,a,b);
        if (result == 0) return 6;
    } else {
        result=NNS_SndArcGetFileAddress(*record);
    }
    if (out != 0) *out=result;
    return 0;
}
