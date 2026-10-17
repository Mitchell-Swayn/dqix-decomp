#include <globaldefs.h>
ARM
extern "C" int _Z13ReleaseGBABust(unsigned short); extern "C" void _Z20SetIRQInterruptStatei(int);
// Original: arm9/main @ 0x020D1540; symbol: func_020d1540; size: 0x24.
 extern "C" void System_ReleaseGBABusAndRestoreIRQState(unsigned short owner,int* state) { if (state[0]==0) _Z13ReleaseGBABust(owner); _Z20SetIRQInterruptStatei(state[1]); }
