#include <globaldefs.h>
ARM
extern "C" void* Zone3D_GetMainInstance(void);
extern "C" void* GameState_GetSerializedProgressState(void);
extern "C" void Zone3D_StartContainerBreakAnimation(void*, unsigned);
extern "C" void* ZoneState_GetTrackedZoneCache(void);
extern "C" void* ZoneState_FindTrackedZoneByIdentifier(void*, int);
extern "C" void Object_SetBoundedTwelveBitFlag(void*, int);
extern "C" void BitArray_SetIndexedBoolean(void*, unsigned char*, int, int);
// Original: arm9/ov017 @ 0x021B6174; symbol: func_ov017_021b6174; size: 0x70.
extern "C" void Field_MarkContainerBrokenAndLootCollected(unsigned key, unsigned value, int bit) {
    unsigned short* first = (unsigned short*)Zone3D_GetMainInstance();
    void* second = GameState_GetSerializedProgressState();
    if (key == *first) Zone3D_StartContainerBreakAnimation(first, value);
    void* record = ZoneState_FindTrackedZoneByIdentifier(ZoneState_GetTrackedZoneCache(), key);
    if (record != 0) Object_SetBoundedTwelveBitFlag(record, value);
    BitArray_SetIndexedBoolean(second, (unsigned char*)second + 0x8c, bit + 0x79e, 1);
}
