extern "C" { struct Table { unsigned short first,count,n,m; unsigned pad; unsigned* base; unsigned char* relocBase; };
// Original: arm9/ov014 @ 0x02188BA0; symbol: func_ov014_02188ba0; size: 0x30.
 unsigned char* func_ov014_02188ba0(Table* p,unsigned char* offset,unsigned char* fallback) { bool empty=true; int relative=offset-(unsigned char*)0; if(relative!=-1 && p->relocBase) empty=false; if(!empty)fallback=p->relocBase+relative;return fallback; } }
