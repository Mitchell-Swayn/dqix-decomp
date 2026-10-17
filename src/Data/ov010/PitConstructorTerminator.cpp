#include <globaldefs.h>
#pragma define_section pit_ctor ".ctor" RW
// The constructor list contains only its null terminator; no constructor executes.
typedef void (*PitConstructor)();
__declspec(section "pit_ctor") PitConstructor data_ov010_02184a6c = 0;
