#include <globaldefs.h>
#include <System/DTCM.h>
// Original: arm9/main @ 0x020C6AD4; symbol: _Z40InitializeInterruptContextBlock_020c6ad4v; size: 0x18.
ARM BlockedContextList* InitializeInterruptBlockedThreadList()
{
 BlockedContextList* p=&Entry_UnknownRoleProcedureReferenceRecords.block_60;
 p->last=0; p->first=0;
 return p;
}
