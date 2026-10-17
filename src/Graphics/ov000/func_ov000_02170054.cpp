#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetAndApplyGlobalConfiguration(unsigned int);
extern "C" void ResetRecordDefaults(char *);
// Original: arm9/ov000 @ 0x02170054; symbol: func_ov000_02170054; size: 0x24.
extern "C" void func_ov000_02170054(void *p) {
    Graphics_ResetAndApplyGlobalConfiguration((unsigned int)p + 0x50);
    Graphics_ResetAndApplyGlobalConfiguration((unsigned int)p + 0x68);
    ResetRecordDefaults((char *)p + 8);
}
