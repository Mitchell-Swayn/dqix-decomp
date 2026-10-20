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
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" State* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
extern "C" void Unclassified_InitializeArithmeticHelpers(ProcessorContext**);
// Original: arm9/ov031 @ 0x0220DA1C; symbol: func_ov031_0220da1c; size: 0x98.
extern "C" void Network_SetWirelessStateAndConnectionAlarm(int state) {
    int irq=DisableIRQInterrupts();
    State* obj=NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
    if(obj->value==9 && state!=9)CancelAlarm(&obj->alarm);
    State* current=NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
    if(current->value!=11)current->value=state;
    if(state==9)SetTimeout(&NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage->alarm,0x22f5341,Unclassified_InitializeArithmeticHelpers,0);
    SetIRQInterruptState(irq);
}
