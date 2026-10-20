#include "Resource/Script.h"
#include "World/WorldScriptArrayList.h"
#include "Memory/SafeAllocator.h"
struct TextArrayContext { SafeAllocator* allocator; WorldScriptArrayList* list; };
// Original data: arm9/main @ 0x2108fc0; symbol: data_02108fc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" TextArrayContext WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage;
extern "C" void AllocateWorldScriptArrayEntries(WorldScriptArrayList*,SafeAllocator*,int);
// Uses the context ID count when present, otherwise the script-provided signed capacity.
// Original: arm9/main @ 0x0208D550; symbol: func_0208d550; size: 0x44.
extern "C" int WorldScriptText_AllocateSelectedEntries(Script::Parameter* parameters,int) {
 short requested=(short)parameters->ToInt();
 WorldScriptArrayList* list=WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.list;
 short contextCount=(short)list->unknownC;
 if(contextCount)AllocateWorldScriptArrayEntries(list,WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.allocator,contextCount);
 else AllocateWorldScriptArrayEntries(list,WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.allocator,requested);
 return 1;
}
