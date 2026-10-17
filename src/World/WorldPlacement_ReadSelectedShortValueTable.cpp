#include "World/WorldPlacementSource.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
extern "C" WorldPlacementSource data_02108fe4;
// Original: arm9/main @ 0x0208E444; symbol: func_0208e444; size: 0x78.
// Reads opcode104: installs16signedshort placement values when selector matches.
extern "C" int WorldPlacement_ReadSelectedShortValueTable(Script::Parameter* parameters, int)
{
    unsigned char selector=GameState::GetInstance()->unknownPlacementByte_5cda_;
    unsigned char requested=(unsigned char)parameters->ToInt();
    ++parameters;
    if(selector==requested) {
        SafeAllocator* allocator=&GameResources_GetInstance()->allocator_array_1a0[0];
        short* values=data_02108fe4.randomValues=(short*)allocator->Allocate(32);
        for(int i=0;i<16;i++) {
            int value=parameters->ToInt();
            ++parameters;
            *values=value;
            ++values;
        }
    }
    return 1;
}
