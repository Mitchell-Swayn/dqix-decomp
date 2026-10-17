#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" void func_02027b10(int, int);
extern "C" int data_020fdc4c[];
// Original: arm9/main @ 0x0201F390; symbol: func_0201f390; size: 0x24.
extern "C" int Script_DispatchIntegerToStoredTarget(Script::Parameter* parameter) {
    int value=parameter->ToInt();
    int target=data_020fdc4c[4];
    func_02027b10(target,value);
    return 1;
}
