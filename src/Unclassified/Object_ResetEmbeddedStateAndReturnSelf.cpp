#include <globaldefs.h>
extern "C" {
    void ClearRecordAndInvalidateTwoIndices(void *);
// Original: arm9/main @ 0x020DFC2C; symbol: func_020dfc2c; size: 0x14.
    void *Object_ResetEmbeddedStateAndReturnSelf(void *p){
        ClearRecordAndInvalidateTwoIndices(p);
        return p;
    }
}
