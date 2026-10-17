#include <globaldefs.h>
ARM
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char* p,int a,void* b);
extern "C" char data_02108760[];
// Original: arm9/ov006 @ 0x02159F0C; symbol: func_ov006_02159f0c; size: 0x88.
extern "C" void Util_DispatchPendingModeOnce(char *self) {
    if (*(int*)(self + 0x3ac)) return;
    if (!*(int*)(self + 0x3a4)) return;
    switch (*(int*)(self + 0x39c)) {
    case 0: DispatchStoredHalfwordIndexWithTwoArguments(data_02108760, 10, 0); break;
    case 1: DispatchStoredHalfwordIndexWithTwoArguments(data_02108760, 12, 0); break;
    case 2: DispatchStoredHalfwordIndexWithTwoArguments(data_02108760, 11, 0); break;
    }
    *(int*)(self + 0x3ac) = 1;
}
