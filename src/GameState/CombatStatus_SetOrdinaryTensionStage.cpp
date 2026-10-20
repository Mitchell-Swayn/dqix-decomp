#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02088220; symbol: func_02088220; size: 0x14.
void CombatStatus_SetOrdinaryTensionStage(char *p,unsigned char v){*(unsigned int *)(p+0x14)|=0x800000;*(unsigned char *)(p+0x24)=v;}
}
