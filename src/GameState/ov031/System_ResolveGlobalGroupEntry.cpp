#include <globaldefs.h>
ARM
extern "C" unsigned char *data_ov031_02290d00;
extern "C" int ResolveGroupEntryAndInvokeOwnerHandler(unsigned owner, unsigned source, unsigned index);
// Original: arm9/ov031 @ 0x02236878; symbol: func_ov031_02236878; size: 0x24.
extern "C" int System_ResolveGlobalGroupEntry(unsigned int index) {
    return ResolveGroupEntryAndInvokeOwnerHandler((unsigned int)(data_ov031_02290d00 + 0x94), 0, index);
}
