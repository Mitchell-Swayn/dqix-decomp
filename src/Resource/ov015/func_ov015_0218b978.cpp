#include <globaldefs.h>
#include <Resource/Script.h>
struct Record {void* first;void* second;short value;unsigned char flag1,flag2;};struct Pair {void* first;void* second;};struct RecordArray {Record* records;Pair* pairs;int count,pairCount;};
extern "C" {extern char data_02114e20[];void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);void func_ov015_0218b828(RecordArray*);extern RecordArray* data_ov015_02194560;void func_ov015_0218b978(RecordArray*,int);void func_ov015_0218b9ac(RecordArray*,int);}
// Original: arm9/ov015 @ 0x0218B978; symbol: func_ov015_0218b978; size: 0x34.
extern "C" ARM void func_ov015_0218b978(RecordArray* p,int count){func_ov015_0218b828(p);p->records=(Record*)AllocatorUnion_AllocateFourByteAligned(data_02114e20,count*12);p->count=0;}
