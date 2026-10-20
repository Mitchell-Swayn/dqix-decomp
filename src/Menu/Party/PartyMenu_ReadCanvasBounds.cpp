struct WindowCanvasOwner;
struct WindowCanvasRecord;
struct PartyMenuState;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
// Original: arm9/ov002 @ 0x02157030; symbol: func_ov002_02157030; size: 0x4C.
extern "C" void PartyMenu_ReadCanvasBounds(PartyMenuState* owner,int id,short* a,short* b,short* c,short* d) {
    char* p=(char*)owner;
    char* q=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(p+0xec8),id);
    if(!q)return;
    *a=*(short*)(q+0xac);
    *b=*(short*)(q+0xae);
    *c=*(short*)(q+0xa8);
    *d=*(short*)(q+0xaa);
}
