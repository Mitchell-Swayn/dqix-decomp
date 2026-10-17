#include <globaldefs.h>
struct State {char pad[0x94];unsigned char ready;};extern "C" unsigned TestCurrentCoordinatesResolveValidEntry(void*);
// Original: arm9/main @ 0x0205C6BC; symbol: func_0205c6bc; size: 0x28.
extern "C" unsigned Object_ReadSelectionResultWhenReady(State* self) {unsigned result=0;if(self->ready)result=TestCurrentCoordinatesResolveValidEntry((char*)self+4);return result;}
