#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct E{char pad[5];char name[11];};struct T{E *data;int count;};
// Original: arm9/main @ 0x0209998C; symbol: func_0209998c; size: 0x4C.
E *FindRecordByName(T *p,char *name){for(int i=0;i<p->count;i++){E *n=p->data+i;if(strcmp(n->name,name)==0)return n;}return 0;}
}
