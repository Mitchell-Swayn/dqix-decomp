#include <globaldefs.h>
ARM
extern "C" {int Grid_ComputeSelectedLinearIndex(int*);void Grid_SelectIndexAndComputePageCoordinates(int*,int);
// Original: arm9/main @ 0x0205C4A8; symbol: func_0205c4a8; size: 0x60.
void Grid_AdvanceWrappedPageAndClampSelection(int* p,int delta){int value=p[5]+delta;p[5]=value;int limit=p[1];if(limit<=value)p[5]=p[5]-limit;else if(value<0)p[5]=p[5]+limit;int count=p[0];if(count<=Grid_ComputeSelectedLinearIndex(p))Grid_SelectIndexAndComputePageCoordinates(p,count-1);}}
