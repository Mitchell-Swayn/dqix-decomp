#include <globaldefs.h>
ARM
struct Node { unsigned a,b; unsigned* records; unsigned char count; };
struct Pool { char pad[0x224];void* allocator; };
extern "C" char* data_ov031_02290d28;
extern "C" void UnlinkPointerPair(void*);
extern "C" void func_ov031_0223bf48(void*,void*);
// Original: arm9/ov031 @ 0x0223BA20; symbol: func_ov031_0223ba20; size: 0x80.
extern "C" void Network_UnlinkNodeAndReleaseRecords(Node* node) {
int group=0;
unsigned* records=node->records;
int i=0;
if((int)node->count>0) do {
*records=(*records&0xc1fffcff)|0x200;
records+=2;
++i;
} while(i<node->count);
UnlinkPointerPair(node);
if((unsigned)node>=(unsigned)(data_ov031_02290d28+0x228)) group=1;
Pool* pool=(Pool*)data_ov031_02290d28;
func_ov031_0223bf48(pool[group].allocator,node);
}
