#include <globaldefs.h>
ARM
extern "C" {char* SpriteAnimation_FindTrackByKey(void*,unsigned);void Graphics_SubmitTransformedCellToOam(void*,void*);}
// Original: arm9/main @ 0x0205ADDC; symbol: func_main_0205addc; size: 0xb0.
// Looks up flagged key record, applies fixed-point position and optional part to bounded entry.
extern "C" void SpriteAnimation_SubmitTrackFrame(char* self,unsigned key){if(!*(void**)(self+0x3c))return;char* record=SpriteAnimation_FindTrackByKey(*(void**)(self+0x3c),key);if(!record)return;char* again=SpriteAnimation_FindTrackByKey(*(void**)(self+0x3c),key);int enabled;if(again)enabled=((unsigned char)again[21]&8)?1:0;else enabled=0;if(!enabled)return;unsigned index=*(unsigned short*)(*(char**)(record+12)+4**(unsigned short*)(record+16)+2);if(index>=*(unsigned short*)(self+0x4c))return;char* entry=*(char**)(self+0x40)+40*index;int x=*(short*)(record+4),y=*(short*)(record+6);*(int*)(entry+20)=x<<12;*(int*)(entry+24)=y<<12;unsigned part=(unsigned char)record[20];if(part!=255)entry[34]=part;Graphics_SubmitTransformedCellToOam(self,entry);}
