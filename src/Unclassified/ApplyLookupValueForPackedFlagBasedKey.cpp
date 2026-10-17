#include <globaldefs.h>
ARM
struct Record{int a;void* data;unsigned int flags;};extern "C" {int RecordLookup_FindGlobalEntryById(short);int AppendDirectoryAndFilePathWithSeparator(int,int,void*,Record*);
// Original: arm9/main @ 0x020E47BC; symbol: func_020e47bc; size: 0x54.
int ApplyLookupValueForPackedFlagBasedKey(int value,Record* p){if(p->data){int key=RecordLookup_FindGlobalEntryById((short)(((p->flags<<20)>>26)+300));value=AppendDirectoryAndFilePathWithSeparator(value,key,p->data,p);}return value;}}
