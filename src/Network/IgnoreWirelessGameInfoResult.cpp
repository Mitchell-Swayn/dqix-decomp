#include <globaldefs.h>
// Original: arm9/main @ 0x0202AEBC; symbol: func_0202aebc; size: 0x4.
// WM_SetGameInfo completion callback registered by UpdateSequenceAndSubmitEnabledState.
// WMCallbackFunc is void (*)(void*); the completion result is intentionally ignored.
extern "C" ARM void IgnoreWirelessGameInfoResult(void* result) {
}
