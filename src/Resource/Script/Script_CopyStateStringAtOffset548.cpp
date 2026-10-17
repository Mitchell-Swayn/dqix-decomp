// Field widths and exact relocation-backed globals/callee contracts reviewed against original ARM.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Triple{unsigned x,y,z;};typedef void(*Callback)(void*);extern "C" {char* strcpy(char*,const char*);char* GameState_GetIndexList(void*);int GameState_ReadOffset5721ByteBufferLength(void*);unsigned CountSetBitsInWord(unsigned);extern char data_020fdc4c[],data_02111684[],data_02109404[];}
// Original: arm9/main @ 0x0201F634; symbol: func_0201f634; size: 0x2C.
extern "C" int Script_CopyStateStringAtOffset548(const Script::Parameter* p){const char* s=p->ToString();strcpy(*(char**)(data_020fdc4c+16)+0x548,s);return 1;}
