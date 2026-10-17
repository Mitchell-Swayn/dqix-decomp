#include <globaldefs.h>
struct ZeroPair { int a; int b; };
// Original: arm9/main @ 0x020D2CE0; symbol: func_020d2ce0; size: 0x20.
extern "C" ARM void WordPair_ClearWithVolatileTemporary(ZeroPair* p)
{
    volatile ZeroPair temp;
    p->a = 0;
    temp.a = 0;
    temp.b = 0;
    p->b = 0;
}
