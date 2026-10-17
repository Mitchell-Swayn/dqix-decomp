#include <globaldefs.h>
ARM
#pragma optimization_level 2
extern "C" unsigned char data_ov031_0224c980;
struct ContextGlobal { unsigned char pad[0x54]; void* volatile context; };
extern "C" void Network_AppendValidatedFrameToRing(void*, void*, unsigned, unsigned, unsigned, unsigned);
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x02200AA0; symbol: func_ov031_02200aa0; size: 0x58.
extern "C" void System_MarkSharedContextReady(void* a, void* b, unsigned c, unsigned d) {
    Network_AppendValidatedFrameToRing(a, b, c, d, 0, 0);
    if (((ContextGlobal*)&data_ov031_0224c980)->context != 0) {
        if (_Z17IsContextInactiveP16ProcessorContext(((ContextGlobal*)&data_ov031_0224c980)->context) == 0)
            _Z25MarkContextReadyAndSwitchP16ProcessorContext(((ContextGlobal*)&data_ov031_0224c980)->context);
    }
}
