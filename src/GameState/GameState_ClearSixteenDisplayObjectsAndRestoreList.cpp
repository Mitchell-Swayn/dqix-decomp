#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" void GameState_ClearObjectByIndex(GameState*,unsigned);
extern "C" void ObjectPool_ResetDisplayEntry(void*);
struct ResetRecord {unsigned words[0x355];};
// Original: arm9/main @ 0x0205859C; symbol: func_0205859c; size: 0x7C.
extern "C" void GameState_ClearSixteenDisplayObjectsAndRestoreList(ResetRecord* p) {GameState* state=GameState::GetInstance();for(int i=0;i<16;i++)GameState_ClearObjectByIndex(state,i+0xd0);for(int i=0;i<16;i++)ObjectPool_ResetDisplayEntry((char*)p+8+i*0xd4);p->words[0x352]=0;if(p->words[0x353]){*(unsigned*)(p->words[0x353]+0x1ec)=0;p->words[1]=p->words[0x354];}else{p->words[0]=0;p->words[1]=0;}}
