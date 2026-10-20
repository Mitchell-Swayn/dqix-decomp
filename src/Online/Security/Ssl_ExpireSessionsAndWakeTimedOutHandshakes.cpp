#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/ProcessorContext.h>
ARM
#pragma force_active on
#pragma optimization_level 4
struct Cache {char first[0x20];char second[0x30];unsigned timestamp,address;unsigned short port;unsigned char valid,pad;};
struct TimedSslSocket {
    ProcessorContext* waitingContext;
    int waitState;
    unsigned char state, timeoutEnabled;
    unsigned short padding;
    unsigned char* crypto;
    unsigned timestamp;
};
// Original data: arm9/ov031 @ 0x0224E3B8; symbol: data_ov031_0224e3b8.
// Zero-initialized mutable storage; four 0x5c-byte entries are accessed here.
// This observed span does not establish the full logical object extent.
// The Cache definition matches Network_RestoreMatchingCachedConnection exactly.
extern "C" Cache MemoryZeroBlock170_UnknownRoleZeroInitializedStorage[4];
// Original: arm9/ov031 @ 0x0220AA98; symbol: func_ov031_0220aa98; size: 0xe0.
// Expires cached sessions and wakes waiting socket contexts after handshake timeouts.
extern "C" void Ssl_ExpireSessionsAndWakeTimedOutHandshakes(unsigned now)
{
    int irq = DisableIRQInterrupts();
    int i = 0;
    Cache* session = MemoryZeroBlock170_UnknownRoleZeroInitializedStorage;
    do {
        if (session->valid && (int)(now - session->timestamp) > 957) session->valid = 0;
        ++i;
        ++session;
    } while (i < 4);
    SetIRQInterruptState(irq);
    ProcessorContext* context = OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.firstContext;
    if (context) do {
        TimedSslSocket* socket = (TimedSslSocket*)context->unknown_A4;
        if (socket && socket->waitingContext && socket->timeoutEnabled && socket->state == 4 && socket->crypto[0x455] < 8 && (int)(now - socket->timestamp) > 239 && socket->waitState == 2) {
            socket->state = 0;
            socket->waitState = 0;
            MarkContextReadyAndSwitch(socket->waitingContext);
        }
        context = context->pNext;
    } while (context);
}
