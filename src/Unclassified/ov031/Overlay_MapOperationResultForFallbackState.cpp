#include <globaldefs.h>
ARM
extern "C" int Unclassified_InvokeHelperWithTwoZerosAndForwardedSixthArgument(int, int, int, int);
// Original: arm9/ov031 @ 0x02241480; symbol: func_ov031_02241480; size: 0x4C.
extern "C" int Overlay_MapOperationResultForFallbackState(void* self, int a, int b, int c, int d) {
    int result = Unclassified_InvokeHelperWithTwoZerosAndForwardedSixthArgument(a, b, c, d);
    if (result >= 0) return result;
    if (*(void**)((char*)self + 4) != 0) return -1002;
    if (result == -56) return 0;
    return -1001;
}
