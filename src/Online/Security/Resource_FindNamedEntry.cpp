#include <globaldefs.h>
#include "std_library_functions.h"
ARM
struct NamedEntry { const char* name; };
struct NameTable { unsigned char pad[0x814]; NamedEntry** entries; int count; };
// Original: arm9/ov031 @ 0x02207D88; symbol: func_ov031_02207d88; size: 0x4C.
// Returns the first named entry whose string matches the requested name.
extern "C" NamedEntry* Resource_FindNamedEntry(NameTable* self,const char* name) {
 int i=0;
 if(self->count>0) {
 NamedEntry** entries=self->entries;
 int count=self->count;
 do {
 NamedEntry* entry=entries[i];
 if(strcmp(entry->name,name)==0)return entry;
 ++i;
 }while(i<count);
 }
 return 0;
}
