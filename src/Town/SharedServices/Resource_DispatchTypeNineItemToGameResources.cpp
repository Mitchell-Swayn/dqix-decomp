#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance();
extern "C" void OnlineDownload_TryRequestTransferStop(void *, void *);
// Original: arm9/ov003 @ 0x02172570; symbol: Resource_DispatchTypeNineItemToGameResources; size: 0x34.
// Handles only type byte 9 and passes GameResources +0x3b48 and the item to the type-nine handler.
extern "C" int Resource_DispatchTypeNineItemToGameResources(const unsigned char *type, void *item) {
    if (*type != 9)
        return 0;
    unsigned char *resources = (unsigned char *)GameResources_GetInstance();
    void *record = *(void **)(resources + 0x3b48);
    OnlineDownload_TryRequestTransferStop(record, item);
    return 1;
}
