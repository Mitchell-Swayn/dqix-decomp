#include <globaldefs.h>
ARM
extern "C" {
    void* _ZN9GameState11GetInstanceEv();
    void* ReadGlobalAt02100044();
    void MoveQueuedRecordAndApplySourceValue(void*,const void*,short);
    float _ZNK9GameState11GetDayTimerEv(void*);
}
// Original: arm9/ov017 @ 0x021CDAA0; symbol: func_ov017_021cdaa0; size: 0x44.
// Field purposes remain uncertain; operation and call sequence follow original instructions.
extern "C" void QueueDayTimerMessage93() {
    void* state=_ZN9GameState11GetInstanceEv();
    void* queue=ReadGlobalAt02100044();
    struct TimerMessage {
        unsigned char tag;
        char pad[3];
        float timer;
        char tail[12];
    }
    message;
    message.tag=0x93;
    message.timer=_ZNK9GameState11GetDayTimerEv(state);
    MoveQueuedRecordAndApplySourceValue(queue,&message,0);
}
