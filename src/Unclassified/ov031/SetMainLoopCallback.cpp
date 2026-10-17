#include <globaldefs.h>

typedef void (*MainLoopCallback)(void);

// Layout projection of the shared overlay state; earlier fields are unreconstructed.
struct OverlayMainLoopState
{
    unsigned char preceding_state[0xC];
    MainLoopCallback callback;
};

extern "C" OverlayMainLoopState data_ov031_02250c0c;

// Original: arm9/ov031 @ 0x022274C0; symbol: func_ov031_022274c0; size: 0x10.
// Installs the callback invoked each iteration by the loop at 0x02226FE4.
// The overlay's broader subsystem remains unclassified.
extern "C" ARM void SetMainLoopCallback(MainLoopCallback callback)
{
    data_ov031_02250c0c.callback = callback;
}
