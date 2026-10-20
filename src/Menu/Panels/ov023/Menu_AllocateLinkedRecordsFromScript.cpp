#include <globaldefs.h>
#include <Resource/Script.h>
ARM
struct AllocatedRecordArray {unsigned char pad[4];void* entries;unsigned short initialized;short count;};
extern "C" void Menu_AllocateCatalogueEntries(AllocatedRecordArray*,unsigned,int);
struct ArrayCountOverride {short count;unsigned short unknown;unsigned active;unsigned allocator;AllocatedRecordArray* array;};
extern "C" ArrayCountOverride ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov023 @ 0x021E1194; symbol: Menu_AllocateLinkedRecordsFromScript; size: 0x58.
// Uses a nonzero active shared count in preference to the narrowed script count.
extern "C" int Menu_AllocateLinkedRecordsFromScript(Script::Parameter* parameter) {
 short count=parameter->ToInt();
 if(ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.active&&ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.count)
  Menu_AllocateCatalogueEntries(ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.array,ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.allocator,ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.count);
 else
  Menu_AllocateCatalogueEntries(ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.array,ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.allocator,count);
 return 1;
}
