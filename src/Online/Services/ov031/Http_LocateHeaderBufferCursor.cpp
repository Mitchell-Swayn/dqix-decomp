#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02240410; symbol: Http_LocateHeaderBufferCursor; size: 0x5C.
// Resolves a byte position into a linked512-byte block and local offset.
extern "C" void Http_LocateHeaderBufferCursor(void* root,int value,void** nodeOut,int* offsetOut) {
 if(value<0x400){*nodeOut=0;*offsetOut=value;return;}
 int page=(value-0x400)>>9;
 int remaining=page-1;
 void* node=*(void**)((char*)root+0x1c);
 if(page!=0)do {node=*(void**)node;}while(remaining--!=0);
 *nodeOut=node;
 *offsetOut=(value-0x400)&0x1ff;
}
