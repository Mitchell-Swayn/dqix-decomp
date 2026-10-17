#include <globaldefs.h>
ARM
struct GameState; struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*, int);
extern "C" void* GameState_GetIndexList(GameState* state);
extern "C" unsigned char *ReadWordFieldAtOffset150(void *);
extern "C" short CountPositiveSignedByteQuantities(void *p,int i);
extern "C" unsigned char ReadGlobalElementI(unsigned int i);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char* p,int key);
extern "C" int CountEightPositiveHalfwordSlots(char* p);
extern "C" int Object_CountNonzeroFlagBytes(char* p);
// Original: arm9/ov003 @ 0x02179F34; symbol: func_ov003_02179f34; size: 0xBC.
extern "C" int GameState_CountSelectedAvailableQuantities(char *self) {
    int result = 0;
    GameState *state = (GameState*)_ZN9GameState11GetInstanceEv();
    char *list = (char*)GameState_GetIndexList(state);
    unsigned char *group = *(unsigned char**)(self + 0x89c);
    if (*(short*)(self + 0x100c) == 119) {
        int adjustment = FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(group, 29);
        int index = (short)(*(short*)(self + 0x1012) - adjustment);
        unsigned char key = ReadGlobalElementI(index);
        result = CountPositiveSignedByteQuantities(list + 0x1d4, key);
    } else {
        int index = *(signed char*)(self + 0x1043);
        int valid = result;
        if (index >= 0) valid = index <= 3;
        if (valid) {
            Object3D *object = _ZN9GameState21GetPartyMemberByIndexEi(state,index);
            if (object) result = (short)CountEightPositiveHalfwordSlots((char*)ReadWordFieldAtOffset150(object));
        } else result = Object_CountNonzeroFlagBytes(list);
    }
    return result;
}
