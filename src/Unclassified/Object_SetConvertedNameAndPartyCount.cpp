#include <globaldefs.h>
ARM
struct GameState { static GameState *GetInstance(); };
extern "C" void __clear(void *,unsigned);
extern "C" void EncodeTextAsGlyphIds(void *,char *,int);
extern "C" unsigned strlen(const char *);
extern "C" void *memcpy(void *,const void *,unsigned);
extern "C" void GameState_CollectPresentIndicesAmongFirstFour(void *,void *,int *);
// Original: arm9/main @ 0x0202C360; symbol: func_0202c360; size: 0x80.
extern "C" void Object_SetConvertedNameAndPartyCount(char *self,void *text) { int value; char name[20]; unsigned char state[16]; void *game=GameState::GetInstance(); __clear(name,20); EncodeTextAsGlyphIds(text,name,1); self[0x1028]=strlen(name); memcpy(self+0x1014,name,(unsigned char)self[0x1028]+1); GameState_CollectPresentIndicesAmongFirstFour(game,state,&value); self[0x1027]=value; }
