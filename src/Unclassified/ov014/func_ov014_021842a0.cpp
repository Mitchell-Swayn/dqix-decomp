extern "C" { struct Item { short index; unsigned char rest[22]; }; struct Catalog { unsigned pre[2]; Item* items; unsigned char gap[8]; unsigned short count; };
// Original: arm9/ov014 @ 0x021842A0; symbol: func_ov014_021842a0; size: 0x60.
 Item* func_ov014_021842a0(Catalog* p,int index) { Item* items=p->items; if(!items)return 0; unsigned short count=p->count;if(!count)return 0; for(unsigned short i=0;i<count;i++){ int key=items[i].index; if(key==index)return items+i; };return 0; } }
