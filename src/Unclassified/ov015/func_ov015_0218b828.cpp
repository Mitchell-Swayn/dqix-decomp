#include <globaldefs.h>
struct Record { void* first; void* second; short value; unsigned char flag1,flag2; };
struct Node { void* payload; unsigned value; Node* next; };
struct Pair { void* first; Node* nodes; };
struct RecordArray { Record* records; Pair* pairs; int count,pairCount; };
extern "C" { extern char data_02114e20[]; void Memory_FreeThroughAllocatorUnion(void*,void*); void func_ov015_0218b810(RecordArray*); }
// Original: arm9/ov015 @ 0x0218B828; symbol: func_ov015_0218b828; size: 0x150.
extern "C" ARM void func_ov015_0218b828(RecordArray* p) {
    for(int i=0;i<p->count;++i) {
        if(p->records[i].first) {Memory_FreeThroughAllocatorUnion(data_02114e20,p->records[i].first);p->records[i].first=0;}
        if(p->records[i].second) {Memory_FreeThroughAllocatorUnion(data_02114e20,p->records[i].second);p->records[i].second=0;}
    }
    for(int i=0;i<p->pairCount;++i) {
        if(p->pairs[i].first) {Memory_FreeThroughAllocatorUnion(data_02114e20,p->pairs[i].first);p->pairs[i].first=0;}
        Node* node=p->pairs[i].nodes;
        while(node) {
            Node* next=node->next;
            if(node->payload) {Memory_FreeThroughAllocatorUnion(data_02114e20,node->payload);node->payload=0;}
            Memory_FreeThroughAllocatorUnion(data_02114e20,node);
            node=next;
        }
    }
    if(p->records) {Memory_FreeThroughAllocatorUnion(data_02114e20,p->records);p->records=0;}
    if(p->pairs) {Memory_FreeThroughAllocatorUnion(data_02114e20,p->pairs);p->pairs=0;}
    func_ov015_0218b810(p);
}
