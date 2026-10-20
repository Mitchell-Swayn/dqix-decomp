#include <globaldefs.h>
extern "C" {
    void PartySync_ResetRecord(void *);
// Original: arm9/main @ 0x0207DE1C; symbol: func_0207de1c; size: 0x2C.
    unsigned char *PartySync_ReinitializeRecordTable(unsigned char *p){
        PartySync_ResetRecord(p);
        PartySync_ResetRecord(p+12);
        PartySync_ResetRecord(p+24);
        PartySync_ResetRecord(p+36);
        return p;
    }
}
