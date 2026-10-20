#include <globaldefs.h>
ARM
extern "C" {int Grid_GetEntryCount(void*);void Grid_SelectIndexAndComputePageCoordinates(void*,int);void Grid_SelectIndexAndInvalidateTouchHistory(void*,int);
// Original: arm9/main @ 0x0205D7A0; symbol: func_0205d7a0; size: 0x7C.
void Window_SetEnabledSelectionIndices(unsigned char* p,int index){int value=(int)p;if(p[0x95])value=Grid_GetEntryCount(p+0x54);else if(p[0x94])value=Grid_GetEntryCount(p+4);if(index<0&&value<=index)return;if(p[0x95])Grid_SelectIndexAndComputePageCoordinates(p+0x54,index);if(p[0x94])Grid_SelectIndexAndInvalidateTouchHistory(p+4,index);}}
