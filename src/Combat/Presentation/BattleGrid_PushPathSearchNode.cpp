// Original: arm9/ov025 @ 0x021e23d0; symbol: func_ov025_021e23d0; size: 0x18.
extern "C" void BattleGrid_PushPathSearchNode(void** head,void* record) { void* old=*head; *(void**)((unsigned char*)record+8)=old?old:0;*head=record; }
