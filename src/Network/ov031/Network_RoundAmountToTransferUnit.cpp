#include <globaldefs.h>
ARM
extern "C" { extern unsigned char* data_02111304[]; extern int data_ov031_0224e1d0[]; int _Z20DisableIRQInterruptsv(); int _Z20SetIRQInterruptStatei(int); }
// Original: arm9/ov031 @ 0x022066B4; symbol: func_ov031_022066b4; size: 0xA4.
extern "C" int Network_RoundAmountToTransferUnit(int amount) {
 unsigned char* limits=*(unsigned char**)(data_02111304[1]+0xa4);
 int irq=_Z20DisableIRQInterruptsv();
 int unit;
 if(limits) {
  int first=*(unsigned short*)(limits+0x2e);
  int second;
  if(first && (second=*(unsigned short*)(limits+0x2c))) {
   int maximum=data_ov031_0224e1d0[9];
   if(first>second) first=second;
   if(first>maximum) first=maximum;
   unit=first*2;
  } else unit=data_ov031_0224e1d0[9]*2;
 } else unit=data_ov031_0224e1d0[9]*2;
 _Z20SetIRQInterruptStatei(irq);
 if(unit>0) {
  int quotient=amount/unit;
  if(quotient>0) return unit*quotient;
 }
 return amount;
}
