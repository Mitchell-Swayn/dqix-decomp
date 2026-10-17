extern "C" { struct Table { unsigned short first,count,n,m; unsigned pad; unsigned* base; unsigned char* relocBase; }; typedef unsigned (*Lookup)(const unsigned short*); unsigned func_ov014_02188b18(const unsigned short*); unsigned* func_ov014_021892d4(Table*,int,Lookup);
// Original: arm9/ov014 @ 0x021893C4; symbol: func_ov014_021893c4; size: 0x20.
 unsigned* func_ov014_021893c4(Table* p,int index) { if(index<0)return p->base; return func_ov014_021892d4(p,index,func_ov014_02188b18); } }
