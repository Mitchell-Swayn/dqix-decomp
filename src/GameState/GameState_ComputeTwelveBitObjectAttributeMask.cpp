#include <globaldefs.h>
#include <GameState/GameState.h>
struct Unit {char pad[0x150];char* records;};
extern "C" Unit* GameState_GetObjectWithFlag100(GameState*,unsigned);
extern "C" int Object_ReadIndexedBitAtOffset8EC(void*,unsigned short);
extern "C" unsigned Lookup_ReadThirteenByFiveByteTable(unsigned,unsigned);
extern "C" int CountPositiveGroupedValuesMatchingMask(unsigned);
extern "C" unsigned short data_020f29f4[];
// Original: arm9/main @ 0x020DD3CC; symbol: func_020dd3cc; size: 0xF8.
extern "C" unsigned GameState_ComputeTwelveBitObjectAttributeMask(unsigned id){Unit* p=GameState_GetObjectWithFlag100(GameState::GetInstance(),id);if(!p)return 0;unsigned result=0;for(unsigned short i=0;i<=11;i++)if(Object_ReadIndexedBitAtOffset8EC(p->records,data_020f29f4[i]))result|=1u<<i;unsigned flags=*(unsigned*)(p->records+0x950);for(unsigned char i=0;i<4;i++){unsigned value=Lookup_ReadThirteenByFiveByteTable(flags&0xff,i);if(value&&value>=1&&value<=12)result|=1u<<((value-1)&0xff);}for(unsigned i=0;i<=11;i++){unsigned bit=1u<<i;if((result&(1u<<i))&&CountPositiveGroupedValuesMatchingMask(bit)==0)result&=~bit;}return result;}
