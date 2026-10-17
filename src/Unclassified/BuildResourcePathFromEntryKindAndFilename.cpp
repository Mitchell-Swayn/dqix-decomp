#include <globaldefs.h>
struct Entry{unsigned ptr,unused;unsigned a:12;unsigned kind:6;unsigned rest:14;};extern "C" unsigned RecordLookup_FindGlobalEntryById(unsigned);extern "C" unsigned AppendDirectoryAndFilePathWithSeparator(unsigned,unsigned,unsigned,int);
// Original: arm9/main @ 0x020E4750; symbol: func_020e4750; size: 0x48.
extern "C" ARM unsigned BuildResourcePathFromEntryKindAndFilename(unsigned a,Entry* e){if(e->ptr){unsigned kind=RecordLookup_FindGlobalEntryById(e->kind);a=AppendDirectoryAndFilePathWithSeparator(a,kind,e->ptr,0);}return a;}
