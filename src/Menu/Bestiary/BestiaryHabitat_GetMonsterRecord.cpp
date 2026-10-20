extern "C" { struct Table { unsigned short first,count,n,m; unsigned pad; unsigned* base; unsigned char* relocBase; }; typedef unsigned (*Lookup)(const unsigned short*); unsigned BestiaryHabitat_ReadMonsterKey(const unsigned short*); unsigned* BestiaryHabitat_FindMonsterByKey(Table*,int,Lookup);
// Original: arm9/ov014 @ 0x021893C4; symbol: func_ov014_021893c4; size: 0x20.
 unsigned* BestiaryHabitat_GetMonsterRecord(Table* p,int index) { if(index<0)return p->base; return BestiaryHabitat_FindMonsterByKey(p,index,BestiaryHabitat_ReadMonsterKey); } }
