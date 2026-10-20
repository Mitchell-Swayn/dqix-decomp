#include <globaldefs.h>
ARM
extern "C" int Grid_ReadLinearIndexWhenEnabled(void*);extern "C" int Grid_ComputeSelectedLinearIndex(void*);
// Original: arm9/main @ 0x0205C570; symbol: func_0205c570; size: 0x40.
extern "C" int Selection_GetActiveInputIndex(unsigned char* p){int result=-1;if(p[148]&&p[80])result=Grid_ReadLinearIndexWhenEnabled(p+4);if(p[149])result=Grid_ComputeSelectedLinearIndex(p+84);return result;}
