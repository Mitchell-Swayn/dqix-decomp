#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" const char *HttpResponse_FindFieldValue(unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02218ED8; symbol: func_ov031_02218ed8; size: 0x40.
extern "C" int HttpResponse_CopyFieldValueIfFits(unsigned int first, unsigned int second, char *destination, unsigned int capacity) {
    const char *source = HttpResponse_FindFieldValue(first, second);
    if (source == 0) return 0;
    if ((int)strlen(source) >= (int)capacity) return 0;
    strcpy(destination, source);
    return 1;
}
