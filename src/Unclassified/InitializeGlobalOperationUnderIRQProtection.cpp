#include <globaldefs.h>
ARM
extern "C" unsigned data_02111818[];extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" int InvokeOperationCode17();
// Original: arm9/main @ 0x020CF08C; symbol: func_020cf08c; size: 0x70.
extern "C" int InitializeGlobalOperationUnderIRQProtection(unsigned a0,unsigned a1,unsigned a2){int irq=_Z20DisableIRQInterruptsv();if(data_02111818[3]){_Z20SetIRQInterruptStatei(irq);return 1;}data_02111818[3]=1;_Z20SetIRQInterruptStatei(irq);data_02111818[8]=0;data_02111818[9]=0;data_02111818[5]=a0;data_02111818[4]=a1;data_02111818[7]=a2;return InvokeOperationCode17()?0:3;}
