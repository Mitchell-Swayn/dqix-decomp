#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned char* GameState_FindCharacterStateByObjectIndex(void*,int);extern "C" unsigned char* GameState_FindUnusedIndexedRecord(void*);extern "C" void GameObject_AttachIndexedStateAndDerivedPointers(void*,void*);extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/main @ 0x02053C74; symbol: func_02053c74; size: 0x50.
extern "C" void GameState_AttachOrCreateIndexedCharacterState(void* p,int index){void* state=_ZN9GameState11GetInstanceEv();unsigned char* entry=GameState_FindCharacterStateByObjectIndex(state,index);if(!entry){entry=GameState_FindUnusedIndexedRecord(state);if(entry)*(short*)(entry+0x568)=index;else DisableInterruptsAndHaltForever();}GameObject_AttachIndexedStateAndDerivedPointers(p,entry);}
