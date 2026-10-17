#include <globaldefs.h>
#pragma define_section stage_ctor ".ctor" RW
// This overlay has no static constructors: the list is only its terminator.
typedef void (*StageConstructor)();
extern "C" {
__declspec(section "stage_ctor") StageConstructor data_ov021_0218bbd4 = 0;
}
