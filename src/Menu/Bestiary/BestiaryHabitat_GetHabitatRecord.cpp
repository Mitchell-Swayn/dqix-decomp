extern "C" {
extern "C" unsigned* BestiaryHabitat_GetMonsterHabitatRecords(void*,void*);
// Original: arm9/ov014 @ 0x0218940C; symbol: func_ov014_0218940c; size: 0x24.
unsigned* BestiaryHabitat_GetHabitatRecord(void* p,int i,void* entry) { if(!entry) return 0; return BestiaryHabitat_GetMonsterHabitatRecords(p,entry)+i; }
}
