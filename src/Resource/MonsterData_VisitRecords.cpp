#include <globaldefs.h>
#pragma optimize_for_size off
struct List {unsigned count:12,flags:20;char* entries;};
typedef void (*Visitor)(List*,char*);
// Original: arm9/main @ 0x0206F110; symbol: func_0206f110; size: 0x60.
extern "C" ARM int MonsterData_VisitRecords(List*p,Visitor callback){
 int count;char* entry=p->entries;
 if(!entry || !(count=p->count) || !callback)return 0;
 int i=0;for(;i<count;entry+=28){callback(p,entry);++i;}return 1;
}
