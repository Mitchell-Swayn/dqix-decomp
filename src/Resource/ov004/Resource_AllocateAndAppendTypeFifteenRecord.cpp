#include <globaldefs.h>
ARM
struct Tree; struct State; struct Node; struct Item;
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" Tree* FindTreeNodeForwarder(Tree* tree, unsigned id);
extern "C" void* func_ov011_021849c8(State* self);
extern "C" void AppendEnabledNodeToForwardChain(Node** owner,Node* node);
extern "C" int InitializeTypeFifteenPackedRecord(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" char data_ov023_021ff078[];
struct Initial { void *vtable; char pad[60]; };
// Original: arm9/ov004 @ 0x0216B06C; symbol: func_ov004_0216b06c; size: 0xB4.
extern "C" void Resource_AllocateAndAppendTypeFifteenRecord(State *self, unsigned value, unsigned id, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned char flag) {
    char *allocator = (char*)FindTreeNodeForwarder((Tree*)self,id);
    char *record = _ZN13SafeAllocator8AllocateEj((unsigned)(allocator+4),64);
    if (record) {
        Initial initial;
        initial.vtable = data_ov023_021ff078;
        memcpy(record,&initial,64);
        InitializeTypeFifteenPackedRecord((Item*)record,self,value,id,a,b,c,d,1,e,15);
        Node **head = (Node**)func_ov011_021849c8(self);
        AppendEnabledNodeToForwardChain(head,(Node*)record);
        record[0x3d] = flag;
    }
}
