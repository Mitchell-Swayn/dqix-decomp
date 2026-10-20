#pragma opt_propagation off
#pragma thumb off
#pragma always_inline on
#include <Graphics/Vector.h>
struct VectorCopy { int words[3]; };
static inline void CopyVectorWords(Vector3fix* out,const Vector3fix* in) { *(VectorCopy*)out=*(const VectorCopy*)in; }
// Selects a triangle vertex or edge point by Voronoi-region tests; the interior retains p.
// Fixed-point products are rounded individually before their differences are taken.
// CopyVectorWords copies the three-word representation without the shared class assignment call.
// Original: arm9/main @ 0x02031D20; symbol: func_02031d20; size: 0x370.
extern "C" void Vector3fix_ClampPointToTriangleRegions(Vector3fix* out,const Vector3fix* p,const Vector3fix* a,const Vector3fix* b,const Vector3fix* c)
{
 Vector3fix ab,ac,ap;
 Vector3fix_Subtract(b,a,&ab);
 Vector3fix_Subtract(c,a,&ac);
 Vector3fix_Subtract(p,a,&ap);
 int d1=Vector3fix_InnerProduct(&ab,&ap);
 int d2=Vector3fix_InnerProduct(&ac,&ap);
 if(d1<=0 && d2<=0){CopyVectorWords(out,a);return;}
 Vector3fix bp;
 Vector3fix_Subtract(p,b,&bp);
 int d3=Vector3fix_InnerProduct(&ab,&bp);
 int d4=Vector3fix_InnerProduct(&ac,&bp);
 if(d3>=0 && d4<=d3){CopyVectorWords(out,b);return;}
 int vc1=FIX32_MULTIPLY(d3,d2);
 int vc2=FIX32_MULTIPLY(d1,d4);
 int vc=vc2-vc1;
 if(vc<=0 && d1>=0 && d3<=0){
  int v=fix32_Divide(d1,d1-d3);
  Vector3fix result;
  Vector3fixMultiplyScalar(&ab,v,&result);
  Vector3fix_Add(a,&result,&result);
  CopyVectorWords(out,&result);return;
 }
 Vector3fix cp;
 Vector3fix_Subtract(p,c,&cp);
 int d5=Vector3fix_InnerProduct(&ab,&cp);
 int d6=Vector3fix_InnerProduct(&ac,&cp);
 if(d6>=0 && d5<=d6){CopyVectorWords(out,c);return;}
 int vb1=FIX32_MULTIPLY(d1,d6);
 int vb2=FIX32_MULTIPLY(d5,d2);
 int vb=vb2-vb1;
 if(vb<=0 && d2>=0 && d6<=0){
  int w=fix32_Divide(d2,d2-d6);
  Vector3fix result;
  Vector3fixMultiplyScalar(&ac,w,&result);
  Vector3fix_Add(a,&result,&result);
  CopyVectorWords(out,&result);return;
 }
 int va1=FIX32_MULTIPLY(d5,d4);
 int va2=FIX32_MULTIPLY(d3,d6);
 int va=va2-va1;
 if(va<=0 && d4-d3>=0 && d5-d6>=0){
  int w=fix32_Divide(d4-d3,(d4-d3)+(d5-d6));
  Vector3fix result;
  Vector3fix_Subtract(c,b,&result);
  Vector3fixMultiplyScalar(&result,w,&result);
  Vector3fix_Add(b,&result,&result);
  CopyVectorWords(out,&result);return;
 }
 CopyVectorWords(out,p);
}
