extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
// Original: arm9/ov014 @ 0x02186DF0; symbol: func_ov014_02186df0; size: 0x3C.
void BestiaryScreen_RequestClose(Owner* p) { if(p->closed)return; p->closed=1;if(p->linked)*p->linked=-1;p->linked=0;p->state=5;p->phase=0; }
}
