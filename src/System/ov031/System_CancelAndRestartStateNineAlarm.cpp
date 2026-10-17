#include <globaldefs.h>
ARM

struct Alarm;
struct ProcessorContext;
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z11CancelAlarmP5Alarm(Alarm *);
extern "C" void _Z10SetTimeoutP5AlarmyPFvPP16ProcessorContextES3_(Alarm *, unsigned long long, void (*)(ProcessorContext **), ProcessorContext **);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void *data_ov031_0224e53c;
extern "C" void Unclassified_InitializeArithmeticHelpers(ProcessorContext **);

// Original: arm9/ov031 @ 0x0220DAB4; symbol: func_ov031_0220dab4; size: 0x74.
extern "C" void System_CancelAndRestartStateNineAlarm(void) {
    int irqState = _Z20DisableIRQInterruptsv();
    _Z11CancelAlarmP5Alarm((Alarm *)((unsigned char *)data_ov031_0224e53c + 0x22CC));
    if (*((unsigned int *)((unsigned char *)data_ov031_0224e53c + 0x2260)) == 9) {
        _Z10SetTimeoutP5AlarmyPFvPP16ProcessorContextES3_((Alarm *)((unsigned char *)data_ov031_0224e53c + 0x22CC), 0x022F5341ULL, Unclassified_InitializeArithmeticHelpers, (ProcessorContext **)0);
    }
    _Z20SetIRQInterruptStatei(irqState);
}
