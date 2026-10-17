#include <globaldefs.h>

extern "C" void InitializeThirtyTwoFortyByteRecords(void *);
extern "C" void Graphics_InitializeSubOamStagingState(void *);

// Original: arm9/main @ 0x0203C73C; symbol: func_0203c73c; size: 0x20.
extern "C" int Object_ResetEmbeddedRecordsAndReleaseState(char *state) {
    InitializeThirtyTwoFortyByteRecords(state + 0x10);
    Graphics_InitializeSubOamStagingState(state);
    return (int)state;
}
