#include <globaldefs.h>
ARM
extern "C" int OnlineError_IsSet(void *);
extern "C" int DlcDownload_RequestFileCount(void *);
// Original: arm9/ov031 @ 0x02212C18; symbol: func_ov031_02212c18; size: 0x24.
extern "C" int DownloadService_RequestFileCount(void *object) {
    if (OnlineError_IsSet(object) != 0)
        return 0;
    return DlcDownload_RequestFileCount(object);
}
