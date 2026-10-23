#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
// Match the existing linked-buffer reader's nominal object views.
struct Block {Block* next;char bytes[512];};
struct Buffer {char pad[28];Block* next;char bytes[1024];};
extern "C" void Http_LocateHeaderBufferCursor(void*,int,void**,int*);
extern "C" int Util_ReadLinkedBufferByte(Buffer*,Block**,int*);
// Original: arm9/ov031 @ 0x022405B8; symbol: func_ov031_022405b8; size: 0x70.
extern "C" int Http_SkipHeaderValueSpaces(void* root,int start,int end) {
 if(start<end) {
  Block* block;int offset;
  Http_LocateHeaderBufferCursor(root,start,(void**)&block,&offset);
  while(start<end) {
   if(Util_ReadLinkedBufferByte((Buffer*)root,&block,&offset)!=32)return start;
   ++start;
  }
 }
 return -1;
}
