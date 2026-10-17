#include <globaldefs.h>
ARM
extern "C" void _Z20AddContextSwitchLockv(void);
extern "C" void _Z23RemoveContextSwitchLockv(void);
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
extern "C" void* data_ov031_0224e580;
// Original: arm9/ov031 @ 0x0220F558; symbol: func_ov031_0220f558; size: 0x5C.
extern "C" unsigned System_UnlockAndSwitchReadyContext(void) {
    volatile unsigned short* ime = (volatile unsigned short*)0x04000208;
    unsigned short previous = *ime;
    *ime = 0;
    _Z20AddContextSwitchLockv();
    if (!_Z17IsContextInactiveP16ProcessorContext((char*)data_ov031_0224e580 + 0x34))
        _Z25MarkContextReadyAndSwitchP16ProcessorContext((char*)data_ov031_0224e580 + 0x34);
    _Z23RemoveContextSwitchLockv();
    unsigned current = *ime;
    *ime = previous;
    return current;
}
