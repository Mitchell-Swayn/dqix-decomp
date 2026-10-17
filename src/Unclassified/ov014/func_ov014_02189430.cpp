extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
unsigned* func_ov014_0218940c(Table*,int,void*); unsigned char* func_ov014_02189398(Table*);
// Original: arm9/ov014 @ 0x02189430; symbol: func_ov014_02189430; size: 0x38.
 unsigned* func_ov014_02189430(Table* p,int i,void* e) { if(!e)return 0; unsigned short* v=(unsigned short*)func_ov014_0218940c(p,i,e);if(!v)return 0;unsigned* base=(unsigned*)func_ov014_02189398(p);return base+*v; }
}
