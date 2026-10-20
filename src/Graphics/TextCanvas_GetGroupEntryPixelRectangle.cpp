#include <globaldefs.h>
ARM
extern "C" char* DisplayLayout_FindGroupById(void*);extern "C" char* DisplayLayout_FindPartById(void*,int);
// Original: arm9/main @ 0x02080A6C; symbol: func_02080a6c; size: 0xC0.
extern "C" void TextCanvas_GetGroupEntryPixelRectangle(char* p,int unused,int id,short* x,short* y,short* a,short* b){char* table=DisplayLayout_FindGroupById(p+12);if(!table)return;*x=*(short*)(table+10)<<3;*y=*(short*)(table+12)<<3;for(unsigned char i=0;i<(unsigned char)table[19];++i){int key=(*(short**)table)[i];if(id==key){char* e=DisplayLayout_FindPartById(p+4,id);if(!e)return;*x+=*(short*)(e+6);*y+=*(short*)(e+8);*a=*(short*)(e+10);*b=*(short*)(e+12);return;}}}
