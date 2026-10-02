#include "World/WorldScriptZoneRecord.h"
#include "World/Zone3D.h"
#include "Resource/Script.h"
#include "std_library_functions.h"

extern "C" int func_0208daf4(Script::Parameter* parameters, int)
{
    if (data_02108fc8.matched == 1) return 0;
    int value0 = (parameters++)->ToInt();
    int selector0 = (parameters++)->ToInt();
    int selector1 = (parameters++)->ToInt();
    if (selector0 != data_02108fc8.info->unknown_0_ &&
        selector1 != data_02108fc8.info->unknown_0_) return 0;
    data_02108fc8.record->unknown0 = value0;
    data_02108fc8.record->selector0 = selector0;
    data_02108fc8.record->selector1 = selector1;
    const char* name = (parameters++)->ToString();
    memcpy(data_02108fc8.record->name, name, 16);
    data_02108fc8.record->name[15] = 0;
    data_02108fc8.record->unknown14 = (parameters++)->ToInt();
    data_02108fc8.record->unknown18 = (parameters++)->ToFloat();
    parameters = parameters->ToVec3fix(&data_02108fc8.record->vector);
    data_02108fc8.record->unknown28 = (fix16_t)(parameters->ToFloat() * 4096.0f);
    data_02108fc8.matched = 1;
    return 1;
}
