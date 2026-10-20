#include <globaldefs.h>
ARM
extern "C" void *SystemState_GetGlobalFlags(); extern "C" int SystemState_TestAnyFlags(void *,int);
// Original: arm9/main @ 0x02027438; symbol: func_02027438; size: 0x134.
extern "C" void Graphics_UpdateSubBackgroundScrollByDisplayMode(char *self) { if(SystemState_TestAnyFlags(SystemState_GetGlobalFlags(),65)) return; int x,y; switch(*(int *)(self+20)) { case 0: x=*(int *)(self+68); if(x<0)x=x%8+8; else x=x%8; y=*(int *)(self+72); if(y<0)y=y%8+8; else y=y%8; *(volatile unsigned *)0x04001010=((x+128)&511)|(((y+32)<<16)&0x1ff0000); return; case 2: case 3:y=*(int *)(self+72); if(y<0)y=y%8+8; else y=y%8; *(volatile unsigned *)0x04001010=((y+32)<<16)&0x1ff0000; return; case 4:y=*(int *)(self+72); if(y<0)y=y%8+8; else y=y%8; *(volatile unsigned *)0x04001010=((32-y)<<16)&0x1ff0000; return; default:*(volatile unsigned *)0x04001010=0; return; } }
