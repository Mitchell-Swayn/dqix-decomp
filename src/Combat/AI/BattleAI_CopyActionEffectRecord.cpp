#include <globaldefs.h>
#pragma force_active on
// copies ten bytes as one word followed by six byte copies.
// Original: arm9/ov024 @ 0x021F6A4C; symbol: func_ov024_021f6a4c; size: 0x3c.
extern "C" void BattleAI_CopyActionEffectRecord(unsigned char* dst, const unsigned char* src) { *(unsigned int*)dst=*(const unsigned int*)src; dst[4]=src[4]; dst[5]=src[5]; dst[6]=src[6]; dst[7]=src[7]; dst[8]=src[8]; dst[9]=src[9]; }
