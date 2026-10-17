#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv(); extern "C" void _Z20SetIRQInterruptStatei(int); extern "C" unsigned int data_021117b0[];
// Original: arm9/main @ 0x020CDAC4; symbol: func_020cdac4; size: 0x20.
 extern "C" void WriteGlobalValueUnderIRQProtection(unsigned int value) { int state=_Z20DisableIRQInterruptsv(); data_021117b0[1]=value; _Z20SetIRQInterruptStatei(state); }
