#include <globaldefs.h>
extern "C" int ValidateStatusFiveAndDispatchCommandEleven(void *);
extern "C" void SetGlobalValueExceptModesNineAndTen(int);
extern "C" void Network_HandleRestartCompletionAndPendingMode(void);

// Original: arm9/main @ 0x0202D0E0; symbol: func_0202d0e0; size: 0x28.
extern "C" int PollCallbackUntilStatusTwo(void) {
    int result = ValidateStatusFiveAndDispatchCommandEleven((void *)Network_HandleRestartCompletionAndPendingMode);
    if (result != 2) {
        SetGlobalValueExceptModesNineAndTen(result);
        return 0;
    }
    return 1;
}
