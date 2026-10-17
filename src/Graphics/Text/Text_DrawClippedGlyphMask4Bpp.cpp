struct FontGlyphMask { unsigned char prefix[4]; signed char width; unsigned char unused; short bitOffset; };
struct FontMaskArchive { unsigned char prefix[4]; unsigned short width; unsigned char unused[6]; unsigned char *bits; };
extern "C" FontMaskArchive *data_02107834[];
// Original: arm9/main @ 0x02045864; symbol: func_02045864; size: 0x154.
// Draws twelve rows of a font glyph bitmask into a clipped 4bpp pixel buffer.
// Proposed descriptive name: Text_DrawClippedGlyphMask4Bpp.
extern "C" void Text_DrawClippedGlyphMask4Bpp(short x, short y, FontGlyphMask *glyph, unsigned char *destination, int width, int height, unsigned char color, unsigned char fontIndex)
{
 // Preserve the original compiler's copy back to the height parameter home.
 height=height;
 if (glyph && destination) {
 int row; signed char bit; unsigned char *source; int column;
 int rowOffset;
 int rowStride;
 int outputStride;

 struct DrawLocals { FontMaskArchive *font; int offset; unsigned char highColor; unsigned char lowColor; int sourceStride; signed char firstBit; int destinationStride; } locals;
 locals.offset=glyph->bitOffset;
 locals.font=data_02107834[fontIndex];

 unsigned short fontWidth=locals.font->width;
 int startingBit=7-(locals.offset&7);
 int shiftedColor=color<<4;
 locals.highColor=(unsigned char)shiftedColor;
 locals.lowColor=color&15;
 locals.sourceStride=fontWidth>>3;
 locals.firstBit=(signed char)startingBit;
 locals.destinationStride=width>>1;

 for(row=0;row<12;row++) {
  // Initializing the bit cursor before address arithmetic preserves its lifetime.
  bit=locals.firstBit;
  rowOffset=(int)locals.font->bits;
  rowStride=locals.sourceStride;
  outputStride=locals.destinationStride;
  rowOffset+=rowStride*row;
  source=(unsigned char *)rowOffset+(locals.offset>>3);
  column=y+row;
  rowOffset=outputStride*column;
  if(column<0 || height<=column) continue;
  for(column=0;column<glyph->width;column++) {
   int destinationX=x+column;
   if(destinationX<0 || width<=destinationX) continue;
   if(*source & (1<<bit)) {
    if(destinationX&1) { unsigned char keep=(((unsigned char *)(destination+rowOffset))[destinationX>>1]&=15); (destination+rowOffset)[destinationX>>1]=keep|locals.highColor; }
    else { unsigned char keep=(((unsigned char *)(destination+rowOffset))[destinationX>>1]&=240); (destination+rowOffset)[destinationX>>1]=keep|locals.lowColor; }
   }
   bit--;
   if(bit<0) {bit=7;source++;}
  }
 }
 }
}
