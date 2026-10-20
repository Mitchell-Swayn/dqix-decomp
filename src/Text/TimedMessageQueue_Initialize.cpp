#include <globaldefs.h>
extern "C" {
    void TimedMessageQueue_Clear(void *);
// Original: arm9/main @ 0x020D806C; symbol: func_020d806c; size: 0x14.
    void *TimedMessageQueue_Initialize(void *p){
        TimedMessageQueue_Clear(p);
        return p;
    }
}
