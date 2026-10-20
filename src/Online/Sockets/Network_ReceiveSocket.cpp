#include <globaldefs.h>
ARM
extern "C" void Network_ReceiveSocketData(void *, void *, void *, int, int, int);
// Original: arm9/ov031 @ 0x022072AC; symbol: func_ov031_022072ac; size: 0x24.
extern "C" void Network_ReceiveSocket(void *arg0, void *arg1, void *arg2, int arg3) {
    Network_ReceiveSocketData(arg0, arg1, arg2, 0, 0, arg3);
}
