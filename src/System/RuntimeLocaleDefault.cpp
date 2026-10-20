#include "System/RuntimeLocale.h"

char ProgramData_FormatMDY[12] = "%m/%d/%y";
// Original data: arm9/main @ 0x20eecfc; symbol: data_020eecfc.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex dcec0e0240ed0e0234ed0e021ced0e02d8ec0e0250ed0e02a8ed0e02d4ec0e02.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeTimeFormats SharedData_UnknownRoleDataReferences_Variant10;
// Original data: arm9/main @ 0x20eecec; symbol: data_020eecec.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 200000006e0000000000000030ee0e02.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeLocaleAuxiliary SharedData_UnknownRoleDataReferences_Variant9;
RuntimeLocale RuntimeWideConversionEncodeWideCharacter_UnknownRoleDataReferences = {&SharedData_UnknownRoleDataReferences_Variant10, &SharedData_UnknownRoleDataReferences_Variant9, &SharedData_UnknownRoleProcedureReferenceRecords_Variant26};
