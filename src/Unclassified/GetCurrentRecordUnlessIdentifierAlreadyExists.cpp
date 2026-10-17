#include <globaldefs.h>
struct State {char pad[0x9c];char* records;char pad2[0x14];unsigned char index;};extern "C" void* FindReadyRecordByIdBeforeStopIndex(State*,unsigned);
// Original: arm9/main @ 0x0205E00C; symbol: func_0205e00c; size: 0x28.
extern "C" void* GetCurrentRecordUnlessIdentifierAlreadyExists(State* self,unsigned id) {if(FindReadyRecordByIdBeforeStopIndex(self,id))return 0;return self->records+self->index*0xe0;}
