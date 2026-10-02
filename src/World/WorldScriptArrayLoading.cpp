#include "World/WorldScriptArrayList.h"
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

extern "C" Script::OpcodeLookupEntry data_020f121c[5];

extern "C" void func_0208d860(WorldScriptArrayList* list, SafeAllocator* allocator,
    const void* scriptData, unsigned int length, const short* keyFilter,
    short capacityOverride, unsigned short stringMask)
{
    if (!allocator || !scriptData || !length) return;
    data_02108fc0.list = list;
    list->keyFilter = keyFilter;
    data_02108fc0.list->capacityOverride = capacityOverride;
    data_02108fc0.list->stringMask = stringMask;
    data_02108fc0.allocator = allocator;
    Script script;
    script.Initialize();
    script.SetOpcodeLookup(data_020f121c);
    script.Load(scriptData, length);
    script.Execute();
}
