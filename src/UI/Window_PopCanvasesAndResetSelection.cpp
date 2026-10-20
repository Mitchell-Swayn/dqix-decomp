#include <globaldefs.h>
extern "C" void Window_PopTextCanvases(void*,unsigned);extern "C" void Grid_ResetDirectionalRepeat(void*);extern "C" void Window_RefreshSelectionGeometry(void*);struct State{char pad[0x98];void* a;void* b;char gap[0x13];unsigned char mode;};
#pragma optimization_level 4
// Original: arm9/main @ 0x0205D6A0; symbol: func_0205d6a0; size: 0x44.
extern "C" ARM void Window_PopCanvasesAndResetSelection(State* p,int flag){if(!p->a||!p->b)return;unsigned char mode=1;if(flag)mode=p->mode;Window_PopTextCanvases(p,mode);Grid_ResetDirectionalRepeat((char*)p+0x54);Window_RefreshSelectionGeometry(p);}
