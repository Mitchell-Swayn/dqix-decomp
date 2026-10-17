extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
int func_ov014_02188d10(Stream*); void func_ov014_02188bd0(Stream*); void func_ov014_02188c34(Stream*);
// Original: arm9/ov014 @ 0x02188BFC; symbol: func_ov014_02188bfc; size: 0x38.
 void func_ov014_02188bfc(Stream* p,void* source,int index) { func_ov014_02188d10(p); func_ov014_02188bd0(p); p->index=index; p->source=source; p->active=1; func_ov014_02188c34(p); }
}
