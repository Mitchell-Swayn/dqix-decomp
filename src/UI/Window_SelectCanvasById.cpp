#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Window_RefreshSelectionGeometry(void*);
// Original: arm9/main @ 0x0205DEE8; symbol: func_0205dee8; size: 0x10.
extern "C" void Window_SelectCanvasById(unsigned char* p,unsigned mode){p[176]=mode;Window_RefreshSelectionGeometry(p);}
