struct State { char reserved[0x5c]; void *buffer; };
extern "C" { State *ReadWordFieldAtOffset1C(); void *memset(void *,int,unsigned); void ClearAndFormatOutputForNonnegativeCount(void *,void *); }
// Original: arm9/ov026 @ 0x021D8A78; symbol: func_ov026_021d8a78; size: 0x34.
extern "C" void *func_ov026_021d8a78(void *owner) { void *buffer=ReadWordFieldAtOffset1C()->buffer; memset(buffer,0,0x960); ClearAndFormatOutputForNonnegativeCount(owner,buffer); return buffer; }
