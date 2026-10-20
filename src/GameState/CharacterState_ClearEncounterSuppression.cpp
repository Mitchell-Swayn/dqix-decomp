#include <globaldefs.h>

extern "C" int GameResources_GetInstance();
extern "C" void Field_UpdateCombatantAppearanceFlags(int, int, int, int);
extern "C" void Network_QueueTypeSeventeenRecord(int, int, int, unsigned short);

// Original: arm9/main @ 0x02083C48; symbol: func_02083c48; size: 0x58.
extern "C" void CharacterState_ClearEncounterSuppression(unsigned char* self, int arg, int flag, int arg4) {
    self[0x56c] = 0;
    if (flag != 0) {
        Field_UpdateCombatantAppearanceFlags(GameResources_GetInstance(), 0,
                            *(short*)(self + 0x568), 2);
    }
    if (arg != 0) {
        Network_QueueTypeSeventeenRecord(0, 1, 0, *(unsigned short*)(self + 0x568));
    }
}
