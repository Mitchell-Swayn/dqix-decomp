#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void GameState_SetField5CB0AndSelectedRecordFirstByte(GameState*,unsigned char); extern "C" void GameState_WriteField5CB4AndIndexedRecordValue(GameState*,unsigned char); extern "C" void GameState_SetWord5CB8AndSelectedRecordByte(GameState*,unsigned char);
// Original: arm9/main @ 0x0206DF14; symbol: func_0206df14; size: 0x58.
 extern "C" void GameState_CopySelectedRecordInitialThreeBytes(unsigned char* p){GameState* g=GameState::GetInstance();GameState_SetField5CB0AndSelectedRecordFirstByte(g,p[(short)p[0x332]*(short)28]);GameState_WriteField5CB4AndIndexedRecordValue(g,(p+(unsigned)p[0x332]*28)[1]);GameState_SetWord5CB8AndSelectedRecordByte(g,(p+(unsigned)p[0x332]*28)[2]);}
