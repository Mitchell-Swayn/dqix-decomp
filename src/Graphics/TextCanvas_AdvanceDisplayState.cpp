#include <globaldefs.h>
ARM
// Map is the accepted FillSequentialCharacterTilemap owner layout.
struct Map {
 char reserved0[156];int revision;
 unsigned ignored:5;unsigned tile:16;unsigned reserved1:11;
 short reserved2[2],width,height;char reserved3[25];unsigned char flags;
 char reserved4[14];unsigned short* cells;
};
extern "C" void TextCanvas_FillSequentialCharacterTilemap(Map*);
extern "C" void TextCanvas_DrawPageNumberPair(void*,int);
// Original: arm9/main @ 0x0204C87C; symbol: func_0204c87c; size: 0x74.
extern "C" void TextCanvas_AdvanceDisplayState(void* object,unsigned unusedTick) {
 Map* self=(Map*)object;
 if(!(self->flags&1))return;
 switch(self->revision) {
  case 0:break;
  // The signed halfword in reserved3+20 is the display-height field at0xc0.
  case 1:*(short*)(self->reserved3+20)=self->height;++self->revision;TextCanvas_FillSequentialCharacterTilemap(self);break;
  case 2:TextCanvas_FillSequentialCharacterTilemap(self);break;
  case 3:break;
  case 4:self->revision=3;break;
 }
 TextCanvas_DrawPageNumberPair(self,1);
}
