#include "System/RuntimeLocale.h"

// Original data: arm9/main @ 0x20eecd4; symbol: data_020eecd4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char SharedData_UnknownRoleInitializedBytes_Variant52[4];
// Original data: arm9/main @ 0x20eecd8; symbol: data_020eecd8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25540000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char SharedData_UnknownRoleInitializedBytes_Variant53[4];
extern char ProgramData_TextAMPM[8];
extern char ProgramData_FormatMDY[12];
extern char ProgramData_FormatIMSP[12];
extern char ProgramData_FormatABETY[16];
extern char ProgramData_TextSunSundayMonMondayTueTuesdayWedWednesdayThuThursdayFriFridaySatSaturday[88];
extern char ProgramData_TextJanJanuaryFebFebruaryMarMarchAprAprilMayMayJunJuneJulJulyAugAugustSepSeptemberOctOctoberNovNovemText[136];

RuntimeTimeFormats SharedData_UnknownRoleDataReferences_Variant10 = {
    ProgramData_TextAMPM, ProgramData_FormatABETY, ProgramData_FormatIMSP, ProgramData_FormatMDY,
    SharedData_UnknownRoleInitializedBytes_Variant53, ProgramData_TextSunSundayMonMondayTueTuesdayWedWednesdayThuThursdayFriFridaySatSaturday, ProgramData_TextJanJanuaryFebFebruaryMarMarchAprAprilMayMayJunJuneJulJulyAugAugustSepSeptemberOctOctoberNovNovemText, SharedData_UnknownRoleInitializedBytes_Variant52
};
