#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
#include "GameState/GameState.h"
struct T;extern "C" int GameState_GetProgressChapter(void*);extern "C" void*Network_GetConnectionManager();extern "C" unsigned MessageTextTable_FindTextById(T*,int);struct ModeWord{signed a:9,mode:10,rest:13;};struct StateFlags{unsigned reserved:29,hidden:1,rest:2;};struct Bit{unsigned char flag:1,rest:7;};
// Original: arm9/ov023 @ 0x021E6594; symbol: func_ov023_021e6594; size: 0x118.
extern "C" ARM void Graphics_CopyContextTextForProtagonistAndSpecialMode(unsigned char*self){const char*text;GameState*state=GameState::GetInstance();unsigned char*raw=(unsigned char*)state;ModeWord*mode=(ModeWord*)(raw+0x569c);if(!((StateFlags*)(raw+0x569c))->hidden){if(GameState_GetProgressChapter(state)==1)text=(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),0x50e9);else{Network_GetConnectionManager();unsigned char*data=P(state->GetProtagonist(),0x150);int base=0x50dc;if(((Bit*)(data+0x49c))->flag==1)base+=50;text=(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),(short)(base+W(data,0x950)));}memset(self+0x1400,0,64);memcpy(self+0x1400,text,strlen(text));}if((mode+1)->mode==300){memset(self+0x1440,0,64);const char*text=(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),0x283c);memcpy(self+0x1440,text,strlen(text));}}