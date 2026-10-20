extern "C" {
struct Table { unsigned short first, count, n,m; unsigned pad; unsigned* base; }; struct Entry { unsigned short key; unsigned short index; };
// Original: arm9/ov014 @ 0x021893E4; symbol: func_ov014_021893e4; size: 0x28.
unsigned* BestiaryHabitat_GetMonsterHabitatRecords(Table* p,Entry* e) { if(!e)return 0; return p->base+p->first+(e->index&0xfff); }
}
