#include <globaldefs.h>
ARM
extern "C" void ApplyBytePermutationXorStream(void *);
// Original: arm9/ov031 @ 0x022093F4; symbol: func_ov031_022093f4; size: 0x18.
extern "C" int Ssl_DecryptRecordPayload(void *object, void *unused, int result) {
    ApplyBytePermutationXorStream((unsigned char *)object + 0x1e0);
    return result;
}
