#include <globaldefs.h>
ARM
extern "C" void UpdateModeByteAndValidateTenPrintableCharacters(unsigned int);
// Original: arm9/ov031 @ 0x022154E4; symbol: func_ov031_022154e4; size: 0x14.
extern "C" unsigned int WfcConnection_FinalizeAccessPointMetadata(void *object) {
    UpdateModeByteAndValidateTenPrintableCharacters(*(unsigned char *)((unsigned char *)object + 0xD0D));
    return 0x10;
}
