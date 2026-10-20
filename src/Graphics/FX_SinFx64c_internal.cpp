#include <globaldefs.h>
ARM
typedef unsigned long long u64;
// Original: arm9/main @ 0x020C30AC; symbol: FX_SinFx64c_internal; size: 0xE8.
// SDK FX_SinFx64c_internal: evaluates the sine polynomial for a reduced unsigned
// 32.32 argument, with the exact sqrt(1/2) result at 1.0.
extern "C" u64 FX_SinFx64c_internal(u64 y) {
    u64 tmp;
    u64 yy;
    if (y == 0x100000000ULL) return 0xb504f334ULL;
    yy = y*y >> 32;
    tmp = 0x100000000ULL - (36796552ULL*yy >> 32);
    tmp = 0x100000000ULL - ((63079804ULL*yy >> 32)*tmp >> 32);
    tmp = 0x100000000ULL - ((132467588ULL*yy >> 32)*tmp >> 32);
    tmp = 3373259426ULL - ((346799334ULL*yy >> 32)*tmp >> 32);
    return tmp*y >> 32;
}
