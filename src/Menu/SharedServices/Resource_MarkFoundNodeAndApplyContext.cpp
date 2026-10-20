#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" void MenuSelectionGrid_RefreshCursorAndSelectionCallback(void*, void*);
// Original data: arm9/ov004 @ 0x2171034; symbol: data_ov004_02171034.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned short InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x0216E984; symbol: func_ov004_0216e984; size: 0x48.
extern "C" int Resource_MarkFoundNodeAndApplyContext(void* context) {
    void* head = Menu_GetDisplayRecordRegistry(context);
    if (head != 0) {
        void* node = MenuRecordList_LocateByKey((void**)head, *(unsigned short*)((char*)&InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage + 0xa));
        if (node != 0) {
            *(unsigned char*)((char*)node + 0xc) |= 0x10;
            MenuSelectionGrid_RefreshCursorAndSelectionCallback(node, context);
        }
    }
    return 0;
}
