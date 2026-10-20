#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void WfcUtility_GetNavigationContext(unsigned *,unsigned *);
extern "C" void WfcUtility_CreateBottomButtonBar(int);
// Original: arm9/ov031 @ 0x02223568; symbol: WfcUtility_CreateBottomButtonsForDisplayMode; size: 0x38.
// Allocates the requested mode's sprites only when the second shared state word equals one.
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int mode) {
 unsigned state;
 WfcUtility_GetNavigationContext(0,&state);
 if(state!=1)return;
 WfcUtility_CreateBottomButtonBar(mode);
}
