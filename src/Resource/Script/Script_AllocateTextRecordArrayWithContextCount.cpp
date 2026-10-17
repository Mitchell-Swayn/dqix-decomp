#include "Resource/Script.h"
#include "World/WorldScriptArrayList.h"
#include "Memory/SafeAllocator.h"
struct TextArrayContext { SafeAllocator* allocator; WorldScriptArrayList* list; };
extern "C" TextArrayContext data_02108fc0;
extern "C" void AllocateWorldScriptArrayEntries(WorldScriptArrayList*,SafeAllocator*,int);
// Uses the context ID count when present, otherwise the script-provided signed capacity.
// Original: arm9/main @ 0x0208D550; symbol: func_0208d550; size: 0x44.
extern "C" int Script_AllocateTextRecordArrayWithContextCount(Script::Parameter* parameters,int) {
 short requested=(short)parameters->ToInt();
 WorldScriptArrayList* list=data_02108fc0.list;
 short contextCount=(short)list->unknownC;
 if(contextCount)AllocateWorldScriptArrayEntries(list,data_02108fc0.allocator,contextCount);
 else AllocateWorldScriptArrayEntries(list,data_02108fc0.allocator,requested);
 return 1;
}
