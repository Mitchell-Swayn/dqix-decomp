#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
extern "C" {
Vec Object3D_ReadRotationVector(void*);
int _Z22fix32ReduceAngle0To2Pii(int);
void Ov023_InitializeFourEmbeddedFields(void*,int);
void CharacterPreview_SetBodyRotation(void*,Vec*);
int ReadSelectedCoordinatePair(void*,int*,int*);
int Input_TestKeyMask(unsigned short*,unsigned short);
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov009 @ 0x02188604; symbol: func_ov009_02188604; size: 0x340.
extern "C" void Input_UpdateObjectYawFromButtonsAndTarget(unsigned char* self,unsigned ticks) {
 if(*(unsigned*)(self+0xd9c)&8){
   int done=0;
   Vec rotation=Object3D_ReadRotationVector(*(void**)(self+0x7f8));
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
   ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
   if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55] || (Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] && *(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x24)) || Main_UnknownRoleZeroInitializedStorage_Variant4[0x54]){
     touch=1;
     if(y>=169 && y<=177){if(x>=14 && x<=23)left=1;if(x>=59 && x<=68)right=1;}
   }
   if(!touch){if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200))left=1;if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100))right=1;}
   if(left && right){*(int*)(self+0x804)=0x1eb;*(unsigned*)(self+0xd9c)|=8;}
   else if(left || right){
     Vec rotation=Object3D_ReadRotationVector(*(void**)(self+0x7f8));
     if(left)rotation.y+=(int)(4096.0f*(0.08f*(float)ticks));
     if(right)rotation.y-=(int)(4096.0f*(0.08f*(float)ticks));
     rotation.y=_Z22fix32ReduceAngle0To2Pii(rotation.y);
     CharacterPreview_SetBodyRotation(*(void**)(self+0x7f8),&rotation);
   }
 }
}
