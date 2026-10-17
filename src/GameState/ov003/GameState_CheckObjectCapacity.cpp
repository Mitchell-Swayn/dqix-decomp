#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void* state);
extern "C" int Object_SumKeyValuesAcrossThreeContainers(unsigned char* object, int id);
// Original: arm9/ov003 @ 0x02179DA8; symbol: func_ov003_02179da8; size: 0x70.
extern "C" int GameState_CheckObjectCapacity(unsigned char* object, int useObjectTotal) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* list = GameState_GetIndexList(state);
    int total = 1;
    if (useObjectTotal) total = Object_SumKeyValuesAcrossThreeContainers((unsigned char*)list, *(short*)(object + 0x18));
    unsigned limit = 0x0098967f;
    if (*(unsigned*)((char*)list + 0xf6c) + *(unsigned short*)(object + 0x1a) > limit) return 2;
    if (total == 1) return 1;
    return *(unsigned*)((char*)list + 0xf6c) + (*(unsigned short*)(object + 0x1a) << 1) > limit;
}
