#include <globaldefs.h>
ARM
extern "C" {extern char* data_ov031_0224e53c;int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);void SetSharedStateAndManageStateNineAlarm(int);}
// Original: arm9/ov031 @ 0x0220CF6C; symbol: func_ov031_0220cf6c; size: 0xA4.
extern "C" int Network_RequestSharedStateSeven(){
int irq=_Z20DisableIRQInterruptsv();
if(!data_ov031_0224e53c){_Z20SetIRQInterruptStatei(irq);return 1;}
switch(*(int*)(data_ov031_0224e53c+0x2260)){
case 6:SetSharedStateAndManageStateNineAlarm(7);*(unsigned short*)(data_ov031_0224e53c+0x2280)=4;break;
case 7:_Z20SetIRQInterruptStatei(irq);return 2;
case 3:_Z20SetIRQInterruptStatei(irq);return 0;
default:_Z20SetIRQInterruptStatei(irq);return 1;
}
_Z20SetIRQInterruptStatei(irq);return 3;
}
