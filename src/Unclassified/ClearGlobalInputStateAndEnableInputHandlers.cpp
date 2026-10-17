#include <globaldefs.h>
ARM
extern "C" unsigned data_02153628[];extern "C" unsigned char data_02114e30[];extern "C" unsigned char data_02114e54[];extern "C" void SetByteFieldAtOffset1C(void*,int);extern "C" void SetByteFieldAtOffset61(void*,int);
// Original: arm9/main @ 0x020E1114; symbol: func_020e1114; size: 0x40.
extern "C" void ClearGlobalInputStateAndEnableInputHandlers(){data_02153628[1]=0;data_02153628[2]=0;data_02153628[0]=0;SetByteFieldAtOffset1C(data_02114e30,1);SetByteFieldAtOffset61(data_02114e54,1);}
