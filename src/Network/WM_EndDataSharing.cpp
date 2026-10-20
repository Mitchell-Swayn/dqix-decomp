#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void BuildEventAndDispatchRequestWithCallback(unsigned short, int, int);
// Original: arm9/main @ 0x020D5F88; symbol: func_020d5f88; size: 0x48.
extern "C" int WM_EndDataSharing(int object) {
    if (object == 0) return 6;
    if (*(unsigned short *)((char *)object + 0x80e) == 0) return 3;
    BuildEventAndDispatchRequestWithCallback(*(unsigned short *)((char *)object + 0x816), 0, 0);
    *(unsigned short *)((char *)object + 0x80e) = 0;
    *(unsigned short *)((char *)object + 0x81c) = 0;
    return 0;
}
