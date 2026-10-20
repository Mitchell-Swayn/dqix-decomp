#include <globaldefs.h>
ARM
extern "C" int Util_ReadLinkedBufferByte(...);
extern "C" int Http_LocateHeaderBufferCursor(...);
extern "C" int Util_ReadLinkedBufferByte(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x022404E8; symbol: FindNextCarriageReturnLineFeedAndFirstColon.
extern "C" int Http_FindHeaderLineEndAndColon(void* buffer,int start,int end,int* colon){
bool carriage=false;if(colon)*colon=-1;if(start<end){void* block;int offset;Http_LocateHeaderBufferCursor(buffer,start,&block,&offset);while(start<end){int value=Util_ReadLinkedBufferByte(buffer,&block,&offset);if(value==58&&colon&&*colon<0)*colon=start;if(!carriage){if(value==13)carriage=1;}else{if(value==10)return start==end-1?0:start+1;carriage=0;}start++;}}return -1;
}
