#include <globaldefs.h>
ARM
struct Entry { unsigned unknown; const signed char* name; unsigned tail[3]; };
struct Table { Entry* entries; short pad,count; };
struct State { Entry* current; Table* table; unsigned pad[4]; unsigned field18; unsigned short field1c; unsigned char field1e,pad1f,field20; };
extern "C" { unsigned String_CountBytesUntilTerminator(const signed char*); int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned); }
// Original: arm9/ov003 @ 0x0215F41C; symbol: func_ov003_0215f41c; size: 0x88.
extern "C" void TextEntry_SelectControlByNameAndResetInput(State* p,const signed char* name,int count) {
 p->current=0;
 p->field18=0;
 p->field1c=0;
 p->field1e=1;
 p->field20=0;
 unsigned length=String_CountBytesUntilTerminator(name);
 count=p->table->count;
 Entry* entry=p->table->entries;
 for(short i=0;i<count;++i,++entry) {
  if(entry->name && !RuntimeMemory_CompareByteRanges(entry->name,name,length)) {
   p->current=entry;
   return;
  }
 }
}
