#include <globaldefs.h>
ARM
struct GameState; struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*, int);
extern "C" void* GameState_GetIndexList(GameState* state);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *);
extern "C" short Inventory_CountPositiveQuantitySlots(void *p,int i);
extern "C" unsigned char Inventory_MapShopCategoryToGroup(unsigned int i);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char* p,int key);
extern "C" int CharacterState_CountCarriedItems(char* p);
extern "C" int Inventory_CountOccupiedSlots(char* p);
// Original: arm9/ov003 @ 0x02179F34; symbol: func_ov003_02179f34; size: 0xBC.
extern "C" int GameState_CountSelectedAvailableQuantities(char *self) {
    int result = 0;
    GameState *state = (GameState*)_ZN9GameState11GetInstanceEv();
    char *list = (char*)GameState_GetIndexList(state);
    unsigned char *group = *(unsigned char**)(self + 0x89c);
    if (*(short*)(self + 0x100c) == 119) {
        int adjustment = FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(group, 29);
        int index = (short)(*(short*)(self + 0x1012) - adjustment);
        unsigned char key = Inventory_MapShopCategoryToGroup(index);
        result = Inventory_CountPositiveQuantitySlots(list + 0x1d4, key);
    } else {
        int index = *(signed char*)(self + 0x1043);
        int valid = result;
        if (index >= 0) valid = index <= 3;
        if (valid) {
            Object3D *object = _ZN9GameState21GetPartyMemberByIndexEi(state,index);
            if (object) result = (short)CharacterState_CountCarriedItems((char*)GameObject_GetLinkedIndexedState(object));
        } else result = Inventory_CountOccupiedSlots(list);
    }
    return result;
}
