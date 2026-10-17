#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" unsigned char* ReadGlobalValueAt02108844();extern "C" int ReadNonnegativeIndexedBit(void*,void*,unsigned);extern "C" void BitArray_SetIndexedBoolean(void*,void*,unsigned,int);extern "C" unsigned char* func_02097430(void*,int);extern short data_020e90d4[];
// Original: arm9/main @ 0x020ABF60; symbol: func_020abf60; size: 0xC0.
extern "C" int SetRecordFlagsOnceAfterPrerequisiteBit(void* p){if(!p)return 0;unsigned char* bits=ReadGlobalValueAt02108844();if(!ReadNonnegativeIndexedBit(bits,bits+140,1942)||ReadNonnegativeIndexedBit(bits,bits+140,4419))return 0;BitArray_SetIndexedBoolean(bits,bits+140,4419,1);unsigned* flags=(unsigned*)((char*)GameState::GetInstance()+30192);struct Cursor {short* key;int index;};Cursor cursor;cursor.key=data_020e90d4;cursor.index=0;for(;cursor.index<21;cursor.index++){unsigned char* record=func_02097430(p,*cursor.key++);short index=*(short*)(record+26)-1;flags[index]|=1024;}return 1;}
