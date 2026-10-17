#include <globaldefs.h>
extern "C" int ValidateCartridgeIdentityUnderBusLock();extern "C" int System_ReadSharedFlagsValidByte();
// Original: arm9/main @ 0x020D131C; symbol: func_020d131c; size: 0x28.
extern "C" int TestFirstReadinessPredicateAndNegatedSecondPredicate() {if(ValidateCartridgeIdentityUnderBusLock() && !System_ReadSharedFlagsValidByte())return 1;return 0;}
