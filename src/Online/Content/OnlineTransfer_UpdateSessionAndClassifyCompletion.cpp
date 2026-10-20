#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void OnlineTransfer_DispatchOperationPhase(void *record);
// Original: arm9/ov031 @ 0x022436E0; symbol: func_ov031_022436e0; size: 0x28.
extern "C" int OnlineTransfer_UpdateSessionAndClassifyCompletion(unsigned char *record) {
    _ZN9GameState11GetInstanceEv();
    OnlineTransfer_DispatchOperationPhase(record);
    return record[0x36] != 0 ? 2 : 1;
}
