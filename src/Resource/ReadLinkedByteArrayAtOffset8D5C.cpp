// Field widths and exact relocation-backed globals/callee contracts reviewed against original ARM.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Triple{unsigned x,y,z;};typedef void(*Callback)(void*);extern "C" {char* strcpy(char*,const char*);char* GameState_GetIndexList(void*);int GameState_ReadOffset5721ByteBufferLength(void*);unsigned CountSetBitsInWord(unsigned);extern char data_020fdc4c[],data_02111684[],data_02109404[];}
// Original: arm9/main @ 0x0209FC9C; symbol: func_0209fc9c; size: 0x30.
extern "C" unsigned ReadLinkedByteArrayAtOffset8D5C(char* p,int i){unsigned char* q=(unsigned char*)((unsigned)*(void**)(p+4)+0x8d5c);if(!q)return 0;if(i<0){if(i>=10)return 0;}return q[i];}
