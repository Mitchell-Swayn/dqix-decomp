#include <globaldefs.h>
ARM
extern "C" unsigned IPC_SendTwoWordCommandAndStoreCallbackState(int,int,int,unsigned,unsigned);
// Original: arm9/main @ 0x020CE5B0; symbol: func_020ce5b0; size: 0x64.
extern "C" unsigned MapModeToCommandSelectorOrInvalidFFFF(int mode,unsigned a,unsigned b) { int selection; switch(mode) { case 1:selection=1;break; case 3:selection=2;break; case 2:selection=3;break; default:selection=0;break; } if(!selection) return 0xffff; return IPC_SendTwoWordCommandAndStoreCallbackState(selection,0,0,a,b); }
