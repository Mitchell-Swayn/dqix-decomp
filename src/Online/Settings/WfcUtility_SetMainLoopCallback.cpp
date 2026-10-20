#include <globaldefs.h>

typedef void (*MainLoopCallback)(void);

// Layout projection of the shared overlay state; earlier fields are unreconstructed.
struct OverlayMainLoopState
{
    unsigned char preceding_state[0xC];
    MainLoopCallback callback;
};

// Original data: arm9/ov031 @ 0x2250c0c; symbol: data_ov031_02250c0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" OverlayMainLoopState Ov031GetStatusCode_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov031 @ 0x022274C0; symbol: func_ov031_022274c0; size: 0x10.
// Installs the callback invoked each iteration by the loop at 0x02226FE4.
// The overlay's broader subsystem remains unclassified.
extern "C" ARM void WfcUtility_SetMainLoopCallback(MainLoopCallback callback)
{
    Ov031GetStatusCode_UnknownRoleZeroInitializedStorage.callback = callback;
}
