struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
struct Owner; struct Record;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void Graphics_PositionAndSubmitSpriteCell(int,int,void*,unsigned,unsigned char,unsigned char);
extern "C" void SetFourHalfwordArrayElementsForBoundedIndex(char*,int,short,short,short,short);
// Original data: arm9/ov002 @ 0x216c98a; symbol: data_ov002_0216c98a.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0800280048006800.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" short GraphicsUpdateFourByFourSelectionGrid_UnknownRoleInitializedBytes[];
// Original: arm9/ov002 @ 0x0215AD70; symbol: func_ov002_0215ad70; size: 0x1F4.
// Places sixteen grid records, highlights the selected cell, and updates the adjacent record.
extern "C" void Graphics_UpdateFourByFourSelectionGrid(char* self) {
 char* record; short cell; int py; short x;
 record=(char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(self+0xec8)),28);
 if(record) {
  short baseX=(short)(*(short*)(record+0xac)*8),baseY=(short)(*(short*)(record+0xae)*8);
  struct Four {short v[4];}; Four offsets=*(Four*)GraphicsUpdateFourByFourSelectionGrid_UnknownRoleInitializedBytes;
  unsigned char ordinal=0; unsigned short index=22;
  for(unsigned char row=0;row<4;row++) {
   for(unsigned char col=0;col<4;col++) {
    x=offsets.v[col]; short y=offsets.v[row];
    short px=x+baseX; py=(short)(y+baseY);
    Graphics_PositionAndSubmitSpriteCell(px,py,*(void**)(self+0x1a68),index++,(unsigned char)(12+ordinal*4),255);
    cell=(short)(col+row*4);
    if(*(short*)(self+0x1c06)==cell)Graphics_PositionAndSubmitSpriteCell(px,py,*(void**)(self+0x1a68),17,8,255);
    SetFourHalfwordArrayElementsForBoundedIndex(record,cell,x,y,24,24);
    ordinal++;
   }
  }
  record=(char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(self+0xec8)),29);
  if(record) {
   short x=*(short*)(record+0xac),y=*(short*)(record+0xae);
   x*=8; y*=8;
   Graphics_PositionAndSubmitSpriteCell(x+16,y+24,*(void**)(self+0x1a68),20,84,8);
  }
 }
}
