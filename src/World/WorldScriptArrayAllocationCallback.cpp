#include "World/WorldScriptArrayList.h"
#include "Resource/Script.h"

extern "C" int func_0208d550(Script::Parameter* parameters, int)
{
    short capacity = (short)parameters->ToInt();
    if (data_02108fc0.list->capacityOverride)
        func_0208d8ec(data_02108fc0.list, data_02108fc0.allocator,
                     data_02108fc0.list->capacityOverride);
    else
        func_0208d8ec(data_02108fc0.list, data_02108fc0.allocator, capacity);
    return 1;
}
