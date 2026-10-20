#include <globaldefs.h>
ARM
struct Obj;
struct A;
extern "C" void Window_UpdateEnabledEntryAndRoot(Obj* p,void* q);
extern "C" unsigned int Window_IsVisible(A **p);
// Original: arm9/ov003 @ 0x02176098; symbol: func_ov003_02176098; size: 0x34.
extern "C" void Window_UpdateEntryIfBitSet(char* object) {
    if (*(A***)object == 0) return;
    if (Window_IsVisible(*(A***)object) == 0) return;
    Window_UpdateEnabledEntryAndRoot(*(Obj**)object, object + 0x7d8);
}
