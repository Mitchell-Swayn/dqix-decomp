struct Entry {
    unsigned short a,b,c,d;
};
struct List {
    unsigned a,b;
    Entry* entries;
    unsigned char count;
};
// Original: arm9/ov031 @ 0x0223BCC8; symbol: func_ov031_0223bcc8; size: 0x60.
extern "C" void SetSpriteAttributePriority(List* p,int index,unsigned value) {
    Entry* e=p->entries;
    if(index>=0) {
        e[index].c=(e[index].c&~0xc00)|(value<<10);
        return;
    }int i=0;
    if(i>=p->count)return;
    do {
        e[i].c=(e[i].c&~0xc00)|(value<<10);
        ++i;
    }while(i<p->count);
}
