#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct E{char pad[16];unsigned char key:3;char rest[19];};struct A{E data[5];int count;};
// Original: arm9/main @ 0x020D3D90; symbol: func_020d3d90; size: 0x3C.
E *NpcAttributes_FindEntryByKind(A *p,unsigned int key){E *n=p->data;for(int i=0;i<p->count;n++,i++)if(n->key==key)return n;return 0;}
}
