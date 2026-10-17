#include <globaldefs.h>
ARM
struct RecordDirectory { unsigned char pad[0x1c]; unsigned char * volatile records; unsigned char rest[4]; void *optional; };
extern "C" struct RecordDirectory data_ov001_02165880;
extern "C" unsigned char data_ov001_021658b8[];
extern "C" void func_ov001_0215a134(void *);
extern "C" void func_ov001_02158ae4(void);
// Original: arm9/ov001 @ 0x0215A9B4; symbol: func_ov001_0215a9b4; size: 0x60.
extern "C" int Graphics_RefreshTwentyFourRecordsAndNotify(void) {
    for (int i = 0; i < 0x18; i++) func_ov001_0215a134(data_ov001_02165880.records + i * 0x588);
    if (*(int *)(data_ov001_021658b8 + 0xe4) != 0 && data_ov001_02165880.optional != 0) func_ov001_02158ae4();
    return 1;
}
