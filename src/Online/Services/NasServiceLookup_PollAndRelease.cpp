#include <globaldefs.h>
ARM
extern "C" void NasServiceLocator_DestroySession(void);
extern "C" unsigned NasServiceLocator_PollRequest(void);
// Original: arm9/ov031 @ 0x02212598; symbol: Unclassified_ReadStateAndNotifyForValuesThreeToFive; size: 0x24.
// Reads the current value, calls the notifier only for values 3 through 5 inclusive, and returns the value.
extern "C" unsigned NasServiceLookup_PollAndRelease(void) {
    unsigned value = NasServiceLocator_PollRequest();
    if (value - 3 <= 2) NasServiceLocator_DestroySession();
    return value;
}
