#include <globaldefs.h>
#pragma optimization_level 2
#pragma optimize_for_size on
#include "Graphics/AlphaTween.h"
extern "C" void* memset(void*,int,unsigned);extern "C" void CombatantMotion_ClearSidestepState(void*);struct Vector{unsigned x,y,z;};struct State{unsigned a;Vector b,c;unsigned char ids[4];unsigned word;char pad[0x1c];Vector d;unsigned char mode;char pad1;unsigned char unknown[8],enabled,pad2;char array[6],pad3[2];AlphaTween tween;unsigned tail;unsigned char id;};struct Object{char pad[0x13c];State* state;};
// Original: arm9/main @ 0x02049C88; symbol: func_02049c88; size: 0xE4.
extern "C" ARM void InitializeLinkedStateBufferVectorsAndIDSentinels(Object* p,State* s){p->state=s;if(!p->state)return;memset(p->state,0,0x70);p->state->a=0;{Vector* v=&p->state->b;v->x=0;v->y=0;v->z=0;}{Vector* v=&p->state->c;v->x=0;v->y=0;v->z=0;}{Vector* v=&p->state->d;v->x=0;v->y=0;v->z=0;}p->state->word=0;p->state->mode=0;p->state->ids[0]=255;p->state->ids[1]=255;p->state->ids[2]=255;p->state->ids[3]=255;p->state->enabled=1;CombatantMotion_ClearSidestepState(p->state->unknown);p->state->tween.Reset();memset(p->state->array,0,6);p->state->tail=0;p->state->id=255;}
