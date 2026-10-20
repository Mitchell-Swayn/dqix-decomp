#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma opt_common_subs off
struct TilePart { unsigned char width,height,pad[2]; unsigned int attr; };
struct RectPart { unsigned int attr,unused; unsigned char x,y,width,height; };
// Original data: arm9/main @ 0x20ee958; symbol: data_020ee958.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 40400000000000c040200000004000c020400000008000c020200000000000802010000000400080200800000040004010200000008000801010000000000040 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" TilePart GraphicsSplitRectangleIntoParts_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020E1438; symbol: func_020e1438; size: 0x130.
extern "C" unsigned int Graphics_SplitRectangleIntoParts(RectPart* out,unsigned int capacity,unsigned int x,unsigned int y,unsigned int width,unsigned int height) {
 if (!capacity) return 0;
 unsigned int count=0,offset=0;
 while(offset<height) {
  TilePart* part=0;
  TilePart* p=GraphicsSplitRectangleIntoParts_UnknownRoleInitializedBytes;
  unsigned int i=0;
  unsigned int remaining=height-offset;
  for(;i<12;i++,p++) {
   if(p->width==width && p->height<=remaining) { part=p; break; }
  }
  if(part) {
   out[count].x=x;
   out[count].y=offset+y;
   out[count].width=part->width;
   out[count].height=part->height;
   out[count].attr=part->attr;
   count++;
   offset+=part->height;
  } else {
   unsigned int half=width>>1;
   unsigned int remain=height-offset;
   count+=Graphics_SplitRectangleIntoParts(out+count,capacity-count,x,offset,half,remain);
   count+=Graphics_SplitRectangleIntoParts(out+count,capacity-count,x+half,offset,half,remain);
   break;
  }
  if(count>=capacity) break;
 }
 return count;
}
