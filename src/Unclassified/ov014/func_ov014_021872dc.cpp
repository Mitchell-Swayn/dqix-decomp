extern "C" { struct Node { Node* next; }; struct Owner { unsigned char pre[0xb8]; Node* head; Node* selected; }; short func_ov014_021874f8(Owner*); short func_ov014_02187520(Owner*); Node* func_ov014_02187340(Owner*,int);
// Original: arm9/ov014 @ 0x021872DC; symbol: func_ov014_021872dc; size: 0x64.
 void func_ov014_021872dc(Owner* p,int delta) { short pages=(func_ov014_021874f8(p)+15)/16; short page=func_ov014_02187520(p); page=page+delta; if(page<0)page=pages+page;if(pages<=page)page-=pages;p->selected=func_ov014_02187340(p,page); } }
