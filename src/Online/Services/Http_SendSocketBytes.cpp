#include <globaldefs.h>
extern "C" int Network_SendSocket(int, int, int, int);
// Original: arm9/ov031 @ 0x022414CC; symbol: func_ov031_022414cc; size: 0x4C.
extern "C" int Http_SendSocketBytes(void *context, int a, int b, int c, int d) {
    int result = Network_SendSocket(a, b, c, d);
    if (result >= 0) return result;
    if (*(void **)((char *)context + 4)) return -1002;
    if (result == -56) return 0;
    return -1001;
}
