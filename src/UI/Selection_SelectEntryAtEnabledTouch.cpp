#include <globaldefs.h>
struct State {char pad[0x94];unsigned char ready;};extern "C" unsigned Grid_SelectCellAtActiveTouch(void*);
// Original: arm9/main @ 0x0205C6BC; symbol: func_0205c6bc; size: 0x28.
extern "C" unsigned Selection_SelectEntryAtEnabledTouch(State* self) {unsigned result=0;if(self->ready)result=Grid_SelectCellAtActiveTouch((char*)self+4);return result;}
