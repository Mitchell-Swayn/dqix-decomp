#include <globaldefs.h>
ARM
extern "C" void Grid_InitializeSelectionGeometry(void*);
// Original: arm9/main @ 0x0205BBCC; symbol: func_0205bbcc; size: 0x44.
extern "C" void Grid_InitializeTouchSelection(unsigned char* p){Grid_InitializeSelectionGeometry(p);*(unsigned*)(p+48)=~0U;*(unsigned*)(p+52)=0;*(unsigned short*)(p+56)=0;*(unsigned short*)(p+58)=0;*(unsigned*)(p+60)=0;*(unsigned*)(p+64)=0;*(unsigned*)(p+68)=0;*(unsigned*)(p+72)=0;p[76]=0;p[77]=0;p[78]=0;}
