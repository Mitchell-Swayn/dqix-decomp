#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" void* Combat_GetCommandActorSnapshot(unsigned, unsigned);
extern "C" void Graphics_SetPolygonIdForPartyObjectGroup(void*, unsigned, int);
// Original: arm9/ov025 @ 0x021E8638; symbol: func_ov025_021e8638; size: 0x38.
extern "C" int Combat_SetPrimaryActorGroupPolygonId(char* self, unsigned index) {
    void* resources = GameResources_GetInstance();
    void* record = Combat_GetCommandActorSnapshot(index, 0);
    Graphics_SetPolygonIdForPartyObjectGroup(resources, *(unsigned short*)((char*)record + 0x20), *(signed char*)(self + 8));
    return 1;
}
