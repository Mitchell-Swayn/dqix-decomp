#include <globaldefs.h>
#include <Resource/Script.h>
struct Record {void* first;void* second;short value;unsigned char flag1,flag2;};struct Pair {void* first;void* second;};struct RecordArray {Record* records;Pair* pairs;int count,pairCount;};
extern "C" {extern char data_02114e20[];void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);void func_ov015_0218b828(RecordArray*);extern RecordArray* data_ov015_02194560;void func_ov015_0218b978(RecordArray*,int);void func_ov015_0218b9ac(RecordArray*,int);}
// Original: arm9/ov015 @ 0x0218B9AC; symbol: func_ov015_0218b9ac; size: 0x28.
extern "C" ARM void func_ov015_0218b9ac(RecordArray* p,int count){p->pairs=(Pair*)AllocatorUnion_AllocateFourByteAligned(data_02114e20,(unsigned)count<<3);p->pairCount=0;}
