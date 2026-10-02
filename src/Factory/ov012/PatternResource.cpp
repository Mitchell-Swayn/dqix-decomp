#include "PatternState.h"

// The resource loader calls this for each 32-byte record before setting its
// fixed-up flag. A -1 offset or absent string pool denotes a null alternative.
extern "C" int func_ov012_0218558c(PatternResource* resource, PatternRecord* record)
{
    for (int i = 0; i < record->count; ++i) {
        char* encoded = record->alternatives[i].text;
        int absent = 1;
        // MWCC preserves the byte-pointer subtraction used by the original
        // relocatable-pointer representation; integer subtraction folds it.
        int offset = encoded - (char*)0;
        if (offset != -1 && resource->strings != 0) {
            absent = 0;
        }
        record->alternatives[i].text = absent ? 0 : resource->strings + offset;
    }
    return 1;
}
