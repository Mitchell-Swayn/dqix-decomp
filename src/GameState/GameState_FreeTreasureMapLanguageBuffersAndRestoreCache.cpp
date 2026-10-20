#include <globaldefs.h>
ARM
#include <GameState/GameState.h>

extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable();
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/main @ 0x020A395C; symbol: func_020a395c; size: 0x7C.
extern "C" void GameState_FreeTreasureMapLanguageBuffersAndRestoreCache() {
    GameState* state=GameState::GetInstance();
    char* map=(char*)GameResources_GetInstance();
    unsigned char* language=state->GetTreasureMapLanguageData();
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,*(void**)(map+0x448c));
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,language);
    if (*(unsigned char*)(map+0x4490)) {
        FileCache_RestoreRomTablesIfSpaceAvailable();
        *(unsigned char*)(map+0x4490)=0;
    }
    state->SetTreasureMapLanguageDataPtr(0);
    *(unsigned*)(map+0x448c)=0;
}
