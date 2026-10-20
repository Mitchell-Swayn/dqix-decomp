// Original: arm9/main @ 0x0200D958; symbol: func_0200d958; size: 0x8C.
// Compiler runtime support: __DecodeSignedNumber.
// Already matching C retained; excluded from further C reconstruction.
#pragma opt_repositioncode off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma optimize_for_size off
#include <globaldefs.h>
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef int s32; typedef unsigned long long u64;
ARM
extern "C" signed char *Runtime_DecodeCompactSignedInteger(signed char *src, u32 *out) {
 s32 first=src[0];
 if (!(first & 1)) { *out=first>>1; return src+1; }
 unsigned char second=(u8)src[1];
 if (!(first & 2)) { *out=second | ((u32)(first>>2)<<8); return src+2; }
 unsigned char third=(u8)src[2];
 if (!(first & 4)) { u32 result=((u32)(first>>3)<<16) | (second<<8); *out=third | result; return src+3; }
 u32 fourth=(u8)src[3]; u32 result=((u32)(first>>3)<<24) | (second<<16); result |= third<<8; *out=fourth | result; return src+4;
}
