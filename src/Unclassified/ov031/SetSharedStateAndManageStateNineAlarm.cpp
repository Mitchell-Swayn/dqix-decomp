#pragma thumb off
// Field behavior reconstructed from original instructions; broader object semantics remain uncertain.
#include <System/Timing.h>
#include <System/Interrupts.h>
struct State {
    char pad[0x2260];
    int value;
    char gap[0x68];
    Alarm alarm;
};
extern "C" State* data_ov031_0224e53c;
extern "C" void Unclassified_InitializeArithmeticHelpers(ProcessorContext**);
// Original: arm9/ov031 @ 0x0220DA1C; symbol: func_ov031_0220da1c; size: 0x98.
extern "C" void SetSharedStateAndManageStateNineAlarm(int state) {
    int irq=DisableIRQInterrupts();
    State* obj=data_ov031_0224e53c;
    if(obj->value==9 && state!=9)CancelAlarm(&obj->alarm);
    State* current=data_ov031_0224e53c;
    if(current->value!=11)current->value=state;
    if(state==9)SetTimeout(&data_ov031_0224e53c->alarm,0x22f5341,Unclassified_InitializeArithmeticHelpers,0);
    SetIRQInterruptState(irq);
}
