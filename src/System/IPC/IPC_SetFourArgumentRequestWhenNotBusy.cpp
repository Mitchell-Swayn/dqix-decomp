#include <globaldefs.h>
ARM
extern "C" unsigned data_02111818[];extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" int RealTimeClock_ReadRegisterCommand16();
// Original: arm9/main @ 0x020CF1E0; symbol: func_020cf1e0; size: 0x7C.
extern "C" int IPC_SetFourArgumentRequestWhenNotBusy(unsigned a0,unsigned a1,unsigned a2,unsigned a3){int irq=_Z20DisableIRQInterruptsv();if(data_02111818[3]){_Z20SetIRQInterruptStatei(irq);return 1;}data_02111818[3]=1;_Z20SetIRQInterruptStatei(irq);data_02111818[8]=2;data_02111818[9]=0;data_02111818[5]=a0;data_02111818[6]=a1;data_02111818[4]=a2;data_02111818[7]=a3;return RealTimeClock_ReadRegisterCommand16()?0:3;}
