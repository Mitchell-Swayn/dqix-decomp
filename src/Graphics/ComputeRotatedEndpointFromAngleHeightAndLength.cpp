#include <globaldefs.h>
#pragma opt_lifetimes off
#pragma opt_propagation off
#include <Graphics/Vector.h>
ARM
// Original: arm9/main @ 0x0202E5D8; symbol: func_0202e5d8; size: 0xBC.
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char* self,int angle,int y,int length) {
 int rotation=fix32ReduceAngle0To2Pi(angle);
 int yy=(int)(((long long)y*y+0x800)>>12);
 *(int*)(self+0x70)=rotation;*(int*)(self+0x74)=y;*(int*)(self+0x78)=length;
 int ll=(int)(((long long)length*length+0x800)>>12);
 Vector3fix offset;
 offset.x=0;offset.y=y;offset.z=fix32_Sqrt(ll-yy);
 Matrix4x3 second=RotationMatrixY(rotation);
 Mat4x3_ApplyToVector(&offset,&second,&offset);
 Vector3fix_Add((Vector3fix*)(self+0x10),&offset,(Vector3fix*)(self+4));
}
