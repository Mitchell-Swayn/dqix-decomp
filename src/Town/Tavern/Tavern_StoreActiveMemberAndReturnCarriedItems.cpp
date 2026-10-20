#include <globaldefs.h>
ARM
extern "C" void Field_ReturnMemberCarriedItemsToBag(int);
extern "C" void GameState_AppendSerializedRecord(int, int);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void GameObject_DisableMovementInput(void*, int);
// Original: arm9/ov003 @ 0x02166F40; symbol: func_ov003_02166f40; size: 0x40.
extern "C" void Tavern_StoreActiveMemberAndReturnCarriedItems(char* self) {
    int index = *(short*)(self + 0x482);
    Field_ReturnMemberCarriedItemsToBag(index);
    index = *(short*)(self + 0x482);
    GameState_AppendSerializedRecord(index, 0);
    void* protagonist = _ZN9GameState14GetProtagonistEv(_ZN9GameState11GetInstanceEv());
    if (protagonist != 0) GameObject_DisableMovementInput(protagonist, 1);
}
