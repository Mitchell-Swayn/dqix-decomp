#include <globaldefs.h>
struct Entry { unsigned int value; unsigned short tag; };
struct Record { unsigned int header; Entry entries[9]; };
// Original: arm9/main @ 0x0209B988; symbol: func_0209b988; size: 0x20.
extern "C" ARM void CopyIndexedEntryValueAndTag(Record* records,int index,int slot,const Entry* entry) {
 records[index].entries[slot].value=entry->value;
 records[index].entries[slot].tag=entry->tag;
}
