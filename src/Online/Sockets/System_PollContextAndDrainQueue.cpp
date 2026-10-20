#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void *);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void *);
// Original data: arm9/ov031 @ 0x224cb28; symbol: data_ov031_0224cb28.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemPollContextAndDrainQueue_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022004D4; symbol: func_ov031_022004d4; size: 0x50.
extern "C" int System_PollContextAndDrainQueue(void) {
    int irq = _Z20DisableIRQInterruptsv();
    int inactive = _Z17IsContextInactiveP16ProcessorContext(SystemPollContextAndDrainQueue_UnknownRoleZeroInitializedStorage);
    if (!inactive && *(unsigned int *)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage + 0x44) == 0) {
        *(unsigned int *)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage + 0x44) = 1;
        _Z25MarkContextReadyAndSwitchP16ProcessorContext(SystemPollContextAndDrainQueue_UnknownRoleZeroInitializedStorage);
    }
    _Z20SetIRQInterruptStatei(irq);
    return inactive;
}
