#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
extern "C" {
// Original: arm9/main @ 0x02058618; symbol: func_02058618; size: 0x40.
extern "C" int GameState_CountObjectsInD0ThroughDFSlots(void* unusedDisplay){GameState *p=GameState::GetInstance();int count=0;for(int i=0;i<16;i++)if(p->GetGameObjectByIndex(i+0xd0))count++;return count;}
}
