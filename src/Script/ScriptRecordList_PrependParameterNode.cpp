#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct E{char pad[16];E *next;};struct A{E *head;unsigned char count;};
// Original: arm9/main @ 0x0206EEEC; symbol: func_0206eeec; size: 0x2C.
void ScriptRecordList_PrependParameterNode(A *p,E *n){if(p->head){n->next=p->head;p->head=n;}else{p->head=n;n->next=0;}p->count++;}
}
