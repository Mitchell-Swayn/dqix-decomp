#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021634C8; symbol: func_ov000_021634c8; size: 0x5C.
// Appends a value to the signed halfword list at 0x6fba only when it is absent.
extern "C" void CombatScene_AddUniqueOriginalTarget(unsigned char* self,int value) {
 int i;
 for(i=0;i<*(short*)(self+0x6fc2);++i)if(value==*(short*)(self+0x6fba+i*2))break;
 if(i==*(short*)(self+0x6fc2)) {
  *(short*)(self+0x6fba+(*(short*)(self+0x6fc2))++*2)=value;
 }
}
