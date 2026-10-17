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
extern "C" ScanlineAlarmState data_02111654;
extern "C" unsigned int Timer_ExtendWrappingCounter(int scanline);
extern "C" int ClassifyDayAndTickDeltaAgainstStoredLimit(ScanlineAlarm*, unsigned int frame, int scanline);
extern "C" void System_ConfigureInterruptFourAndDisplayStatusBit(ScanlineAlarm*);
extern "C" void LinkedList_UnlinkNodeFromGlobalDoublyLinkedList(ScanlineAlarm*);
extern "C" void SortedTimerQueue_InsertByKeyAndPriority(ScanlineAlarm*);
#pragma optimize_for_size off
// Original: arm9/main @ 0x020C94E4; symbol: func_020c94e4; size: 0x178.
extern "C" void HandleScanlineInterruptAndRecordFiredMask()
{
    DisableSpecificInterrupts(4);
    volatile unsigned short* displayStatus = (volatile unsigned short*)0x04000004;
    *displayStatus &= ~0x20;
    DTCM_DATA_INTERRUPTS_FIRED |= 4;
    unsigned short status = *displayStatus;
    Timer_ExtendWrappingCounter(((unsigned char)(status >> 8) | ((status << 1) & 0x100)) - 1);
    ScanlineAlarm* alarm = data_02111654.first;
    if (!alarm) return;
    volatile unsigned short* scanlineRegister = (volatile unsigned short*)0x04000006;
    do {
        unsigned short scanline = *scanlineRegister;
        unsigned int frame = Timer_ExtendWrappingCounter(scanline);
        int state = ClassifyDayAndTickDeltaAgainstStoredLimit(alarm, frame, scanline);
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
                alarm->frame = data_02111654.frame + 1;
                SortedTimerQueue_InsertByKeyAndPriority(alarm);
            }
            break;
        }
        case 2:
            LinkedList_UnlinkNodeFromGlobalDoublyLinkedList(alarm);
            alarm->frame = data_02111654.frame + 1;
            SortedTimerQueue_InsertByKeyAndPriority(alarm);
            break;
        }
        alarm = data_02111654.first;
    } while (alarm);
}
