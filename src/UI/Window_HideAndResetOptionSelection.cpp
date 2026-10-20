#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void Window_HideAndRequestDisplayReset(void *);void Window_ResetOptionSelection(void *);
// Original: arm9/main @ 0x020E25E8; symbol: func_020e25e8; size: 0x1C.
void Window_HideAndResetOptionSelection(void **p){Window_HideAndRequestDisplayReset(p[4]);Window_ResetOptionSelection(p);}
}
