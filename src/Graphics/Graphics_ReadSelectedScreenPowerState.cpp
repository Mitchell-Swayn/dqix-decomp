// Original: arm9/main @ 0x020DB9A8; symbol: func_020db9a8; size: 0x24.
extern "C" int Graphics_ReadSelectedScreenPowerState(unsigned char* p){int v;if(p[0x54]==0)v=(*(volatile unsigned short*)0x04000304 & 0x8000)>>15;else v=0;return v;}
