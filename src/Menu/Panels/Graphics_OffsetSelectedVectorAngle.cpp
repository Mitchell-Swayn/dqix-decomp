#include <globaldefs.h>
ARM
struct Vector { union { struct { int x,y,z; }; int values[3]; }; };
struct Flags { unsigned char selected:1; unsigned char rest:7; };
extern "C" { void Graphics_WriteHalfwordRegister35CAndDisplayControl(int,int,int,unsigned short); void Object3D_ReadRotationVector(Vector*,void*); int _Z22fix32ReduceAngle0To2Pii(int); void CharacterPreview_SetBodyRotation(void*,Vector*); }
// Original: arm9/ov023 @ 0x021FCC68; symbol: func_ov023_021fcc68; size: 0x84.
extern "C" void Graphics_OffsetSelectedVectorAngle(unsigned char* object) {
 Graphics_WriteHalfwordRegister35CAndDisplayControl(0,0,0,0);
 int offset=((Flags*)(object+0x1864))->selected*0xc20;
 object+=0x20;
 Vector updated;
 Vector original;
 Object3D_ReadRotationVector(&original,object+offset);
 updated=original;
 updated.y+=0x199;
 updated.y=_Z22fix32ReduceAngle0To2Pii(updated.y);
 CharacterPreview_SetBodyRotation(object+offset,&updated);
}
