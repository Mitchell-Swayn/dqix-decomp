#include "World/WorldPlacementSource.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
// Original data: arm9/main @ 0x2108fe4; symbol: data_02108fe4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" WorldPlacementSource WorldPlacementSourceInitializeSingleton_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x0208E444; symbol: func_0208e444; size: 0x78.
// Reads opcode104: installs16signedshort placement values when selector matches.
extern "C" int WorldPlacement_ReadSelectedShortValueTable(Script::Parameter* parameters, int)
{
    unsigned char selector=GameState::GetInstance()->unknownPlacementByte_5cda_;
    unsigned char requested=(unsigned char)parameters->ToInt();
    ++parameters;
    if(selector==requested) {
        SafeAllocator* allocator=&GameResources_GetInstance()->allocator_array_1a0[0];
        short* values=WorldPlacementSourceInitializeSingleton_UnknownRoleZeroInitializedStorage.randomValues=(short*)allocator->Allocate(32);
        for(int i=0;i<16;i++) {
            int value=parameters->ToInt();
            ++parameters;
            *values=value;
            ++values;
        }
    }
    return 1;
}
