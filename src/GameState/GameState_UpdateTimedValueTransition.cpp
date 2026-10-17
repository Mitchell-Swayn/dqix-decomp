#include <globaldefs.h>
ARM
extern "C" unsigned long long _Z19GetCurrentTimestampv();
struct Fade { unsigned char state,request,paused,pad; unsigned short duration,pad6; unsigned long long start; float value; };
// Original: arm9/main @ 0x0201FA2C; symbol: func_0201fa2c; size: 0x180.
extern "C" void GameState_UpdateTimedValueTransition(Fade* p,unsigned elapsed) {
 if(p->state==1) {
 if(p->request==3) {p->state=3; p->request=0;}
 else {p->value=176.0f; p->request=0;}
 } else if(p->state==2) {
 if(p->paused) return;
 if(p->duration) {
 if(((_Z19GetCurrentTimestampv()-p->start)<<6)/0x82ea >= (int)p->duration) p->request=4;
 }
 if(p->request==4) {p->state=4;p->request=4;p->duration=0;}
 p->value=136.0f;
 } else if(p->state==3) {
 p->value -= 6.0f*((float)elapsed/33.333332f);
 if(p->value<136.0f) {p->value=136.0f;p->state=2;}
 } else if(p->state==4) {
 p->value += 6.0f*((float)elapsed/33.333332f);
 if(176.0f<p->value) {p->value=176.0f;p->state=1;}
 }
}
