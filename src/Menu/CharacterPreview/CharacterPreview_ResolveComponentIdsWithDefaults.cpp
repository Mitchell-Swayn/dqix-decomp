#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021E5FDC; symbol: func_ov023_021e5fdc; size: 0xAC.
extern "C" void CharacterPreview_ResolveComponentIdsWithDefaults(void* unused,short* dst,const short* src) {
dst[0]=src[0];dst[1]=src[1];dst[2]=src[2];dst[3]=src[3];dst[4]=src[3];dst[5]=src[4];dst[6]=src[5];dst[7]=src[6];dst[8]=src[7];dst[9]=src[8];
if(dst[0]<0) dst[0]=1000;
if(dst[6]<0) dst[6]=994;
if(dst[1]<0) dst[1]=8001;
if(dst[5]<0) {
dst[5]=src[11];
if(dst[5]<0) dst[5]=8010;
}
}
