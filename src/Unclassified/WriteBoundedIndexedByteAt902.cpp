// Original: arm9/main @ 0x020465F0; symbol: func_020465f0; size: 0x18.
extern "C" void WriteBoundedIndexedByteAt902(char* p,int i,int v) { if(i<0) return; if(i<16) *(char*)(p+i+0x902)=v; }
