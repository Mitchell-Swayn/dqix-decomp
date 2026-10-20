extern "C" {
struct Owner { unsigned char pad[0xdc]; unsigned* base; }; struct Entry { unsigned char pad[0x1a]; short index; };
// Original: arm9/ov014 @ 0x02187450; symbol: func_ov014_02187450; size: 0x38.
unsigned* BestiaryScreen_GetMonsterProgressRecord(Owner* p,Entry* e) { if(!e)return 0; short index=e->index-1; if(index>=0 && index<0x134)return p->base+index; return 0; }
}
