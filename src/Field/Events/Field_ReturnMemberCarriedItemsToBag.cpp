#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void* GameObject_GetLinkedIndexedState(void*);
extern "C" void Inventory_AddItemCountWithNinetyNineLimit(void*, int, int);
// Slot values and the indexed list's semantic role are unresolved.
// Original: arm9/ov017 @ 0x021b6bb8; symbol: func_ov017_021b6bb8; size: 0x74.
extern "C" void Field_ReturnMemberCarriedItemsToBag(int index) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* list = GameState_GetIndexList(state);
    void* object = GameState_GetObjectWithFlag100(state, index);
    if (!object) return;
    unsigned char* entries = (unsigned char*)GameObject_GetLinkedIndexedState(object);
    for (unsigned char i = 0; i < 8; ++i) {
        short count = *(short*)(entries + 0x454 + i * 2);
        if (count > 0) Inventory_AddItemCountWithNinetyNineLimit(list, count, 1);
    }
}
