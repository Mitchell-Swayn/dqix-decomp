#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(int *, unsigned int);
// Original: arm9/ov004 @ 0x0215C094; symbol: func_ov004_0215c094; size: 0x18.
extern "C" int Menu_ResumeItemMarketAfterListing(int *state) {
    Menu_QueueScriptEntry(state, 0x387);
    return 0;
}
