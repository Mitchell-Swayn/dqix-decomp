#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Input_TestKeyMask(unsigned short*,unsigned short);
extern "C" const Matrix4x3* _ZN12RenderConfig20GetInverseViewMatrixEv();
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void __clear(void*,unsigned);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vector3fix*,int,Vector3fix*);
struct Triple{int x,y,z;};
extern "C" void Graphics_TranslateObjectPositionVariants(void*,Triple);
extern "C" void World_AddYawToModeSelectedVectors(void*,int);
extern "C" unsigned short data_02114e30[];
// Original: arm9/ov015 @ 0x02191874; symbol: func_ov015_02191874; size: 0x170.
extern "C" void Graphics_ApplyInputToSelectedObjectTransform(char* self){
 if(*(void**)(self+0x34)){
 _ZN9GameState11GetInstanceEv();
 Vector3fix delta;__clear(&delta,12);
 if(Input_TestKeyMask(data_02114e30,0x40))delta.z=-409;
 if(Input_TestKeyMask(data_02114e30,0x80))delta.z=409;
 if(Input_TestKeyMask(data_02114e30,0x10))delta.x=409;
 if(Input_TestKeyMask(data_02114e30,0x20))delta.x=-409;
 Matrix3x3 view;
 memcpy(&view,_ZN12RenderConfig20GetInverseViewMatrixEv(),36);
 Mat3x3_ApplyToVector(&delta,&view,&delta);
 delta.y=0;
 Vector3fix_Normalize(&delta,&delta);
 _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&delta,409,&delta);
 if(Input_TestKeyMask(data_02114e30,0x400))delta.y+=409;
 if(Input_TestKeyMask(data_02114e30,0x800))delta.y-=409;
 Graphics_TranslateObjectPositionVariants(*(void**)(self+0x34),*(Triple*)&delta);
 if(Input_TestKeyMask(data_02114e30,0x200))World_AddYawToModeSelectedVectors(*(void**)(self+0x34),409);
 if(Input_TestKeyMask(data_02114e30,0x100))World_AddYawToModeSelectedVectors(*(void**)(self+0x34),-409);
 }
}
