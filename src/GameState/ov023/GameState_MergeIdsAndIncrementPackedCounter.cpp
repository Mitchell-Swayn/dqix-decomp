#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" void AddToLowCounterAtOffset10SaturatingAt500(unsigned char*,unsigned);
extern "C" int GameState_MergePositiveIdsIntoBitset(unsigned*,const short*,int);
extern "C" int GameState_CopySixtyByteFieldAtOffset7504(void*);
extern "C" int GameState_Copy176BytesAtOffset7540(const void*);
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void*);
struct Buffer {unsigned char pad[16];unsigned counter:9;unsigned rest:23;unsigned char pad2[156];};
// Original: arm9/ov023 @ 0x021ED724; symbol: func_ov023_021ed724; size: 0xBC.
extern "C" int GameState_MergeIdsAndIncrementPackedCounter(void* owner,const short* source,int count){
 short ids[50];Buffer buffer;unsigned bits[15];
 if(!owner)return 0;if(!source)return 0;if(!count)return 0;
 int result=0;
 GameState_CopySixtyByteFieldAtOffset7504(bits);
 memset(ids,0,100);
 for(int i=0;i<count;i++)ids[i]=source[i];
 GameState_MergePositiveIdsIntoBitset(bits,ids,count);
 GameState_CopyB0ByteStateBufferToOutput(&buffer);
 if(!buffer.counter)result|=1;
 AddToLowCounterAtOffset10SaturatingAt500((unsigned char*)&buffer,count);
 GameState_Copy176BytesAtOffset7540(&buffer);
 return result;
}
