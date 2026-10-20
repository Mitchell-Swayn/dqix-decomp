#include <globaldefs.h>
ARM
struct Record {short key;unsigned short flags;};
struct Table {char pad[0x20];Record* volatile records;unsigned short count;};
// Original: arm9/ov006 @ 0x02153C6C; symbol: func_ov006_02153c6c; size: 0x50.
// Finds a nonnegative halfword key in a stride-four table; the table base is read for each entry.
extern "C" Record* FindNonnegativeHalfwordKeyInPackedTable(Table* table,int key) {
 if(key<0) return 0;
 unsigned short count=table->count;
 for(unsigned short i=0;i<count;++i) {
  Record* entry=&table->records[i];
  if(entry->key==key) return entry;
 }
 return 0;
}
