#include <Resource/Script.h>
extern "C" void *data_020fdd30; extern "C" int FindSixteenByteEntryByKey(void*,int); extern "C" void Object_AppendPairWithinCapacity(void*,int*);
#pragma always_inline on
static inline int Reconstruct_func_02027eec(const Script::Parameter *params) { int start=params[0].ToInt(); int end=params[1].ToInt(); struct Pair {int previous;int next;}; Pair values; values.previous=0;values.next=0; int i=start+1; values.previous=FindSixteenByteEntryByKey(data_020fdd30,start); while(i<=end) { values.next=FindSixteenByteEntryByKey(data_020fdd30,i); ++i; if(values.previous && values.next)Object_AppendPairWithinCapacity(data_020fdd30,(int*)&values); if(values.next)values.previous=values.next; } return 1; }
// Original: arm9/main @ 0x02027EEC; symbol: func_02027eec; size: 0xA4.
extern "C" int Script_LinkNonzeroRecordsAcrossInclusiveIndexRange(const Script::Parameter *params) { return Reconstruct_func_02027eec(params); }
