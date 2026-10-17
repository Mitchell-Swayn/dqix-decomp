#include <globaldefs.h>
ARM
extern "C" {int ReadFirstValue_Main0205BAFC(void*);void ComputePageRowAndColumn(void*,int);void Selection_InvalidateIndexAndComputePageCoordinates(void*,int);
// Original: arm9/main @ 0x0205D7A0; symbol: func_0205d7a0; size: 0x7C.
void Object_SetEnabledSelectionRecordIndices(unsigned char* p,int index){int value=(int)p;if(p[0x95])value=ReadFirstValue_Main0205BAFC(p+0x54);else if(p[0x94])value=ReadFirstValue_Main0205BAFC(p+4);if(index<0&&value<=index)return;if(p[0x95])ComputePageRowAndColumn(p+0x54,index);if(p[0x94])Selection_InvalidateIndexAndComputePageCoordinates(p+4,index);}}
