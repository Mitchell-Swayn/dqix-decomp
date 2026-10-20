#include <globaldefs.h>
ARM
struct Offset50VectorWords {int x,y,z;};
extern "C" Offset50VectorWords Object3D_ReadRotationVector(char*);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" void Graphics_WriteHalfwordRegister35CAndDisplayControl(int,int,int,unsigned short);
extern "C" void CharacterPreview_SetBodyRotation(void*,const Offset50VectorWords*);
struct Selector {unsigned char bit:1;unsigned char rest:7;};
// Original: arm9/ov023 @ 0x021FCCEC; symbol: func_ov023_021fccec; size: 0x84.
extern "C" void CharacterPreview_RotateActiveModelLeft(char* p){

 Graphics_WriteHalfwordRegister35CAndDisplayControl(0,0,0,0);
 int offset=((Selector*)(p+0x1864))->bit*0xc20;
 p+=0x20;
 Offset50VectorWords angle=Object3D_ReadRotationVector(p+offset);
 angle.y+=-0x199;
 angle.y=_Z22fix32ReduceAngle0To2Pii(angle.y);
 CharacterPreview_SetBodyRotation(p+offset,&angle);
}
