#include <globaldefs.h>
extern "C" {
    void Window_ResetOptionSelection(void *);
    void Window_CreateTwoTextOptionLayout(void *,int);
    void Window_ReadCoordinatesAndApplyMargins(void *);
// Original: arm9/main @ 0x020E280C; symbol: func_020e280c; size: 0x28.
    void Window_CreateOptionLayoutAndResetSelection(unsigned char *p,int value){
        Window_ResetOptionSelection(p);
        Window_CreateTwoTextOptionLayout(*(void **)(p+16),value);
        Window_ReadCoordinatesAndApplyMargins(p);
    }
}
