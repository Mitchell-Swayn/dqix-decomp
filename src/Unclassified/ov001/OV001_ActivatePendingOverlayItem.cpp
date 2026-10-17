#include <globaldefs.h>
extern "C" int func_ov017_021d4ce4(void *, int);
extern "C" void Graphics_RefreshTwentyFourRecordsAndNotify();
extern "C" unsigned char data_ov001_02165828[];
extern "C" unsigned char data_ov001_0216580c[];
// Original: arm9/ov001 @ 0x02153948; symbol: func_ov001_02153948; size: 0x4C.
extern "C" int OV001_ActivatePendingOverlayItem(void *item) {
    int result = func_ov017_021d4ce4(data_ov001_02165828, (int)item);
    if (result == -1) return 0;
    if (result != 0) {
        *(void **)data_ov001_0216580c = item;
        Graphics_RefreshTwentyFourRecordsAndNotify();
    }
    return result;
}
