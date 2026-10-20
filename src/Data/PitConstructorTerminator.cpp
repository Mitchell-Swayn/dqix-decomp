#include <globaldefs.h>
#pragma define_section pit_ctor ".ctor" RW
// The constructor list contains only its null terminator; no constructor executes.
typedef void (*PitConstructor)();
__declspec(section "pit_ctor") PitConstructor SharedData_UnknownRoleInitializedBytes_Variant7 = 0;
