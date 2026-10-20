#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" void Statistics_AddCollectedIdCount(unsigned char*,unsigned);
extern "C" int GameState_MergePositiveIdsIntoBitset(unsigned*,const short*,int);
extern "C" int GameState_CopyCollectionFlagBitset(void*);
extern "C" int GameState_StoreStatisticsRecord(const void*);
extern "C" bool GameState_CopyStatisticsRecord(void*);
struct Buffer {unsigned char pad[16];unsigned counter:9;unsigned rest:23;unsigned char pad2[156];};
// Original: arm9/ov023 @ 0x021ED724; symbol: func_ov023_021ed724; size: 0xBC.
extern "C" int GameState_MergeIdsAndIncrementPackedCounter(void* owner,const short* source,int count){
 short ids[50];Buffer buffer;unsigned bits[15];
 if(!owner)return 0;if(!source)return 0;if(!count)return 0;
 int result=0;
 GameState_CopyCollectionFlagBitset(bits);
 memset(ids,0,100);
 for(int i=0;i<count;i++)ids[i]=source[i];
 GameState_MergePositiveIdsIntoBitset(bits,ids,count);
 GameState_CopyStatisticsRecord(&buffer);
 if(!buffer.counter)result|=1;
 Statistics_AddCollectedIdCount((unsigned char*)&buffer,count);
 GameState_StoreStatisticsRecord(&buffer);
 return result;
}
