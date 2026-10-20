#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0223DD34; symbol: func_ov031_0223dd34; size: 0x2C.
extern "C" unsigned int WfcUtility_CountNonzeroBytePrefix(const unsigned char *bytes, int length) {
    int count = 0;
    if (length <= 0)
        goto done;
loop:
    if (bytes[count] == 0)
        goto done;
    ++count;
    if (count < length)
        goto loop;
done:
    return count;
}
