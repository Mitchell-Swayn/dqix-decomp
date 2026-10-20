#include <globaldefs.h>
ARM
#pragma opt_common_subs off
extern "C" void OS_IrqHandler();
struct Registration {unsigned a,b;void(*token)();unsigned references;};
// Original: arm9/ov031 @ 0x0220F2E0; symbol: func_ov031_0220f2e0; size: 0x50.
extern "C" int Network_AcquireItcmTokenReference(Registration* registration){if(!registration->token){registration->token=OS_IrqHandler;++registration->references;return 1;}if(registration->token!=OS_IrqHandler)return 0;++registration->references;return 1;}
