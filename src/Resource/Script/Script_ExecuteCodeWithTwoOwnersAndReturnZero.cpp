// Original ARM and access widths reviewed; resource addresses follow exact relocations.
#include <GameState/GameState.h>
#include <Resource/Script.h>
extern "C" {int GameState_ReadAttributeBits12To19(void*,int);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);extern char* data_02110370[];}struct SignedSix{signed char value:6;unsigned char unused:1;unsigned char flag:1;};struct Direction{unsigned low:24;signed int value:3;unsigned high:5;};
extern "C" char data_02108da8[];extern "C" char data_020f0ca0[];
extern "C" char data_021536c4[];extern "C" char data_020f2e2c[];
extern "C" char data_020fdd30[];extern "C" char data_020ef6f4[];
// Original: arm9/main @ 0x020E57F4; symbol: func_020e57f4; size: 0x5C.
extern "C" int Script_ExecuteCodeWithTwoOwnersAndReturnZero(int a,int b,const void* code,unsigned size){int* g=(int*)data_021536c4;g[1]=a;g[0]=b;Script s;s.Initialize();s.SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f2e2c);s.Load(code,size);s.Execute();return 0;}
