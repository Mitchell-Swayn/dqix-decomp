#include <globaldefs.h>
struct Record { void* first; void* second; short value; unsigned char flag1,flag2; };
struct Node { void* payload; unsigned value; Node* next; };
struct Pair { void* first; Node* nodes; };
struct RecordArray { Record* records; Pair* pairs; int count,pairCount; };
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern char Main_UnknownRoleZeroInitializedStorage_Variant3[]; void Memory_FreeThroughAllocatorUnion(void*,void*); void CharacterViewer_InitializeMenuCatalog(RecordArray*); }
// Original: arm9/ov015 @ 0x0218B828; symbol: func_ov015_0218b828; size: 0x150.
extern "C" ARM void CharacterViewer_DestroyMenuCatalog(RecordArray* p) {
    for(int i=0;i<p->count;++i) {
        if(p->records[i].first) {Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,p->records[i].first);p->records[i].first=0;}
        if(p->records[i].second) {Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,p->records[i].second);p->records[i].second=0;}
    }
    for(int i=0;i<p->pairCount;++i) {
        if(p->pairs[i].first) {Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,p->pairs[i].first);p->pairs[i].first=0;}
        Node* node=p->pairs[i].nodes;
        while(node) {
            Node* next=node->next;
            if(node->payload) {Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,node->payload);node->payload=0;}
            Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,node);
            node=next;
        }
    }
    if(p->records) {Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,p->records);p->records=0;}
    if(p->pairs) {Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,p->pairs);p->pairs=0;}
    CharacterViewer_InitializeMenuCatalog(p);
}
