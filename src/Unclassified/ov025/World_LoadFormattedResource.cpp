#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" unsigned char data_ov025_021ef7ef[];
extern "C" void func_ov025_021e27c8(const char *, signed char);
// Original: arm9/ov025 @ 0x021E4168; symbol: func_ov025_021e4168; size: 0x38.
extern "C" int World_LoadFormattedResource(void *state) {
    char path[0x50];
    sprintf(path, (const char *)data_ov025_021ef7ef, *(unsigned int *)((char *)state + 0xc));
    func_ov025_021e27c8(path, *(signed char *)((char *)state + 8));
    return 1;
}
