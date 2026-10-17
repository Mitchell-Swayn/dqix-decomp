#include <globaldefs.h>

// Overlay 18 has no initialization routines. The loader traverses the bounded
// constructor list and skips this null entry; trailing bytes align the module.
typedef void (*Overlay18Constructor)();
#pragma define_section overlay18_ctor ".ctor" RW
__declspec(section "overlay18_ctor") Overlay18Constructor data_ov018_0218b5a0 = 0;
