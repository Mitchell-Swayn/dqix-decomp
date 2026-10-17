#include <globaldefs.h>
#include <Resource/Script.h>
struct Record {void* first;void* second;short value;unsigned char flag1,flag2;};struct Pair {void* first;void* second;};struct RecordArray {Record* records;Pair* pairs;int count,pairCount;};
extern "C" {extern char data_02114e20[];void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);void func_ov015_0218b828(RecordArray*);extern RecordArray* data_ov015_02194560;void func_ov015_0218b978(RecordArray*,int);void func_ov015_0218b9ac(RecordArray*,int);}
// Original: arm9/ov015 @ 0x0218B6BC; symbol: func_ov015_0218b6bc; size: 0x28.
extern "C" ARM int func_ov015_0218b6bc(const Script::Parameter* parameter){RecordArray* p=data_ov015_02194560;int count=parameter->ToInt();func_ov015_0218b9ac(p,count);return 1;}
