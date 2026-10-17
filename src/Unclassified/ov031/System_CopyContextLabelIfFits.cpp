#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" const char *func_ov031_02218e2c(unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02218ED8; symbol: func_ov031_02218ed8; size: 0x40.
extern "C" int System_CopyContextLabelIfFits(unsigned int first, unsigned int second, char *destination, unsigned int capacity) {
    const char *source = func_ov031_02218e2c(first, second);
    if (source == 0) return 0;
    if ((int)strlen(source) >= (int)capacity) return 0;
    strcpy(destination, source);
    return 1;
}
