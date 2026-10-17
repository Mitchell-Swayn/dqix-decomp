#include <globaldefs.h>
#include <Resource/Script.h>
struct Record {char* first;char* second;unsigned short value;unsigned char flag1,flag2;}; struct Pair {void* first;void* second;}; struct RecordArray {Record* records;Pair* pairs;int count,pairCount;};
extern "C" { extern char data_02114e20[]; extern RecordArray* data_ov015_02194560; void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned); unsigned String_CountBytesUntilTerminator(const char*); void func_ov015_0218b9d4(RecordArray*,const Record*); }
// Original: arm9/ov015 @ 0x0218B5C8; symbol: func_ov015_0218b5c8; size: 0xF4.
extern "C" ARM int func_ov015_0218b5c8(const Script::Parameter* parameters) {
    const char* first=parameters[0].ToString();
    const char* second=parameters[1].ToString();
    int value=parameters[2].ToInt();
    int flag1=parameters[3].ToInt();
    int flag2=parameters[4].ToInt();
    Record record;
    record.first=0; record.second=0; record.value=0; record.flag1=0; record.flag2=0;
    if(first) {record.first=(char*)AllocatorUnion_AllocateFourByteAligned(data_02114e20,String_CountBytesUntilTerminator(first)+1);if(record.first)strcpy(record.first,first);}
    if(second) {record.second=(char*)AllocatorUnion_AllocateFourByteAligned(data_02114e20,String_CountBytesUntilTerminator(second)+1);if(record.second)strcpy(record.second,second);}
    RecordArray* p=data_ov015_02194560;
    record.value=value; record.flag1=flag1; record.flag2=flag2;
    func_ov015_0218b9d4(p,&record);
    return 1;
}
