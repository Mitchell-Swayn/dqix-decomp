#include <globaldefs.h>
#pragma optimize_for_size off
#include <GameState/GameState.h>
extern "C" int sprintf(char*,const char*,...);
static inline int Append(const char* format,char* destination){return sprintf(destination,format);}
// Original: arm9/main @ 0x0206918C; symbol: func_0206918c; size: 0x34.
extern "C" ARM void Text_AppendProtagonistFormatString(void* object,char** cursor) { object=GameState::GetInstance()->GetProtagonist(); if(!object)return; const char* format=*(const char* volatile*)((unsigned char*)object+308); int length=sprintf(*cursor,format); *cursor+=length; }
