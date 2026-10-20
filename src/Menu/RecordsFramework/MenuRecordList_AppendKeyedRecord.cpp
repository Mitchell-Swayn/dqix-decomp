#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
struct Node {
    char pad[6];
    unsigned short enabled;
    char gap[12];
    Node* prev;
    Node* next;
};
// Original: arm9/ov023 @ 0x021F67AC; symbol: func_ov023_021f67ac; size: 0x40.
extern "C" void MenuRecordList_AppendKeyedRecord(Node** owner,Node* node) {
    if(!node->enabled)return;
    Node* p=*owner;
    if(p) {
        while((owner=(Node**)p->next)!=0)p=(Node*)owner;
        p->next=node;
        node->prev=p;
    } else {
        *(Node**)owner=node;
    }
}
