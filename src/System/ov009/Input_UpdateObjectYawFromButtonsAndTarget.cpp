#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
extern "C" {
Vec CopyVectorAtOffset50(void*);
int _Z22fix32ReduceAngle0To2Pii(int);
void Ov023_InitializeFourEmbeddedFields(void*,int);
void func_ov023_021e6088(void*,Vec*);
int ReadSelectedCoordinatePair(void*,int*,int*);
int Input_TestKeyMask(unsigned short*,unsigned short);
extern unsigned char data_02114e54[];
extern unsigned short data_02114e30[];
}
// Original: arm9/ov009 @ 0x02188604; symbol: func_ov009_02188604; size: 0x340.
extern "C" void Input_UpdateObjectYawFromButtonsAndTarget(unsigned char* self,unsigned ticks) {
 if(*(unsigned*)(self+0xd9c)&8){
   int done=0;
   Vec rotation=CopyVectorAtOffset50(*(void**)(self+0x7f8));
   int angle;
   int current=rotation.y;
   int delta=_Z22fix32ReduceAngle0To2Pii(*(int*)(self+0x804)-current);
   if(delta>=0 && delta<0x3244){
     angle=current+delta/12;
     for(unsigned i=0;i<ticks-1;i++)angle+=_Z22fix32ReduceAngle0To2Pii(*(int*)(self+0x804)-angle)/12;
   } else if(delta>=0x3244 && delta<0x6488){
     angle=current-(0x6488-delta)/12;
     for(unsigned i=0;i<ticks-1;i++)angle-=(0x6488-_Z22fix32ReduceAngle0To2Pii(*(int*)(self+0x804)-angle))/12;
   }
   Ov023_InitializeFourEmbeddedFields(*(void**)(self+0x7f8),_Z22fix32ReduceAngle0To2Pii(angle));
   delta=_Z22fix32ReduceAngle0To2Pii(*(int*)(self+0x804)-angle);
   if((delta<0?-delta:delta)<40)done=1;
   else if(((0x6488-delta)<0?-(0x6488-delta):0x6488-delta)<40)done=1;
   if(done){
     Ov023_InitializeFourEmbeddedFields(*(void**)(self+0x7f8),_Z22fix32ReduceAngle0To2Pii(*(int*)(self+0x804)));
     *(int*)(self+0x804)=0;
     *(unsigned*)(self+0xd9c)&=~8;
   }
 }else if(*(unsigned*)(self+0xd9c)&1){
   int left=0,right=0,touch=0;
   int x,y;
   ReadSelectedCoordinatePair(data_02114e54,&x,&y);
   if(data_02114e54[0x55] || (data_02114e54[0x5f] && *(unsigned short*)(data_02114e54+0x24)) || data_02114e54[0x54]){
     touch=1;
     if(y>=169 && y<=177){if(x>=14 && x<=23)left=1;if(x>=59 && x<=68)right=1;}
   }
   if(!touch){if(Input_TestKeyMask(data_02114e30,0x200))left=1;if(Input_TestKeyMask(data_02114e30,0x100))right=1;}
   if(left && right){*(int*)(self+0x804)=0x1eb;*(unsigned*)(self+0xd9c)|=8;}
   else if(left || right){
     Vec rotation=CopyVectorAtOffset50(*(void**)(self+0x7f8));
     if(left)rotation.y+=(int)(4096.0f*(0.08f*(float)ticks));
     if(right)rotation.y-=(int)(4096.0f*(0.08f*(float)ticks));
     rotation.y=_Z22fix32ReduceAngle0To2Pii(rotation.y);
     func_ov023_021e6088(*(void**)(self+0x7f8),&rotation);
   }
 }
}
