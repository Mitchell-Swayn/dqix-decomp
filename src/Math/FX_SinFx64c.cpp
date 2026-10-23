#include <globaldefs.h>
ARM
typedef unsigned long long u64;
typedef long long fx64c;
#define SDK_FOUR_PI ((fx64c)0x0000000145f306ddLL)
extern "C" u64 FX_SinFx64c_internal(u64);
extern "C" u64 FX_CosFx64c_internal(u64);
// SDK C: ntrtwl/NitroSDK 9eec6c92c9d7bba9350732b11296ed16aab3a8bc libraries/fx/src/fx_trig.c.
// Original: arm9/main @ 0x020C3260; symbol: func_020c3260; size: 0x98.
extern "C" fx64c FX_SinFx64c (int rad)
{
	fx64c y;
	fx64c rval;
	int n;

	if (rad < 0) {
		return -FX_SinFx64c(-rad);
	}

	y = (fx64c)((SDK_FOUR_PI * rad) >> 12);
	n = (int)(y >> 32);
	y = y & 0xffffffff;

	if (n & 1) {
		y = 0x100000000LL - y;
	}

	if ((n + 1) & 2) {
		rval = (fx64c)FX_CosFx64c_internal((u64)y);
	} else {
		rval = (fx64c)FX_SinFx64c_internal((u64)y);
	}

	if ((n & 7) > 3) {
		rval = -rval;
	}

	return rval;
}

