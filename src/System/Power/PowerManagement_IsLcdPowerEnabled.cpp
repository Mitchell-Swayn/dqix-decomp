#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020CEDE0; symbol: func_020cede0; size: 0x1C.
bool PowerManagement_IsLcdPowerEnabled(){return (*(volatile unsigned short *)0x04000304&1)!=0;}
}
