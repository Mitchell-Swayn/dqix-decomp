#include <globaldefs.h>

extern "C" unsigned ReadLinkedInfoFlagBitsTwelveThroughFifteen(void*, void*);

// Original: arm9/main @ 0x0205AF18; symbol: func_0205af18; size: 0x20.
extern "C" ARM unsigned short ReadRecordDerivedHalfwordOrZero(void* owner, void* record) {
    if(record) return (unsigned short)ReadLinkedInfoFlagBitsTwelveThroughFifteen(owner, record);
    return 0;
}
