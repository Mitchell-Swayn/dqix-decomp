struct PartyMenuState;
#include <globaldefs.h>
ARM
extern "C" void PartyMenu_BuildAvailableConnectionActions(char*,short*,short*);
// Original data: arm9/ov002 @ 0x216cb48; symbol: data_ov002_0216cb48.
// Menu grid layout by state ID; state 255 terminates the scan. SelectTableDrivenPanelLayout scans with a seven-byte stride and copies the unsigned dimensions, signed offsets and cell dimensions into the menu.
// Initial values: hex 010c080e060a0e030c0809080a10020c0a09040a0d040c0809080a0d050c0812100a0d060c04090a0a0d070c0809010a0d08070409040a0d090c0809010a0d0a ...; full span in module reference.
// Observed span: 318 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" unsigned char PartyMenuConfigurePanelLayout_MenuGridLayoutByStateID[];
struct LayoutEntry { unsigned char id,w,h; signed char x,y; unsigned char a,b; };
struct LayoutState { unsigned char prefix[0xa0]; short x,y,p,q,w,h,a,b; unsigned char pad[1],id,pad2[3],active,pad3,delay; };
// Original: arm9/ov002 @ 0x0215BE00; symbol: func_ov002_0215be00; size: 0x134.
// Selects a seven-byte layout record and applies special connection-count positioning.
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState* owner,int id,int p,int q) {
 char* self=(char*)owner;
 LayoutState* s; int delta; unsigned char* e;
 for(register int i=0; (e=PartyMenuConfigurePanelLayout_MenuGridLayoutByStateID+i*7, PartyMenuConfigurePanelLayout_MenuGridLayoutByStateID[i*7]!=255); ++i) {
  delta=e[0];
  if(delta==id) {
   s=(LayoutState*)(self+0xec8);
   s->id=delta; s->p=p; s->q=q; { int h=e[2],w=e[1]; s->w=w; s->h=h; } { int y=*(signed char*)(e+4),x=*(signed char*)(e+3); s->x=x; s->y=y; } { int b=e[6],a=e[5]; s->a=a; s->b=b; } s->active=1;
   if(e[0]==21) { short out[8],count; delta=0; PartyMenu_BuildAvailableConnectionActions(self,out,&count); if(count<8) delta=(short)((8-count)*2); else { int w=e[1]; int h=e[2]+1; s->w=w; s->h=h; } if(delta<0)delta=0; int x=*(signed char*)(e+3); int y=*(signed char*)(e+4)-delta; s->x=x; s->y=y; }
   if(e[0]==13 && *(int*)(self+0x1bb8)==11) {s->x=17;s->y=16;}
   unsigned char delay=10; if(id==38)delay=12; s->delay=delay; return;
  }
 }
}
