#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088854; symbol: func_02088854; size: 0x20.
void CombatStatus_ApplyDazzle(char *p){p[0x5f]=4;p[0x82]=0;*(unsigned int *)(p+20)|=64;}
}
