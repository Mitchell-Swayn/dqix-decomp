#include <globaldefs.h>
ARM

struct Alarm;
struct ProcessorContext;
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z11CancelAlarmP5Alarm(Alarm *);
extern "C" void _Z10SetTimeoutP5AlarmyPFvPP16ProcessorContextES3_(Alarm *, unsigned long long, void (*)(ProcessorContext **), ProcessorContext **);
extern "C" int _Z20SetIRQInterruptStatei(int);
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
extern "C" void Unclassified_InitializeArithmeticHelpers(ProcessorContext **);

// Original: arm9/ov031 @ 0x0220DAB4; symbol: func_ov031_0220dab4; size: 0x74.
extern "C" void System_CancelAndRestartStateNineAlarm(void) {
    int irqState = _Z20DisableIRQInterruptsv();
    _Z11CancelAlarmP5Alarm((Alarm *)((unsigned char *)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage + 0x22CC));
    if (*((unsigned int *)((unsigned char *)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage + 0x2260)) == 9) {
        _Z10SetTimeoutP5AlarmyPFvPP16ProcessorContextES3_((Alarm *)((unsigned char *)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage + 0x22CC), 0x022F5341ULL, Unclassified_InitializeArithmeticHelpers, (ProcessorContext **)0);
    }
    _Z20SetIRQInterruptStatei(irqState);
}
