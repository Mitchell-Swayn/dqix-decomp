#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);extern "C" unsigned char* data_021142e0[];
// Original: arm9/main @ 0x020D46FC; symbol: func_020d46fc; size: 0x30.
extern "C" unsigned int WirelessCommand_ReadSharedWord14CLowHalfwordAtomically() { int state=_Z20DisableIRQInterruptsv();unsigned char* p=data_021142e0[1];unsigned int value=p ? *(unsigned int*)(p+0x14c) : 0;_Z20SetIRQInterruptStatei(state);return (unsigned short)value; }
