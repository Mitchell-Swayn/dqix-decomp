struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);extern "C" void Window_SetCanvasSuppressed(void*,int);
// Original: arm9/main @ 0x0205DEF8; symbol: func_0205def8; size: 0x40.
extern "C" void Window_SetCanvasEnabled(unsigned char* p,int enabled,int key){if(!*(void**)(p+152)||!*(void**)(p+156))return;void* item=(void*)Window_FindActiveCanvasById((WindowCanvasOwner*)(p),key);if(!item)return;Window_SetCanvasSuppressed(item,enabled==0);}
