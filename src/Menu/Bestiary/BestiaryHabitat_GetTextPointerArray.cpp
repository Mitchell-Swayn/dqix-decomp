extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
unsigned* BestiaryHabitat_GetZoneIdArray(Table*);
// Original: arm9/ov014 @ 0x02189398; symbol: func_ov014_02189398; size: 0x2C.
 unsigned char* BestiaryHabitat_GetTextPointerArray(Table* p) { unsigned char* base=(unsigned char*)p->base; unsigned char* end=(unsigned char*)BestiaryHabitat_GetZoneIdArray(p)+p->n*2; return base+(((end-base)+3)&~3); }
}
