extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; };
// Original: arm9/ov014 @ 0x02189380; symbol: func_ov014_02189380; size: 0x18.
unsigned* BestiaryHabitat_GetZoneIdArray(Table* p) { return p->base+p->first+p->count; }
}
