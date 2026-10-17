#include <globaldefs.h>
#pragma define_section ov33_ctor ".ctor" RW
// End of the overlay constructor list, following its loader initializer.
typedef void (*OverlayConstructor)();
__declspec(section "ov33_ctor") OverlayConstructor data_ov033_022a29e8 = 0;
