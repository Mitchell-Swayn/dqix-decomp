#include <globaldefs.h>
ARM
#include <GameState/GameState.h>

extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void func_020a0c0c();
extern "C" char data_02114e20[];
// Original: arm9/main @ 0x020A395C; symbol: func_020a395c; size: 0x7C.
extern "C" void GameState_FreeTreasureMapLanguageBuffersAndRestoreCache() {
    GameState* state=GameState::GetInstance();
    char* map=(char*)GameResources_GetInstance();
    unsigned char* language=state->GetTreasureMapLanguageData();
    Memory_FreeThroughAllocatorUnion(data_02114e20,*(void**)(map+0x448c));
    Memory_FreeThroughAllocatorUnion(data_02114e20,language);
    if (*(unsigned char*)(map+0x4490)) {
        func_020a0c0c();
        *(unsigned char*)(map+0x4490)=0;
    }
    state->SetTreasureMapLanguageDataPtr(0);
    *(unsigned*)(map+0x448c)=0;
}
