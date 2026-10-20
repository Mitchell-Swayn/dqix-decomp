#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" int sprintf(char*,const char*,...);
// Original: arm9/ov003 @ 0x02160344; symbol: Resource_FormatFourBuffersFromTable; size: 0x58.
// Formats up to four nonnull output buffers using 0x30-byte-spaced resource strings.
extern "C" void Resource_FormatFourBuffersFromTable(void* self) {
    char* resource = (char*)GameResources_GetInstance() + 0x35c;
    int i = 0;
    resource += 0x4000;
    for (; i < 4; ++i) {
        char** buffers = *(char***)( (char*)self + 0x394 );
        if (buffers == 0) return;
        char* destination = buffers[i];
        if (destination != 0) {
            char* format = resource + i * 0x30;
            if (format != 0) sprintf(format, destination);
        }
    }
}
