#include <globaldefs.h>
ARM
extern "C" {
int _Z20DisableIRQInterruptsv();
int _Z20SetIRQInterruptStatei(int);
void Network_ConfigureExtendedScanParameters(const void*,const unsigned char*,void*);
void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
int Network_StartExtendedScan(void*,void*);
void SetSharedStateAndManageStateNineAlarm(int);
void func_ov031_0220defc();
extern char* data_ov031_0224e53c;
}
// Original: arm9/ov031 @ 0x0220CDF4; symbol: func_ov031_0220cdf4; size: 0x178.
extern "C" int Network_RequestExtendedScan(const void* address,const unsigned char* name,void* config){
int irq=_Z20DisableIRQInterruptsv();
if(!data_ov031_0224e53c){_Z20SetIRQInterruptStatei(irq);return 1;}
switch(*(int*)(data_ov031_0224e53c+0x2260)){
case 3:break;
case 5:Network_ConfigureExtendedScanParameters(address,name,config);_Z20SetIRQInterruptStatei(irq);return 2;
case 6:Network_ConfigureExtendedScanParameters(address,name,config);_Z20SetIRQInterruptStatei(irq);return 0;
default:_Z20SetIRQInterruptStatei(irq);return 1;
}
Network_ConfigureExtendedScanParameters(address,name,config);
_Z24InvalidateDataCacheRangePKvj(*(void**)(data_ov031_0224e53c+0x2288),*(unsigned short*)(data_ov031_0224e53c+0x228c));
(*(unsigned*)(data_ov031_0224e53c+0x2284))++;
switch(Network_StartExtendedScan((void*)func_ov031_0220defc,data_ov031_0224e53c+0x2288)){
case 2:SetSharedStateAndManageStateNineAlarm(5);*(unsigned short*)(data_ov031_0224e53c+0x2280)=3;break;
case 8:_Z20SetIRQInterruptStatei(irq);return 4;
case 3:default:SetSharedStateAndManageStateNineAlarm(11);_Z20SetIRQInterruptStatei(irq);return 7;
}
_Z20SetIRQInterruptStatei(irq);return 3;
}
