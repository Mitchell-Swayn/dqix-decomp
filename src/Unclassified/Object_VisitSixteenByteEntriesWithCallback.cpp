#include <globaldefs.h>
struct List { unsigned count:12; unsigned flags:20; char* data; };
// Original: arm9/main @ 0x020E545C; symbol: func_020e545c; size: 0x60.
extern "C" ARM int Object_VisitSixteenByteEntriesWithCallback(List* object,void (*visit)(List*,void*)) { int count; char* data=object->data; if(!data || !(count=object->count) || !visit) return 0; for(int i=0;i<count;++i,data+=16) visit(object,data); return 1; }
