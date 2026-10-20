struct State { char reserved[0x5c]; void *buffer; };
extern "C" { State *TextContext_GetSharedInstance(); void *memset(void *,int,unsigned); void Text_CopyBattleStringByKey(void *,void *); }
// Original: arm9/ov026 @ 0x021D8A78; symbol: func_ov026_021d8a78; size: 0x34.
extern "C" void *BattleScene_FormatBattleStringInSharedBuffer(void *owner) { void *buffer=TextContext_GetSharedInstance()->buffer; memset(buffer,0,0x960); Text_CopyBattleStringByKey(owner,buffer); return buffer; }
