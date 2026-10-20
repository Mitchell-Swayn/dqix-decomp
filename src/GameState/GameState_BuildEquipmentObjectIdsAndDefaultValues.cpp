#include <globaldefs.h>
struct IdList { int entries[11]; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" short* GameObject_GetLinkedStatsOrNull(void*);
extern "C" unsigned char* GameObject_ResolveLinkedStatsOrNull();
// Original data: arm9/main @ 0x20e8878; symbol: data_020e8878.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000000000000000000000000000000000000000000000000000000000000000000000ffffffff00a00000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" IdList GameStateBuildEquipmentObjectIdsAndDefaultValues_UnknownRoleInitializedBytes;
// Original: arm9/main @ 0x02072AFC; symbol: func_02072afc; size: 0x1A0.
extern "C" ARM void GameState_BuildEquipmentObjectIdsAndDefaultValues(int index, int* ids, short* values) {
    void* character = GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(), index);
    if (character) {
        unsigned char* defaults = GameObject_ResolveLinkedStatsOrNull();
        if (defaults) {
            short* equipment = GameObject_GetLinkedStatsOrNull(character);
            IdList list = GameStateBuildEquipmentObjectIdsAndDefaultValues_UnknownRoleInitializedBytes;
            list.entries[0] = index;
            list.entries[1] = index * 12 + 19;
            list.entries[2] = index * 12 + 20;
            list.entries[3] = index * 12 + 21;
            list.entries[4] = index * 12 + 22;
            list.entries[5] = index * 12 + 23;
            list.entries[6] = index * 12 + 25;
            list.entries[7] = index * 12 + 27;
            list.entries[8] = index * 12 + 28;
            list.entries[9] = index * 12 + 29;
            short selected[11] = {equipment[0], equipment[1], equipment[2], equipment[3], equipment[3], equipment[4], equipment[5], equipment[6], equipment[7], equipment[8], equipment[9]};
            for (int i = 0; i < 11; ++i) { ids[i] = list.entries[i]; values[i] = selected[i]; }
            if (values[0] < 0) values[0] = 1000;
            if (values[1] < 0) values[1] = 8001;
            if (values[6] < 0) values[6] = 994;
            if (values[5] < 0) {
                values[5] = *(short*)(defaults + 22);
                if (values[5] < 0) values[5] = 8010;
            }
        }
    }
}
