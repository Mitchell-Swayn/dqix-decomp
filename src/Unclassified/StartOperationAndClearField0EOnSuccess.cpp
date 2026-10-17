#include <globaldefs.h>

extern "C" int data_021015a0[];
extern "C" void Network_SetStateFromCallbackError();
extern "C" int SubmitOperationTwoAndNormalizePendingResult(void (*callback)());

// Original: arm9/main @ 0x0202DF10; symbol: func_0202df10; size: 0x48.
extern "C" int StartOperationAndClearField0EOnSuccess()
{
    data_021015a0[4] = 3;
    int result = SubmitOperationTwoAndNormalizePendingResult(Network_SetStateFromCallbackError);
    if (result != 2) {
        data_021015a0[4] = 9;
        return 0;
    }
    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(data_021015a0) + 0xe) = 0;
    return 1;
}
