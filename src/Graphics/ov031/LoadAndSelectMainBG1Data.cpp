#include <globaldefs.h>
ARM
extern "C" void *data_ov031_02250bf4;
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void *, unsigned);
extern "C" void LoadToMainBG1ScreenData(const void *, unsigned, unsigned);
extern "C" void func_ov031_0223e2c0(int, void *);
// Original: arm9/ov031 @ 0x02223A24; symbol: func_ov031_02223a24; size: 0x40.
extern "C" void LoadAndSelectMainBG1Data(void *argument) {
    _Z25CleanInvalidateCacheRangePKvj(data_ov031_02250bf4, 0xc0);
    LoadToMainBG1ScreenData(data_ov031_02250bf4, 0, 0xc0);
    func_ov031_0223e2c0(1, argument);
}
