// Field widths and exact relocation-backed globals/callee contracts reviewed against original ARM.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Triple{unsigned x,y,z;};typedef void(*Callback)(void*);extern "C" {char* strcpy(char*,const char*);char* GameState_GetIndexList(void*);int GameState_ReadOffset5721ByteBufferLength(void*);unsigned CountSetBitsInWord(unsigned);extern char data_020fdc4c[],data_02111684[],data_02109404[];}
// Original: arm9/main @ 0x020CA364; symbol: func_020ca364; size: 0x2C.
extern "C" void Geometry_CompleteDMATransferCallback(){*(int*)data_02111684=0;Callback f=*(Callback*)(data_02111684+16);void* p=*(void**)(data_02111684+20);if(f)f(p);}
