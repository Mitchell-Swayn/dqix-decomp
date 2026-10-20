#include <globaldefs.h>
ARM
extern "C" int OnlineError_IsSet(unsigned int, unsigned int, unsigned int);
extern "C" int DlcDownload_RequestFileContents(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02212C84; symbol: func_ov031_02212c84; size: 0x38.
extern "C" int DownloadService_RequestFileContents(unsigned int a, unsigned int b, unsigned int c) {
    if (OnlineError_IsSet(a, b, c) != 0) return 0;
    return DlcDownload_RequestFileContents(a, b, c, 0);
}
