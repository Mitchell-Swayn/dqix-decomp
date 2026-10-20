#include <globaldefs.h>
ARM
struct State { char pad[0x34];unsigned char type,step;char pad2[0x33e];unsigned char flags;char pad3[15];int value;};
// Original: arm9/ov031 @ 0x02245548; symbol: func_ov031_02245548; size: 0x1A8.
extern "C" void Util_UpdateModeDependentFixedPointValue(State* p){
if(p->flags&1){switch(p->type){
case 2:if(p->value<0x3c000)p->value+=0x28;if(p->step==6)p->value=0x3c000;break;
case 3:if(p->value<0x46000)p->value+=0x51;if(p->step==6)p->value=0x46000;break;
case 4:if(p->value<0x77f33)p->value+=0xcc;if(p->step==5)p->value=0x78000;break;
}}
else if(p->flags&4){switch(p->type){
case 2:if(p->value<0x64000)p->value+=0x51;if(p->step==6)p->value=0x64000;break;
case 3:if(p->value<0x77f85)p->value+=0x7a;if(p->step==6)p->value=0x78000;break;
}}
else if(p->flags&2){switch(p->type){
case 2:if(p->value<0x3c000)p->value+=0x28;if(p->step==6)p->value=0x3c000;break;
case 3:if(p->value<0x46000)p->value+=0x51;if(p->step==6)p->value=0x46000;break;
case 5:if(p->value<0x77f33)p->value+=0xcc;if(p->step==5)p->value=0x78000;break;
}}
}
