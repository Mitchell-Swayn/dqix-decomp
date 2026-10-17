#include <globaldefs.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
extern "C" {
extern char data_020fe9cc[];
// Original: arm9/main @ 0x0202ADF0; symbol: func_0202adf0; size: 0x28.
void Graphics_FlushAndUploadMainBackgroundScreenData(){CleanInvalidateCacheRange(data_020fe9cc,0x600);LoadToMainBG1ScreenData(data_020fe9cc,0,0x600);}
}
