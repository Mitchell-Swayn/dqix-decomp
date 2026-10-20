#include <globaldefs.h>
ARM
extern "C" unsigned char* DisplayLayout_FindGroupById(void*,int);extern "C" unsigned char* DisplayLayout_FindPartById(void*,int);
// Original: arm9/main @ 0x020804FC; symbol: func_020804fc; size: 0x5C.
extern "C" void TextCanvas_ClearGroupEntrySelection(unsigned char* p,int key){unsigned char* q=DisplayLayout_FindGroupById(p+12,key);if(!q)return;for(unsigned char i=0;i<q[19];++i){short id=(*(short**)q)[i];unsigned char* entry=DisplayLayout_FindPartById(p+4,id);if(entry)entry[42]&=~4;}}
