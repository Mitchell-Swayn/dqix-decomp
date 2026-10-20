#include <globaldefs.h>
struct Record {char pad[0x13];unsigned char reserved:2;unsigned char flag:1;unsigned char rest:5;char pad2[6];short value;char pad3[4];};struct Owner {unsigned unknown;unsigned count:12;unsigned rest:20;Record* records;};
// Original: arm9/main @ 0x02097798; symbol: func_02097798; size: 0xAC.
extern "C" void BestiaryList_ExcludeDuplicateDisplayEntries(Owner* self) {unsigned short count=self->count;Record* records=self->records;unsigned short limit=count-1;short value;Record* record;for(unsigned short i=0;i<limit;++i) {record=records+i;if(record->value<=0)record->flag=1;if(!record->flag) {value=record->value;for(unsigned short j=i+1;j<count;++j)if(records[j].value==value)records[j].flag=1;}}}
