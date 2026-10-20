#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
struct Source {unsigned a,b,c,d;unsigned char bytes[0x333];};extern "C" void GameState_SetProgressChapter(GameState*,unsigned);extern "C" void GameState_SetProgressStage(GameState*,unsigned);extern "C" void GameState_SetProgressStep(GameState*,unsigned);extern "C" void GameState_SetUnknown5cbc(GameState*,unsigned);extern "C" void SaveData_CopyGameFlagRecord(void*,void*);
// Original: arm9/main @ 0x020A9A50; symbol: func_020a9a50; size: 0xA8.
extern "C" int GameState_CopySourceBytesAndSelectedInitialFields(Source* source,char* output,int full) {GameState* state=GameState::GetInstance();GameState_SetProgressChapter(state,source->a);GameState_SetProgressStage(state,source->b);GameState_SetProgressStep(state,source->c);GameState_SetUnknown5cbc(state,source->d);if(full){memcpy(output,source->bytes,0x8c);memcpy(output+0x8c,source->bytes+0x8c,0x15f);memcpy(output+0x2c0,source->bytes+0x2c0,12);memcpy(output+0x2cc,source->bytes+0x2cc,0x66);output[0x332]=source->bytes[0x332];}else SaveData_CopyGameFlagRecord(output,source->bytes);return 1;}
