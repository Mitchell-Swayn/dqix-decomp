#include <globaldefs.h>

extern "C" void ResetStateIndicesFlagsAndTailFields(unsigned short*);

// Original: arm9/main @ 0x02048104; symbol: func_02048104; size: 0x1C.
extern "C" ARM void ResetObjectAndSetFlag200(unsigned short* object) {
    ResetStateIndicesFlagsAndTailFields(object);
    *object |= 0x200;
}
