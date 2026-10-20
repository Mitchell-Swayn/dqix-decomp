struct S{char pad[0xbd0];unsigned int values[8];};
// Original: arm9/main @ 0x0207C5F8; symbol: func_0207c5f8; size: 0x14.
extern "C" unsigned int Inventory_GetGroupItemIds(S* p,unsigned int i){if(i>7)return 0;return p->values[i];}
