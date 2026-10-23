#include <globaldefs.h>
ARM
#pragma always_inline on
typedef unsigned u32;typedef unsigned short u16;typedef unsigned char u8;typedef int BOOL;typedef u16 MATHChecksum16Context;
#define FALSE 0
#define TRUE 1
// SDK C provenance: ntrtwl/NitroSDK 9eec6c92c9d7bba9350732b11296ed16aab3a8bc libraries/math/src/checksum.c.
static inline u32 MATHi_Checksum16Update (const void *input, u32 length)
{
	u32 sum;
	u32 n;
	BOOL fSwap = FALSE;

	sum = 0;

	if (((u32)input) & 1) {
		sum += (*((u8 *)input)++ << 8);
		length--;
		fSwap = TRUE;
	}

	while ((length >> 17) > 0) {
		length -= (1 << 17);
		for (n = (1 << 16); n > 0; n--) {
			sum += *((u16 *)input)++;
		}

		sum = (sum >> 16) + (sum & 0xffff);
		sum = (u16)((sum >> 16) + sum);
	}

	for (n = (length >> 1); n > 0; n--) {
		sum += *((u16 *)input)++;
	}

	if (length & 1) {
		sum += *((u8 *)input);
	}

	sum = (sum >> 16) + (sum & 0xffff);
	sum = (sum >> 16) + (sum & 0xffff);

	if (fSwap) {
		sum = ((sum << 24) | (sum << 8)) >> 16;
	}

	return sum;
}

// Original: arm9/main @ 0x020D1D1C; symbol: func_020d1d1c; size: 0xCC.
extern "C" void Checksum_UpdateOnesComplement16 (MATHChecksum16Context *context, const void *input, u32 length)
{
	u32 sum;

	sum = MATHi_Checksum16Update(input, length);

	sum += *context;
	sum += (sum >> 16);

	*context = (u16)sum;
}

