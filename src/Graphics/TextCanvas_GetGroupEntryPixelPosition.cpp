#include <globaldefs.h>
struct Group {short* indices;char pad[6];short x,y;char pad2[5];unsigned char count;};struct Part {char pad[6];short x,y;};extern "C" Group* DisplayLayout_FindGroupById(void*,unsigned);extern "C" Part* DisplayLayout_FindPartById(void*,int);
// Original: arm9/main @ 0x020809C4; symbol: func_020809c4; size: 0xA8.
extern "C" void TextCanvas_GetGroupEntryPixelPosition(char* self,unsigned id,int wanted,short* x,short* y) {Group* group=DisplayLayout_FindGroupById(self+12,id);if(!group)return;*x=group->x<<3;*y=group->y<<3;for(unsigned char i=0;i<group->count;++i){if(wanted==group->indices[i]){Part* part=DisplayLayout_FindPartById(self+4,wanted);if(!part)return;*x+=part->x;*y+=part->y;return;}}}
