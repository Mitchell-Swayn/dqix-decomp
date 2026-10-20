extern "C" {
struct Node { Node* next; }; struct Owner { unsigned char pad[0xb8]; Node* head; };
// Original: arm9/ov014 @ 0x021874F8; symbol: func_ov014_021874f8; size: 0x28.
short BestiaryScreen_CountFilteredMonsters(Owner* p) { short count=0; for(Node* n=p->head;n;n=n->next) ++count; return count; }
}
