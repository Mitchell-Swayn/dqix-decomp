#include <globaldefs.h>
ARM
extern "C" void Graphics_SetMainDisplayModeAndSelection(unsigned short,unsigned,int);
extern "C" unsigned data_ov016_0219d144[];
extern "C" char data_027e0000[];
// Original: arm9/ov016 @ 0x0218D034; symbol: func_ov016_0218d034; size: 0xA0.
extern "C" void Graphics_ToggleDisplayModeAndSignal() {
if(!data_ov016_0219d144[12]) {
data_ov016_0219d144[12]=1;
if(data_ov016_0219d144[1]==0) {
Graphics_SetMainDisplayModeAndSelection(6,0,0);
*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x1000;
} else {
Graphics_SetMainDisplayModeAndSelection(2,0,0);
*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x400;
}
data_ov016_0219d144[1]^=1;
}
char* flags=data_027e0000;
flags+=0x3000;
*(unsigned*)(flags+0xff8)|=1;
}
