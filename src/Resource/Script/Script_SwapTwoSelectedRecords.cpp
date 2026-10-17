#include <globaldefs.h>
ARM
namespace Script { struct Parameter { char data[8]; int ToInt() const; }; }
extern "C" void *data_020fdd30; extern "C" void *FindSixteenByteEntryByKey(void *,int); extern "C" void Object_AppendPairWithinCapacity(void *,void **);
// Original: arm9/main @ 0x02027DB0; symbol: func_02027db0; size: 0x94.
extern "C" int Script_SwapTwoSelectedRecords(const Script::Parameter *args) { void *pair[2]; pair[1]=0; pair[0]=0; int first=args[0].ToInt(); int second=args[1].ToInt(); if(first==second) return 0; pair[0]=FindSixteenByteEntryByKey(data_020fdd30,first); pair[1]=FindSixteenByteEntryByKey(data_020fdd30,second); if(!pair[0]||!pair[1]) return 0; Object_AppendPairWithinCapacity(data_020fdd30,pair); return 1; }
