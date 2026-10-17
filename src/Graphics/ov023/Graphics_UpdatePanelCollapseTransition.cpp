#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" float _fsub(float,float);
struct Panel { char pad[0x33]; unsigned char state; char pad34[4]; unsigned short flags; short amount; unsigned char elapsed,kind; short rows,x,y,width,height; };
struct Kind { unsigned other:30,kind:2; char pad[0x240]; };
inline void RecomputeRows(Panel* p) {p->rows=(p->amount-p->y*8-65)/8+2; if(p->rows<=0)p->rows=0;}
// Original: arm9/ov023 @ 0x021ECBE8; symbol: func_ov023_021ecbe8; size: 0x214.
extern "C" void Graphics_UpdatePanelCollapseTransition(char* self) {
 if(!(((Panel*)(self+0x400))->flags&0x40)) return;
 unsigned char state=((Panel*)(self+0x400))->state;
 if(state==0) {
 unsigned kind=(*(Kind**)(self+0x20))[*(unsigned char*)(self+0x28)].kind;
 switch(kind) {
 case 0:
 ((Panel*)(self+0x400))->kind=0;
 ((Panel*)(self+0x400))->x=3;((Panel*)(self+0x400))->y=3;((Panel*)(self+0x400))->width=26;((Panel*)(self+0x400))->height=7;
 break;
 case 1:
 ((Panel*)(self+0x400))->kind=1;
 ((Panel*)(self+0x400))->x=3;((Panel*)(self+0x400))->y=3;((Panel*)(self+0x400))->width=26;((Panel*)(self+0x400))->height=7;
 break;
 case 2:
 ((Panel*)(self+0x400))->kind=2;
 ((Panel*)(self+0x400))->x=0;((Panel*)(self+0x400))->y=1;((Panel*)(self+0x400))->width=32;((Panel*)(self+0x400))->height=11;
 break;
 }
 ((Panel*)(self+0x400))->amount=96;
 RecomputeRows((Panel*)(self+0x400));
 ((Panel*)(self+0x400))->state++;
 }
 if(state==1) {
 ((Panel*)(self+0x400))->elapsed+=_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
 float fraction=(float)((Panel*)(self+0x400))->elapsed/60.0f;
 float one=1.0f;
 float value=(float)((Panel*)(self+0x400))->amount;
 value*=_fsub(fraction,one);
 value*=_fsub(fraction,one);
 ((Panel*)(self+0x400))->amount=(int)value;
 RecomputeRows((Panel*)(self+0x400));
 if(*(short*)(self+0x43a)<1) {
 *(short*)(self+0x43a)=0;
 *(unsigned char*)(self+0x433)+=1;
 }
 }
 if(state==2) {
 *(unsigned short*)(self+0x438)&=~0x40;
 *(unsigned char*)(self+0x433)=0;
 }
}
