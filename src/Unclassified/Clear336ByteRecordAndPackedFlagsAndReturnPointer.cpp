#include <globaldefs.h>
extern "C" {
    void Clear336ByteRecordAndPackedFlags(void *);
// Original: arm9/main @ 0x020D806C; symbol: func_020d806c; size: 0x14.
    void *Clear336ByteRecordAndPackedFlagsAndReturnPointer(void *p){
        Clear336ByteRecordAndPackedFlags(p);
        return p;
    }
}
