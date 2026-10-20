#include <globaldefs.h>
ARM
extern "C" void PartySync_ResetRecord(void*);
// Original: arm9/main @ 0x0207DDF0; symbol: func_0207ddf0; size: 0x2C.
extern "C" void* PartySync_ConstructRecordTable(unsigned char* p){PartySync_ResetRecord(p);PartySync_ResetRecord(p+12);PartySync_ResetRecord(p+24);PartySync_ResetRecord(p+36);return p;}
