// Original data: arm9/ov019 @ 0x218c2ac; symbol: data_ov019_0218c2ac.
// Null constructor-list terminator, not a callable routine.
// Initial values: hex 0000000000000000000000000000000000000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov019.md.
#include <globaldefs.h>
#pragma define_section menu_ctor ".ctor" RW
typedef void (*MenuConstructor)();
// Null constructor-list terminator, not a callable routine.
__declspec(section "menu_ctor") MenuConstructor SharedData_NullConstructorListTerminatorNotACallableRoutine = 0;
