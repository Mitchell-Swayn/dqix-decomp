#include <globaldefs.h>
#pragma define_section menu_ctor ".ctor" RW
typedef void (*MenuConstructor)();
// Null constructor-list terminator, not a callable routine.
__declspec(section "menu_ctor") MenuConstructor data_ov019_0218c2ac = 0;
