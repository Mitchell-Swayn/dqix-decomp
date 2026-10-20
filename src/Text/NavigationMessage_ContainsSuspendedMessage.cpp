#include <globaldefs.h>

// Original: arm9/main @ 0x020949BC; symbol: func_020949bc; size: 0x44.
extern "C" ARM int NavigationMessage_ContainsSuspendedMessage(char* p, int value)
{
    int i = 0;
    while (i < *(signed char*)(p + 0x3cc)) {
        short entry = *(short*)(p + i * 0x34 + 0x1d0);
        if (entry == value)
            return 1;
        ++i;
    }
    return 0;
}
