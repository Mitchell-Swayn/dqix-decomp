#include <globaldefs.h>
ARM
#pragma optimization_level 2
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
struct ContextGlobal { unsigned char pad[0x54]; void* volatile context; };
extern "C" void Network_AppendValidatedFrameToRing(void*, void*, unsigned, unsigned, unsigned, unsigned);
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x02200AA0; symbol: func_ov031_02200aa0; size: 0x58.
extern "C" void System_MarkSharedContextReady(void* a, void* b, unsigned c, unsigned d) {
    Network_AppendValidatedFrameToRing(a, b, c, d, 0, 0);
    if (((ContextGlobal*)&NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage)->context != 0) {
        if (_Z17IsContextInactiveP16ProcessorContext(((ContextGlobal*)&NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage)->context) == 0)
            _Z25MarkContextReadyAndSwitchP16ProcessorContext(((ContextGlobal*)&NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage)->context);
    }
}
