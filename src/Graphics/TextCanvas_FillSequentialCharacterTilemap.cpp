#include <globaldefs.h>
struct Map {
 char reserved0[156];int revision;
 unsigned ignored:5;unsigned tile:16;unsigned reserved1:11;
 short reserved2[2],width,height;char reserved3[25];unsigned char flags;
 char reserved4[14];unsigned short* cells;
};
// Original: arm9/main @ 0x0204E998; symbol: func_0204e998; size: 0x90.
extern "C" ARM void TextCanvas_FillSequentialCharacterTilemap(Map* self){if(!(self->flags&1)||!self->cells)return;unsigned tile=self->tile;short y=0;short x;unsigned short* row=self->cells;for(;y<self->height;y++){for(x=0;x<self->width;x++){row[x]=tile;tile=(tile+1)&65535;}row+=self->width;}self->revision++;}
