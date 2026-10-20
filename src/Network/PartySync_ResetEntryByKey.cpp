#include <globaldefs.h>
extern "C" {
void *PartySync_FindEntryByKey(void *,int);void PartySync_ResetRecord(void *);
// Original: arm9/main @ 0x0207DA7C; symbol: func_0207da7c; size: 0x18.
void PartySync_ResetEntryByKey(void *p,int i){void *q=PartySync_FindEntryByKey(p,i);if(q)PartySync_ResetRecord(q);}
}
