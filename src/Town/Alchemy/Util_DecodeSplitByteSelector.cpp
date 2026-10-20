#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x0215745C; symbol: func_ov006_0215745c; size: 0x140.
extern "C" void Util_DecodeSplitByteSelector(int code,unsigned char* first,signed char* second) {
*second=-1;
switch(code) {
case 0x48:*second=0;break;
case 0x49:*second=1;break;
case 0x4a:*second=2;break;
case 0x4b:*second=3;break;
case 0x4c:*second=4;break;
case 0x4d:*second=5;break;
case 0x4e:*second=6;break;
case 0x4f:*second=7;break;
case 0x50:*second=8;break;
case 0x51:*second=9;break;
case 0x52:*second=10;break;
case 0x53:*second=11;break;
case 0x40:*second=12;break;
case 0x41:*first=4;break;
case 0x42:*first=2;break;
case 0x43:*first=5;break;
case 0x44:*first=3;break;
case 0x45:*first=6;break;
}
}
