#include <globaldefs.h>
ARM
extern "C" unsigned RecordLookup_FindGlobalEntryById(short); extern "C" unsigned AppendDirectoryAndFilePathWithSeparator(unsigned,unsigned,unsigned,unsigned); struct Entry { unsigned value;unsigned pad;unsigned count:6;unsigned rest:26;};
// Original: arm9/main @ 0x020E46FC; symbol: func_020e46fc; size: 0x54.
 extern "C" unsigned ApplyLookupValueForCountBasedKey(unsigned a,volatile Entry* p){ if(p->value)a=AppendDirectoryAndFilePathWithSeparator(a,RecordLookup_FindGlobalEntryById((short)(p->count+100)),p->value,0);return a;}
