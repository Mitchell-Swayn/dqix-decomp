#include <globaldefs.h>
struct Fade { unsigned int a,b; unsigned int state; unsigned int c,d; int amount; };
// Original: arm9/main @ 0x0202F380; symbol: func_0202f380; size: 0x84.
extern "C" ARM void AdvanceFadeAmountByScaledStep(char* self,int step) {
 Fade* fade=*(Fade**)(self+0x440); if(!step)step=1; if(!fade)return;
 switch(fade->state) {
 case 0:break;
 case 1:fade->state=2;(*(Fade**)(self+0x440))->amount=0x1000;return;
 case 2:break;
 case 3:

 fade->amount-=step*0x199;
 if((*(Fade**)(self+0x440))->amount<=0) {(*(Fade**)(self+0x440))->state=0;(*(Fade**)(self+0x440))->amount=0;}
 break;
 default:break;
 }
}
