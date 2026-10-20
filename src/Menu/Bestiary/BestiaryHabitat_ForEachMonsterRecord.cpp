extern "C" { struct Table { unsigned short first,count,n,m; unsigned pad; unsigned* base; unsigned char* relocBase; }; typedef void (*Visitor)(Table*,unsigned*);
// Original: arm9/ov014 @ 0x021891F0; symbol: func_ov014_021891f0; size: 0x54.
 int BestiaryHabitat_ForEachMonsterRecord(Table* p,Visitor visit) { int count; unsigned* item=p->base; if(!item || !(count=p->first) || !visit)return 0; for(int i=0;i<count;i++,item++)visit(p,item);return 1; } }
