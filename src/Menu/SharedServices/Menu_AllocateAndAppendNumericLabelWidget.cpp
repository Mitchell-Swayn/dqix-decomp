#include <globaldefs.h>
ARM
struct Tree; struct State; struct Node; struct Item;
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" Tree* Menu_FindSessionArenaById(Tree* tree, unsigned id);
extern "C" void* Menu_GetDisplayRecordRegistry(State* self);
extern "C" void MenuRecordList_AppendKeyedRecord(Node** owner,Node* node);
extern "C" int InitializeTypeFifteenPackedRecord(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original data: arm9/ov023 @ 0x21ff078; symbol: data_ov023_021ff078.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex fcbc1f02b8691f02e8691f0284691f0288691f02186a1f0220bc1f0224bc1f0268bc1f0258741f0250741f024c741f0244741f0240741f0238741f02f8bc1f02 ...; full span in module reference.
// Observed span: 260 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" char SharedData_UnknownRoleProcedureReferenceRecords_Variant10[];
struct Initial { void *vtable; char pad[60]; };
// Original: arm9/ov004 @ 0x0216B06C; symbol: func_ov004_0216b06c; size: 0xB4.
extern "C" void Menu_AllocateAndAppendNumericLabelWidget(State *self, unsigned value, unsigned id, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned char flag) {
    char *allocator = (char*)Menu_FindSessionArenaById((Tree*)self,id);
    char *record = _ZN13SafeAllocator8AllocateEj((unsigned)(allocator+4),64);
    if (record) {
        Initial initial;
        initial.vtable = SharedData_UnknownRoleProcedureReferenceRecords_Variant10;
        memcpy(record,&initial,64);
        InitializeTypeFifteenPackedRecord((Item*)record,self,value,id,a,b,c,d,1,e,15);
        Node **head = (Node**)Menu_GetDisplayRecordRegistry(self);
        MenuRecordList_AppendKeyedRecord(head,(Node*)record);
        record[0x3d] = flag;
    }
}
