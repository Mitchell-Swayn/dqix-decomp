#include <System/Memory.h>
extern "C" void* memset(void*,int,unsigned);
struct Overlay8Record { unsigned char unknown[0x11]; unsigned char byte11; unsigned short flags; unsigned char tail[0x18]; };
// Original: arm9/ov008 @ 0x02189228; symbol: func_ov008_02189228; size: 0x5C.
extern "C" void PartyTalk_ResetProfileRegistrationRecord(Overlay8Record* record) {
    VectorizedMemset(record,0,6);
    memset((unsigned char*)record+6,0,11);
    record->flags &= ~0x3fff;
    record->byte11=0;
    record->flags &= ~0x4000;
    VectorizedMemset(record->tail,0,24);
}
