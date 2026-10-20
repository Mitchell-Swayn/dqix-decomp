#include <globaldefs.h>
ARM
extern "C" int OnlineError_IsSet(void *destination, int index, int count);
extern "C" void VectorizedMemset(void *destination, int value, unsigned length);
extern "C" int DlcDownload_RequestFileList(void *destination, int index, int count);
// Original: arm9/ov031 @ 0x02212C3C; symbol: func_ov031_02212c3c; size: 0x48.
extern "C" int DownloadService_RequestFileList(void *destination, int index, int count) {
    if (OnlineError_IsSet(destination, index, count)) return 0;
    VectorizedMemset(destination, 0, count * 0xb0);
    return DlcDownload_RequestFileList(destination, index, count);
}
