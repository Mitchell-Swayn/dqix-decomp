#include "System/Interrupts.h"
#include "System/DTCM.h"
struct ScanlineAlarm {
    void (*callback)(void*);
    void* argument;
    unsigned int reserved;
    unsigned int frame;
    short scanline, delay;
    ScanlineAlarm* previous;
    ScanlineAlarm* next;
    unsigned int repeat;
    unsigned int reserved20;
    unsigned int cancelled;
};
struct ScanlineAlarmState {
    unsigned int initialized;
    int previousScanline;
    unsigned int frame;
    ScanlineAlarm* first;
    ScanlineAlarm* last;
};
// Original data: arm9/main @ 0x2111654; symbol: data_02111654.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" ScanlineAlarmState OSInitVAlarm_UnknownRoleZeroInitializedStorage;
extern "C" unsigned int Timer_ExtendWrappingCounter(int scanline);
extern "C" int ScanlineAlarm_ClassifyDeadlineWindow(ScanlineAlarm*, unsigned int frame, int scanline);
extern "C" void System_ConfigureInterruptFourAndDisplayStatusBit(ScanlineAlarm*);
extern "C" void LinkedList_UnlinkNodeFromGlobalDoublyLinkedList(ScanlineAlarm*);
extern "C" void ScanlineAlarm_InsertInDeadlineOrder(ScanlineAlarm*);
#pragma optimize_for_size off
// Original: arm9/main @ 0x020C94E4; symbol: func_020c94e4; size: 0x178.
extern "C" void ScanlineAlarm_HandleVCountInterrupt()
{
    DisableSpecificInterrupts(4);
    volatile unsigned short* displayStatus = (volatile unsigned short*)0x04000004;
    *displayStatus &= ~0x20;
    DTCM_DATA_INTERRUPTS_FIRED |= 4;
    unsigned short status = *displayStatus;
    Timer_ExtendWrappingCounter(((unsigned char)(status >> 8) | ((status << 1) & 0x100)) - 1);
    ScanlineAlarm* alarm = OSInitVAlarm_UnknownRoleZeroInitializedStorage.first;
    if (!alarm) return;
    volatile unsigned short* scanlineRegister = (volatile unsigned short*)0x04000006;
    do {
        unsigned short scanline = *scanlineRegister;
        unsigned int frame = Timer_ExtendWrappingCounter(scanline);
        int state = ScanlineAlarm_ClassifyDeadlineWindow(alarm, frame, scanline);
        switch (state) {
        case 0:
            System_ConfigureInterruptFourAndDisplayStatusBit(alarm);
            unsigned short currentScanline = *scanlineRegister;
            if (alarm->scanline != currentScanline || alarm->frame != frame) return;
            DisableSpecificInterrupts(4);
            *(scanlineRegister - 1) &= ~0x20;
            AcknowledgeSpecificInterrupts(4);
        case 1: {
            void (*callback)(void*) = alarm->callback;
            LinkedList_UnlinkNodeFromGlobalDoublyLinkedList(alarm);
            alarm->callback = 0;
            if (callback) callback(alarm->argument);
            if (alarm->repeat && !alarm->cancelled) {
                alarm->callback = callback;
                alarm->frame = OSInitVAlarm_UnknownRoleZeroInitializedStorage.frame + 1;
                ScanlineAlarm_InsertInDeadlineOrder(alarm);
            }
            break;
        }
        case 2:
            LinkedList_UnlinkNodeFromGlobalDoublyLinkedList(alarm);
            alarm->frame = OSInitVAlarm_UnknownRoleZeroInitializedStorage.frame + 1;
            ScanlineAlarm_InsertInDeadlineOrder(alarm);
            break;
        }
        alarm = OSInitVAlarm_UnknownRoleZeroInitializedStorage.first;
    } while (alarm);
}
