#include <globaldefs.h>
ARM
struct Record { short key; unsigned short value; };
struct Table { char pad[32]; Record* records; unsigned short count; };
// Original: arm9/ov006 @ 0x02153E8C; symbol: func_ov006_02153e8c; size: 0x98.
extern "C" void Util_UpdateOrInsertHalfwordRecord(Table* table,const Record* input) {
short key=input->key;
unsigned short count=table->count;
for(unsigned short i=0;i<count;++i) {
Record* entry=&table->records[i];
if(entry->key==key) {*entry=*input;return;}
}
for(unsigned short i=0;i<count;++i) {
Record* entry=&table->records[i];
if(entry->key<=0) {*entry=*input;return;}
}
}
