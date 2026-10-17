#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Object_Clear40Bytes(void *);
// Original: arm9/main @ 0x0202EE94; symbol: func_0202ee94; size: 0x10.
    void ResetEmbeddedRecordAt194(unsigned char *p){
        Object_Clear40Bytes(p+404);
    }
}
