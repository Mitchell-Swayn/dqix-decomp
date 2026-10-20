#include <globaldefs.h>
ARM
#include <System/Matrix.h>
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vector3fix*,int,Vector3fix*);
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(void*,int);
extern "C" bool _ZN8Object3D20DrawMeshWithMaterialEbiii(void*,bool,int,int,int);
inline bool IsPrimary(unsigned char v) { return v <= 3; }
struct DrawObject { char pad[0x44]; Vector3fix pos; };
// Original: arm9/ov025 @ 0x021DF864; symbol: func_ov025_021df864; size: 0x14C.
extern "C" void Graphics_DrawAlphaPositionSamples(unsigned char* p) {
 bool first = IsPrimary(p[0x174]);
 if(first) {
  for(int i=0;i<10;i++) {
   unsigned char* entry=p+0x176+i*2;
   if(entry[1]) {
    Vector3fix v;
    _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_((Vector3fix*)(p+0x158),entry[0]<<12,&v);
    Vector3fix_Add((Vector3fix*)(p+0x164),&v,&v);
    v.y=0x400;
    ((DrawObject*)p)->pos=v;
    _ZN8Object3D17SetInheritedAlphaEi(p,entry[1]);
    _ZN8Object3D20DrawMeshWithMaterialEbiii(p,true,0,0,1);
   }
  }
 } else {
  Vector3fix* dest=(Vector3fix*)(p+0xf0);
  for(int i=0;i<10;i++) {
   unsigned char* entry=p+0x176+i*2;
   if(entry[1]) {
    Vector3fix v;
    _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_((Vector3fix*)(p+0x158),entry[0]<<12,&v);
    Vector3fix_Add((Vector3fix*)(p+0x164),&v,&v);
    v.y=0x400;
    ((DrawObject*)(p+0xac))->pos=v;
    _ZN8Object3D17SetInheritedAlphaEi(p+0xac,entry[1]);
    _ZN8Object3D20DrawMeshWithMaterialEbiii(p+0xac,true,0,0,1);
   }
  }
 }
}
