#include <globaldefs.h>
#include <System/Matrix.h>
ARM
#pragma optimization_level 4
#pragma opt_common_subs off
// Original: arm9/main @ 0x020D74A4; symbol: func_020d74a4; size: 0x90.
extern "C" void Graphics_SetObjectSlotPositionOrTranslation(unsigned char* p,int index,Vector3fix position){
 int offset=index*216;
 if(!*(int*)(p+offset+0xac)){
 *(Vector3fix*)(p+offset+0x44)=position;
 }else{
 Matrix4x3 m;
 MTX_Identity43_(&m);
 Mat4x3_ApplyTranslation(&m,&m,position.x,position.y,position.z);
 Matrix4x3* source=&m;
 Matrix4x3* dest=(Matrix4x3*)(*(unsigned char**)(p+offset+4)+0xe8);
 *dest=*source;
 }
}
