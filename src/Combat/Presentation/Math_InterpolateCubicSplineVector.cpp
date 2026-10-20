#include <globaldefs.h>
ARM
union SplineVector{struct {int x,y,z;};int elements[3];};
struct SplineMatrix{int v[4][4];};
extern "C" {
void Mat4x4_Multiply(const SplineMatrix*,const SplineMatrix*,SplineMatrix*);
extern SplineMatrix Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy5,Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy4,Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy3,Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy2,Math_InterpolateCubicSplineVector_CubicSplineBasisQ12,Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy6;
}
inline int SplineMultiply(int a,int b){return (int)(((long long)a*b+0x800)>>12);}
#define MUL(a,b) SplineMultiply(a,b)
#define ROW(m,r,p) m.v[r][0]=(p).x;m.v[r][1]=(p).y;m.v[r][2]=(p).z
#define EVALUATE(m) out.x=MUL(t3,m.v[0][0])+MUL(t2,m.v[1][0])+MUL(t,m.v[2][0])+m.v[3][0];out.y=MUL(t3,m.v[0][1])+MUL(t2,m.v[1][1])+MUL(t,m.v[2][1])+m.v[3][1];out.z=MUL(t3,m.v[0][2])+MUL(t2,m.v[1][2])+MUL(t,m.v[2][2])+m.v[3][2];out.x/=2;out.y/=2;out.z/=2
// Original: arm9/ov025 @ 0x021EE488; symbol: func_ov025_021ee488; size: 0x704.
extern "C" void Math_InterpolateCubicSplineVector(SplineVector* destination,SplineVector* points,int count,int t){
 int segment=(int)((float)t/4096.0f);
 t-=segment<<12;
 int t2=MUL(t,t);int t3=MUL(t2,t);
 SplineVector out;
 if(segment==0){
   SplineMatrix basis=Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy5;
   SplineMatrix control=Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy4;
   SplineMatrix transformed;
   ROW(control,1,points[segment]);ROW(control,2,points[segment+1]);ROW(control,3,points[segment+2]);
   Mat4x4_Multiply(&basis,&control,&transformed);
   EVALUATE(transformed);
 }else if(segment==count-2){
   SplineMatrix basis=Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy3;
   SplineMatrix control=Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy2;
   SplineMatrix transformed;
   ROW(control,0,points[segment-1]);ROW(control,1,points[segment]);ROW(control,2,points[segment+1]);
   Mat4x4_Multiply(&basis,&control,&transformed);
   EVALUATE(transformed);
 }else{
   SplineMatrix basis=Math_InterpolateCubicSplineVector_CubicSplineBasisQ12;
   SplineMatrix control=Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy6;
   SplineMatrix transformed;
   ROW(control,0,points[segment-1]);ROW(control,1,points[segment]);ROW(control,2,points[segment+1]);ROW(control,3,points[segment+2]);
   Mat4x4_Multiply(&basis,&control,&transformed);
   EVALUATE(transformed);
 }
 *destination=out;
}
