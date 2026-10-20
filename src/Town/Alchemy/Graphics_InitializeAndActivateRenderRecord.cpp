#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct State;
struct RenderRecord { char name[17]; unsigned char flags; short unknown; char pad14[24]; int position[3]; char pad38[12]; int scales[3]; };
extern "C" void Object_InitializeRenderValuesAndUnitScales(void *);
extern "C" void ResourceLoader_SpawnRegisteredPresentationOnce(State* p,unsigned value);
// Original data: arm9/ov006 @ 0x2160087; symbol: data_ov006_02160087.
// Source-defined character literal. Text: "0". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "0".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern "C" char GraphicsUpdateFlaggedAnimationStages_Text0[];
// Original: arm9/ov006 @ 0x021571FC; symbol: func_ov006_021571fc; size: 0x90.
extern "C" void Graphics_InitializeAndActivateRenderRecord(char *self) {
    RenderRecord record;
    Object_InitializeRenderValuesAndUnitScales(&record);
    record.flags &= ~4;
    record.unknown = 0;
    strcpy(record.name, GraphicsUpdateFlaggedAnimationStages_Text0);
    record.scales[0] = 266;
    record.scales[1] = 266;
    record.scales[2] = 266;
    record.position[0] = -65;
    record.position[1] = -2732;
    record.position[2] = 17702;
    ResourceLoader_SpawnRegisteredPresentationOnce((State *)(self + 0x12a0), (unsigned)&record);
    *(unsigned char *)(self + 0x12bc) = 1;
}
