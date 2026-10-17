#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Object_InitializeTwoSelectionRecordsAndFlags(void *);
// Original: arm9/main @ 0x0205C564; symbol: func_0205c564; size: 0xC.
    void InitializeEmbeddedDisplayRecords(void *p){
        Object_InitializeTwoSelectionRecordsAndFlags(p);
    }
}
