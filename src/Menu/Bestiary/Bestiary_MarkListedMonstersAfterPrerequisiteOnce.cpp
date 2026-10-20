#include <globaldefs.h>
#include <GameState/GameState.h>
// Original data: arm9/main @ 0x20e90d4; symbol: data_020e90d4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2c012d012e012f0130013101320133013401350136013701380139013a013b013c013d013e013f0140010000.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* GameState_GetSerializedProgressState();extern "C" int BitArray_ReadNonnegativeIndexMask(void*,void*,unsigned);extern "C" void BitArray_SetIndexedBoolean(void*,void*,unsigned,int);extern "C" unsigned char* BestiaryList_FindMonsterById(void*,int);extern short BestiaryMarkListedMonstersAfterPrerequisiteOnce_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020ABF60; symbol: func_020abf60; size: 0xC0.
extern "C" int Bestiary_MarkListedMonstersAfterPrerequisiteOnce(void* p){if(!p)return 0;unsigned char* bits=GameState_GetSerializedProgressState();if(!BitArray_ReadNonnegativeIndexMask(bits,bits+140,1942)||BitArray_ReadNonnegativeIndexMask(bits,bits+140,4419))return 0;BitArray_SetIndexedBoolean(bits,bits+140,4419,1);unsigned* flags=(unsigned*)((char*)GameState::GetInstance()+30192);struct Cursor {short* key;int index;};Cursor cursor;cursor.key=BestiaryMarkListedMonstersAfterPrerequisiteOnce_UnknownRoleInitializedBytes;cursor.index=0;for(;cursor.index<21;cursor.index++){unsigned char* record=BestiaryList_FindMonsterById(p,*cursor.key++);short index=*(short*)(record+26)-1;flags[index]|=1024;}return 1;}
