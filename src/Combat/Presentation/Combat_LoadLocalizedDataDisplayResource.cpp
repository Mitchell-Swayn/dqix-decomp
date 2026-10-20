#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" unsigned char Combat_QueueDataResourceAndTrackLoad_PathDataS[];
extern "C" void LoadAndRegisterLocalizedDisplayResource(const char *, signed char);
// Original: arm9/ov025 @ 0x021E4168; symbol: func_ov025_021e4168; size: 0x38.
extern "C" int Combat_LoadLocalizedDataDisplayResource(void *state) {
    char path[0x50];
    sprintf(path, (const char *)Combat_QueueDataResourceAndTrackLoad_PathDataS, *(unsigned int *)((char *)state + 0xc));
    LoadAndRegisterLocalizedDisplayResource(path, *(signed char *)((char *)state + 8));
    return 1;
}
