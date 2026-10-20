#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0205CE28; symbol: func_0205ce28; size: 0x28.
extern "C" bool UI_IsPanelTransitionHidden(unsigned char* p) { unsigned int* q=*(unsigned int**)(p+0x440); if (!q) return true; return q[2]==0; }
