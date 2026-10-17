#include <globaldefs.h>
// func_02043110: 0x02043110–0x02043124, arm; 20 bytes
// Original: arm9/main @ 0x02043110; symbol: func_02043110; size: 0x14.
extern "C" void Object_ClearOptionalOffset440RecordWord8(int self) {
    int object = *(int*)(self + 0x440);
        if (object != 0) {
            *(unsigned int*)(object + 8) = 0;
        }
}
