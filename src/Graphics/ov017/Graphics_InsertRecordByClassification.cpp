#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalDisplayManager(void);
extern "C" int InsertRecordByDescendingClassification(unsigned char*, short, int, signed char);
// Original: arm9/ov017 @ 0x021D1854; symbol: func_ov017_021d1854; size: 0x20.
extern "C" int Graphics_InsertRecordByClassification(void* unused, unsigned char* record) { void* manager = Object_GetGlobalDisplayManager(); return InsertRecordByDescendingClassification((unsigned char*)manager, *(short*)(record + 4), *(short*)(record + 6), *(signed char*)(record + 8)); }
