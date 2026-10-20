#include <globaldefs.h>
extern "C" int Menu_ReadScriptArgumentAsInteger(void*);
extern "C" float Menu_ReadScriptArgumentAsFloat(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void Menu_SetSpriteCellTouchRectangle(void*,unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned Menu_WriteGridEntry(void*,unsigned,unsigned,unsigned);
extern "C" void Graphics_CaptureMainBackgroundVramBanks(void*);
extern "C" void Graphics_CaptureSubBackgroundVramBanks(void*);
extern "C" void MapVRAMBanksToMainBG(unsigned);
extern "C" void MapVRAMBanksToSubBG(unsigned);
extern "C" void ColorEffect_ConfigureAlphaBlend(void*,unsigned,unsigned,unsigned,unsigned);
typedef void (*Setup)(unsigned,unsigned,unsigned,unsigned,unsigned);
typedef void (*Priority)(unsigned);
struct SetupTable { Setup entries[2][4]; };
struct PriorityTable { Priority entries[2][4]; };
struct MainBankTable { unsigned values[17]; };
struct SubBankTable { unsigned values[4]; };
// Original data: arm9/ov011 @ 0x2188914; symbol: data_ov011_02188914.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 706218023c62180210621802e4611802b06118027c6118025061180224611802.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov011.md.
extern "C" const SetupTable MenuConfigureBackgroundControlFromArguments_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/ov011 @ 0x2188934; symbol: data_ov011_02188934.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 2464180208641802ec631802d0631802b4631802986318027c63180260631802.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov011.md.
extern "C" const PriorityTable MenuSetBackgroundPrioritiesFromTaggedArguments_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/ov011 @ 0x2188954; symbol: data_ov011_02188954.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000002000000040000000600000001000000030000000700000000100000002000000040000000800000003000000060000000c000000070000000e000000 ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov011.md.
extern "C" const MainBankTable MapIndexedMainBackgroundVramBankConfiguration_UnknownRoleInitializedBytes;
// Original data: arm9/ov011 @ 0x2188904; symbol: data_ov011_02188904.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000040000008000000080010000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov011.md.
extern "C" const SubBankTable MapIndexedSubBackgroundVramBankConfiguration_UnknownRoleInitializedBytes;
struct Vector { int x,y,z; };
struct Object { void (**methods)(); };
// Original: arm9/ov011 @ 0x02188090; symbol: func_ov011_02188090; size: 0x48.
extern "C" unsigned MapIndexedSubBackgroundVramBankConfiguration(void* self) { Graphics_CaptureSubBackgroundVramBanks(Resource_GetSharedLoadState()); unsigned index=Menu_ReadScriptArgumentAsInteger(self); SubBankTable table=MapIndexedSubBackgroundVramBankConfiguration_UnknownRoleInitializedBytes; MapVRAMBanksToSubBG(table.values[index]); return 1; }
