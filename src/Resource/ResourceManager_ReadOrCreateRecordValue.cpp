#include <globaldefs.h>

extern "C" void *ResourceManager_GetIndexedHeaderTableCEntry(void);
extern "C" int NNS_SndArcGetFileAddress(unsigned int);
extern "C" int SoundArchive_LoadSequenceArchiveFile(unsigned int, int, int);

// Original: arm9/main @ 0x020BDE70; symbol: func_020bde70; size: 0x60.
extern "C" int ResourceManager_ReadOrCreateRecordValue(int, unsigned int flags, int a, int b, int *out) {
    unsigned int *record=(unsigned int *)ResourceManager_GetIndexedHeaderTableCEntry();
    if (record == 0) return 3;
    int result;
    if ((flags & 8) != 0) {
        result=SoundArchive_LoadSequenceArchiveFile(*record,a,b);
        if (result == 0) return 7;
    } else {
        result=NNS_SndArcGetFileAddress(*record);
    }
    if (out != 0) *out=result;
    return 0;
}
