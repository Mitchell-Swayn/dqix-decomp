#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void GameState_SetProgressChapter(GameState*,unsigned char); extern "C" void GameState_SetProgressStage(GameState*,unsigned char); extern "C" void GameState_SetProgressStep(GameState*,unsigned char);
// Original: arm9/main @ 0x0206DF14; symbol: func_0206df14; size: 0x58.
 extern "C" void GameState_CopySelectedRecordInitialThreeBytes(unsigned char* p){GameState* g=GameState::GetInstance();GameState_SetProgressChapter(g,p[(short)p[0x332]*(short)28]);GameState_SetProgressStage(g,(p+(unsigned)p[0x332]*28)[1]);GameState_SetProgressStep(g,(p+(unsigned)p[0x332]*28)[2]);}
