#include "Filesystem/BackgroundLoader.h"
extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
void* memset(void*,int,unsigned); int func_ov014_02188d10(Stream*);
// Original: arm9/ov014 @ 0x02188BD0; symbol: func_ov014_02188bd0; size: 0x2C.
 void func_ov014_02188bd0(Stream* p) { memset(p,0,0x14); p->index=-1; p->handle=-1; func_ov014_02188d10(p); }
}
