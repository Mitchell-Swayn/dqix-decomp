#include <globaldefs.h>
ARM
extern "C" void func_ov004_0216856c(void *);
extern "C" void func_ov011_021848a0(void *, unsigned int);
// Original: arm9/ov004 @ 0x021683CC; symbol: func_ov004_021683cc; size: 0x20.
extern "C" int Unclassified_InitializeObjectAndSetState2(void *object) {
    func_ov004_0216856c(object);
    func_ov011_021848a0(object, 2);
    return 0;
}
