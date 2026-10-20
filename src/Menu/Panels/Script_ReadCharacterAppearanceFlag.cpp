#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void *Script_ResolveCharacterFromSignedSelector(int);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov023 @ 0x021E93E0; symbol: ResolveSelectedCharacterLowFlag_v02; size: 0x44.
extern "C" int Script_ReadCharacterAppearanceFlag(void* parameter) { _ZN9GameState11GetInstanceEv(); int selector=Script_ReadParameterAsInteger(parameter); void* character=Script_ResolveCharacterFromSignedSelector(selector); if(!character)return 0; unsigned char* model=*(unsigned char**)((unsigned char*)character+0x150); int flag=(int)model[0x49c]; flag=(int)((unsigned int)flag<<31); flag=(unsigned int)flag>>31; Script_WriteIntegerReferenceOutput((unsigned char*)parameter+8,flag); return 1; }
