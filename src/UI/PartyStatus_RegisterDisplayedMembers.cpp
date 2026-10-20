#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20fdcce; symbol: data_020fdcce.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 98 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char PartyStatusRegisterDisplayedMembers_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02026348; symbol: func_02026348; size: 0x4C.
extern "C" void PartyStatus_RegisterDisplayedMembers(unsigned char* p,unsigned char* ids,int count){if((unsigned)count>4){p[0x75c]=0;return;}for(int i=0;i<count;){unsigned char id=ids[i];unsigned char* slot=p+i;++i;slot[0x758]=id;PartyStatusRegisterDisplayedMembers_UnknownRoleZeroInitializedStorage[id*32]=1;}p[0x75c]=count;}
