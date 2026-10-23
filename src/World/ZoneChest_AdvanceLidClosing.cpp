#include <globaldefs.h>
#include <World/Zone3DContainers.h>
#include <Graphics/Vector.h>
ARM
#pragma always_inline on
static inline int MultiplyFixed(int a,int b){return (int)(((long long)a*b+2048)>>12);}
// Original: arm9/main @0x02015CD0; symbol:func_02015cd0; size:0x224.
// Advances the closing lid trajectory or settles its angle toward the endpoint.
extern "C" bool ZoneChest_AdvanceLidClosing(ZoneChestEntry* self) {
 int closingDuration=0xbff4, settlingDuration=0x17fe8;
 if(self->unknown_18==0){
 unsigned timer=self->timer;
 if((float)timer<=(float)closingDuration/4096.f){
 int squared=(self->timer*self->timer)<<12;
 self->lidAngle=0x4800+MultiplyFixed(fix32_Divide(-2048,0x8fee0),squared);++self->timer;
 }else if((float)timer<=(float)settlingDuration/4096.f){
 int phase=(int)(4096.f*((float)timer-(float)closingDuration/4096.f));
 int decay=4096-fix32_Divide(phase,0x17fe8);
 int angle=MultiplyFixed(fix32_Divide(0xc90f,0x17fe8),phase);if(angle>0x647a)angle=0x647a;
 int displacement=MultiplyFixed(fix32sin(angle),257);
 self->lidAngle=0x4000+MultiplyFixed(displacement,decay);++self->timer;
 }else return true;
 }else if(self->unknown_18==1){
 // The settle path reads a signed halfword; the shared header exposes unsigned storage.
 if(!self->timer){short& angle=*(short*)&self->lidAngle;int change=MultiplyFixed(0x647a-angle,0x333);angle+=change;
 if(fix32abs(change)<4){self->lidAngle=0x647a;++self->timer;return true;}
 }else return true;
 }
 return false;
}
