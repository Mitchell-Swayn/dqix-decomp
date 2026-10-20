#include <globaldefs.h>
ARM
extern "C" void PartySync_ResetRecord(void*);
// Original: arm9/main @ 0x0207D798; symbol: func_0207d798; size: 0x28.
extern "C" void PartySync_ResetRecordTable(unsigned char* p){PartySync_ResetRecord(p);PartySync_ResetRecord(p+12);PartySync_ResetRecord(p+24);PartySync_ResetRecord(p+36);}
