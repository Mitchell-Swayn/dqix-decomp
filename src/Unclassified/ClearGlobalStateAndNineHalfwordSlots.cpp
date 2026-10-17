#include <globaldefs.h>
ARM
extern "C" unsigned data_0211166c;extern "C" short data_02111670[];
// Original: arm9/main @ 0x020C9A54; symbol: func_020c9a54; size: 0x34.
extern "C" void ClearGlobalStateAndNineHalfwordSlots(){data_0211166c=0;int i=0;do{short* slot=data_02111670+i++;*slot=0;}while(i<9);}
