#include <globaldefs.h>
ARM
extern "C" unsigned* data_ov031_02290c48;
extern "C" int func_ov031_02222adc(void*);
extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/ov031 @ 0x02227BC8; symbol: func_ov031_02227bc8; size: 0xBC.
extern "C" int System_QuerySharedStateWithSnapshot(int fallback) {
 switch(data_ov031_02290c48[0]) {
 case 0: case 1: case 3: case 5: return 0;
 case 2: return 1;
 case 4: return 2;
 case 6: {
  int snapshot[58];
  if(func_ov031_02222adc(snapshot)!=1) DisableInterruptsAndHaltForever();
  if(snapshot[8]>=0 && snapshot[8]<=3 && snapshot[9]==1) return 3;
  return 5;
 }
 case 7: return 4;
 }
 return fallback;
}
