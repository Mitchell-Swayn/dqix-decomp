#include "System/RuntimeLocale.h"

#pragma define_section locale_data ".data" RW

// Original fixed-width, zero-padded C-locale text fields.
__declspec(section "locale_data") char SharedData_UnknownRoleInitializedBytes_Variant52[4] = "";
char SharedData_UnknownRoleInitializedBytes_Variant53[4] = "%T";
char ProgramData_TextAMPM[8] = "AM|PM";

extern "C" int Runtime_ConvertByteToWideCharacter(unsigned short*, const char*, unsigned int);
extern "C" int Runtime_WriteSingleByteCharacter(char*, unsigned short);
RuntimeCharacterMethods SharedData_UnknownRoleProcedureReferenceRecords_Variant26 = {Runtime_ConvertByteToWideCharacter, Runtime_WriteSingleByteCharacter};
