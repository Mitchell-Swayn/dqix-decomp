#include <globaldefs.h>
ARM
struct Table { unsigned count:12; unsigned rest:20; char* entries; };
// Original: arm9/main @ 0x020DFFC8; symbol: func_020dffc8; size: 0x60.
extern "C" int ResourceStringTable_VisitEntries(Table* p, void (*callback)(Table*, char*)) {
    int count;
    char* entry=p->entries;
    if (!entry || !(count=p->count) || !callback) return 0;
    for (int i=0;i<count;++i,entry+=8) callback(p,entry);
    return 1;
}
