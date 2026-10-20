#include <globaldefs.h>
struct State {int count;char pad[44];int index;};extern "C" void Grid_SelectIndexAndComputePageCoordinates(State*,int);
// Original: arm9/main @ 0x0205BCDC; symbol: func_0205bcdc; size: 0x28.
extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(State* self,int index) {if(index<0)return;if(self->count<=index)return;self->index=-1;Grid_SelectIndexAndComputePageCoordinates(self,index);}
