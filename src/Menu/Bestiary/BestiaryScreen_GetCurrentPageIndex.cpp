extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
// Original: arm9/ov014 @ 0x02187520; symbol: func_ov014_02187520; size: 0x48.
short BestiaryScreen_GetCurrentPageIndex(Owner* p) { Node* n=p->head; short i=0;for(;n;n=n->next,++i)if(n==p->selected)return i/16;return -1; }
}
