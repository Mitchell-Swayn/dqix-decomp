#include <globaldefs.h>
ARM
extern "C" void NetworkSocket_Close(void *);
// Original: arm9/ov031 @ 0x022413B8; symbol: func_ov031_022413b8; size: 0x10.
extern "C" void Http_CloseSocket(void *unused, void *p) { NetworkSocket_Close(p); }
