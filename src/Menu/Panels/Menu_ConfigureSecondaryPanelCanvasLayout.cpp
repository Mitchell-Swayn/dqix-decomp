#include <globaldefs.h>
ARM
#pragma always_inline on
struct Entry { unsigned char id,a,b; signed char x,y; unsigned char c,d; };
// Original data: arm9/ov023 @ 0x21fd7fc; symbol: data_ov023_021fd7fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0004071c030a0d0104071c060a0d0204071c030a0d0b060a1a0e0a150c0f0820080c130d080820080c130e060601030a010f060601030a0110020202020101ff ...; full span in module reference.
// Observed span: 72 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Entry MenuConfigureSecondaryPanelCanvasLayout_UnknownRoleInitializedBytes[];
inline void SetPair(short* out,int a,int b) { out[0]=a; out[1]=b; }
// Original: arm9/ov023 @ 0x021E7CEC; symbol: func_ov023_021e7cec; size: 0xA0.
extern "C" void Menu_ConfigureSecondaryPanelCanvasLayout(unsigned char* self,int id,int x,int y) {
 for(int i=0;MenuConfigureSecondaryPanelCanvasLayout_UnknownRoleInitializedBytes[i].id!=255;i++) {
  Entry* entry=&MenuConfigureSecondaryPanelCanvasLayout_UnknownRoleInitializedBytes[i];
  if(entry->id==id) {
   self[0x129]=entry->id;
   *(short*)(self+0x11c)=x;
   *(short*)(self+0x11e)=y;
   SetPair((short*)(self+0x120),entry->a,entry->b);
   SetPair((short*)(self+0x118),entry->x,entry->y);
   SetPair((short*)(self+0x124),entry->c,entry->d);
   self[0x12d]=0;
   self[0x12e]=0;
   if(entry->id==16) { self[0x12d]=1; self[0x12e]=1; }
   return;
  }
 }
}
