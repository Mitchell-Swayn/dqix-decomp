#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x0221E5B4; symbol: System_ForwardCallbackRecordSelection; size: 0x8.
// Forwards the callback selector arguments to the routine that chooses one of two static callback records.
extern "C" void Network_CreateSocketByType(int, int);
extern "C" void System_ForwardCallbackRecordSelection(int object, int selector) {
    Network_CreateSocketByType(object, selector);
}
