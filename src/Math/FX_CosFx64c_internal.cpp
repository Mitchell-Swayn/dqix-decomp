// Original: arm9/main @ 0x020C3194; symbol: func_020c3194; size: 0xcc.
#include <globaldefs.h>
typedef unsigned long long u64;
typedef long long fx64c;
#define FX64C_ONE ((fx64c)0x0000000100000000LL)
#define FX64C_SQRT1_2 ((fx64c)0x00000000b504f334LL)
#define SDK_COSCOEFF_1  ((u64) 1324675879LL)
#define SDK_COSCOEFF_2  ((u64) 220779313LL)
#define SDK_COSCOEFF_3  ((u64) 88311725LL)
#define SDK_COSCOEFF_4  ((u64) 47309853LL)

// Original ARM9 main @ 0x020c3194, symbol func_020c3194.
// SDK FX_CosFx64c_internal, pinned NitroSDK libraries/fx/src/fx_trig.c.
extern "C" ARM u64 FX_CosFx64c_internal (u64 y)
{
	u64 tmp;
	u64 yy;

	if (y == 0x100000000LL) {
		return (u64)FX64C_SQRT1_2;
	}

	yy = y * y >> 32;

	tmp = FX64C_ONE - (SDK_COSCOEFF_4 * yy >> 32);
	tmp = FX64C_ONE - ((SDK_COSCOEFF_3 * yy >> 32) * tmp >> 32);
	tmp = FX64C_ONE - ((SDK_COSCOEFF_2 * yy >> 32) * tmp >> 32);
	tmp = FX64C_ONE - ((SDK_COSCOEFF_1 * yy >> 32) * tmp >> 32);

	return tmp;
}
