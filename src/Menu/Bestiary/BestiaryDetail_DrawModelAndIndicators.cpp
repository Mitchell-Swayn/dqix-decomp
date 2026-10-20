#include <globaldefs.h>
ARM
extern "C" void Object_ConvertMappedKeyToTwoHalfwords(void*,int,short*,short*);
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
extern "C" void _ZN8Object3D4DrawEb(void*,bool);
// Original data: arm9/ov014 @ 0x2189478; symbol: data_ov014_02189478.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1a001b0014000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern "C" short BestiaryDetailDrawModelAndIndicators_UnknownRoleInitializedBytes[];
// Original data: arm9/ov014 @ 0x218948c; symbol: data_ov014_0218948c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern "C" short BestiaryDetailDrawModelAndIndicators_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov014 @ 0x218948e; symbol: data_ov014_0218948e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000100010001000100.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern "C" short BestiaryDetailDrawModelAndIndicators_UnknownRoleInitializedBytes_Variant3[];
// Original: arm9/ov014 @ 0x02184A64; symbol: func_ov014_02184a64; size: 0x1A4.
// Updates three mapped record positions when linked flags permit, then draws the linked object.
extern "C" void BestiaryDetail_DrawModelAndIndicators(unsigned char* p) {
 if (!p[0x7c]) return;
 unsigned char* a=*(unsigned char**)(p+0x48);
 unsigned* b;
 if (!a || !(b=*(unsigned**)(p+0x50))) return;
 unsigned enabled=((unsigned)a[0x13]<<30)>>31;
 if (!enabled) return;
 int first=0, last=0;
 if (p[0x81]&0x20) {
  a=*(unsigned char**)(p+0x4c);
  if (a && (((unsigned)a[0x13]<<30)>>31)) first=1;
  b=*(unsigned**)(p+0x54);
  if (b && ((*b<<21)>>31)) last=1;
 } else {
  if(enabled) first=1;
  if((*b<<21)>>31) last=1;
 }
 if(first || last) {
  for(int i=0;i<3;i++) {
   short x=0,y=0;
   int active=i==2?last:first;
   if(active) {
    Object_ConvertMappedKeyToTwoHalfwords(*(void**)(p+0x58),BestiaryDetailDrawModelAndIndicators_UnknownRoleInitializedBytes[i],&x,&y);
    if((p+i)[0x90]) { x+=BestiaryDetailDrawModelAndIndicators_UnknownRoleInitializedBytes_Variant2[i*2]; y+=BestiaryDetailDrawModelAndIndicators_UnknownRoleInitializedBytes_Variant3[i*2]; }
    unsigned char* record=*(unsigned char**)(p+8)+i*0x28;
    *(int*)(record+0x14)=x<<12;
    *(int*)(record+0x18)=y<<12;
    if(p[0x94]) Graphics_SubmitTransformedCellToOam(*(void**)(p+4),*(unsigned char**)(p+8)+i*0x28);
   }
  }
 }
 if((p[0x81]&4) && *(void**)(p+0x40)) _ZN8Object3D4DrawEb(*(void**)(p+0x40),true);
}
