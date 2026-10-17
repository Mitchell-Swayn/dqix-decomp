#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" {extern unsigned data_ov031_0224c980[];unsigned func_ov031_02200754(unsigned);unsigned func_ov031_02200790(unsigned);}
inline int IsConfiguredOrUnset(unsigned address){return data_ov031_0224c980[20]==0 || address==data_ov031_0224c980[20];}
inline int IsLocal(unsigned address){return IsConfiguredOrUnset(address)||address==0x7f000001;}
inline int IsLocalOrFirst(unsigned address){return IsLocal(address)||func_ov031_02200754(address);}
// Original: arm9/ov031 @ 0x022007A4; symbol: func_ov031_022007a4; size: 0x80.
extern "C" int Network_IsLocalOrAcceptedAddress(unsigned address){return IsLocalOrFirst(address)||func_ov031_02200790(address);}
