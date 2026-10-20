#include <globaldefs.h>
// Original: arm9/main @ 0x02026F08; symbol: func_02026f08; size: 0x18.
extern "C" ARM void PartyStatus_SetMemberChangeAnimationEnabled(char* p, int i, int n) { char* record = p+i; record[0x558] = n != 0; }
