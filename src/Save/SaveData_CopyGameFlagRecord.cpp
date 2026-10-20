#include <globaldefs.h>
#pragma optimize_for_size off
// Original: arm9/main @ 0x020A99D0; symbol: func_020a99d0; size: 0x80.
extern "C" ARM void SaveData_CopyGameFlagRecord(unsigned char* dst,const unsigned char* src){int n=70;unsigned short* d;const unsigned short* s;s=(const unsigned short*)src;d=(unsigned short*)dst;do{--n;*d=*s;d++;s++;}while(n);n=564;unsigned char* d8;const unsigned char* s8;s8=src+140;d8=dst+140;do{--n;*d8=*s8;d8++;s8++;}while(n);n=6;s=(const unsigned short*)(src+704);d=(unsigned short*)(dst+704);do{--n;*d=*s;d++;s++;}while(n);n=102;s8=src+716;d8=dst+716;do{--n;*d8=*s8;d8++;s8++;}while(n);dst[818]=src[818];}
