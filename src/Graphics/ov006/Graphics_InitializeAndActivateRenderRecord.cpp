#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct State;
struct RenderRecord { char name[17]; unsigned char flags; short unknown; char pad14[24]; int position[3]; char pad38[12]; int scales[3]; };
extern "C" void Object_InitializeRenderValuesAndUnitScales(void *);
extern "C" void ProcessTypeTwoRecordOnceAndMarkActive(State* p,unsigned value);
extern "C" char data_ov006_02160087[];
// Original: arm9/ov006 @ 0x021571FC; symbol: func_ov006_021571fc; size: 0x90.
extern "C" void Graphics_InitializeAndActivateRenderRecord(char *self) {
    RenderRecord record;
    Object_InitializeRenderValuesAndUnitScales(&record);
    record.flags &= ~4;
    record.unknown = 0;
    strcpy(record.name, data_ov006_02160087);
    record.scales[0] = 266;
    record.scales[1] = 266;
    record.scales[2] = 266;
    record.position[0] = -65;
    record.position[1] = -2732;
    record.position[2] = 17702;
    ProcessTypeTwoRecordOnceAndMarkActive((State *)(self + 0x12a0), (unsigned)&record);
    *(unsigned char *)(self + 0x12bc) = 1;
}
