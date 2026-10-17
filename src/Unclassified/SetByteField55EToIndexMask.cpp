#include <globaldefs.h>

// Original: arm9/main @ 0x0202006C; symbol: func_0202006c; size: 0x18.
extern "C" ARM void SetByteField55EToIndexMask (char* p, int n) { p[0x55e] = n < 0 ? 15 : (1 << n); }
