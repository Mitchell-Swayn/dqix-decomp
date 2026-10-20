struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
// Original: arm9/main @ 0x0205DEB4; symbol: func_0205deb4; size: 0x34.
extern "C" void Window_SetCanvasDisplayAttribute(char* p,int a,int value){if(!*(void**)(p+152)||!*(void**)(p+156))return;char* e=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(p),a);if(e)*(unsigned short*)(e+194)=(unsigned short)(value&15)&15;}
