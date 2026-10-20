#include <globaldefs.h>
ARM
extern "C" double Runtime_ComputeDoubleAbsoluteValue(double);
extern "C" int Math_ReduceChunkedDoubleAngleByHalfPi(double*,double*,int,int,int,const int*);
// Original data: arm9/main @ 0x20e6aec; symbol: data_020e6aec.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex fb21f93ffb2109407cd91240fb2119407a6a1f407cd92240bbfd2540fb2129403a462c407a6a2f405c4731407cd932409c6b3440bbfd3540db8f3740fb213940 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e6b6c; symbol: data_020e6b6c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 83f9a200444e6e00fc291500d1572700dd34f50062dbc0003c999500419043006351fe00bbdeab00b761c5003a6e2400d24d42004906e00009ea2e001c92d100 ...; full span in module reference.
// Observed span: 264 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int MathReduceDoubleAngleByHalfPi_UnknownRoleInitializedBytes[],MathReduceDoubleAngleByHalfPi_UnknownRoleInitializedBytes_Variant2[];
#define HI(x) (((int*)&(x))[1])
#define LO(x) (((unsigned*)&(x))[0])
// Original: arm9/main @ 0x02007028; symbol: Math_ReduceDoubleAngleByHalfPi; size: 0x6c8.
// Reduces a double angle by multiples of pi/2 into a two-double remainder.
extern "C" int Math_ReduceDoubleAngleByHalfPi(double x,double* y) {
 const double zero=0.0,half=0.5,two24=1.67772160000000000000e+07;
 const double invpio2=6.36619772367581382433e-01,pio2_1=1.57079632673412561417e+00,pio2_1t=6.07710050650619224932e-11,pio2_2=6.07710050630396597660e-11,pio2_2t=2.02226624879595063154e-21,pio2_3=2.02226624871116645580e-21,pio2_3t=8.47842766036889956997e-32;
 double z,w,t,r,fn,tx[3];int e0,i,j,nx,n,ix,hx;
 hx=HI(x);ix=hx&0x7fffffff;
 if(ix<=0x3fe921fb){y[0]=x;y[1]=0;return 0;}
 if(ix<0x4002d97c){
  if(hx>0){z=x-pio2_1;if(ix!=0x3ff921fb){y[0]=z-pio2_1t;y[1]=(z-y[0])-pio2_1t;}else {z-=pio2_2;y[0]=z-pio2_2t;y[1]=(z-y[0])-pio2_2t;}return 1;}
  else {z=x+pio2_1;if(ix!=0x3ff921fb){y[0]=z+pio2_1t;y[1]=(z-y[0])+pio2_1t;}else {z+=pio2_2;y[0]=z+pio2_2t;y[1]=(z-y[0])+pio2_2t;}return -1;}
 }
 if(ix<=0x413921fb){
  t=Runtime_ComputeDoubleAbsoluteValue(x);n=(int)(t*invpio2+half);fn=(double)n;r=t-fn*pio2_1;w=fn*pio2_1t;
  if(n<32&&ix!=MathReduceDoubleAngleByHalfPi_UnknownRoleInitializedBytes[n-1]) y[0]=r-w;
  else {j=ix>>20;y[0]=r-w;i=j-((HI(y[0])>>20)&0x7ff);if(i>16){t=r;w=fn*pio2_2;r=t-w;w=fn*pio2_2t-((t-r)-w);y[0]=r-w;i=j-((HI(y[0])>>20)&0x7ff);if(i>49){t=r;w=fn*pio2_3;r=t-w;w=fn*pio2_3t-((t-r)-w);y[0]=r-w;}}}
  y[1]=(r-y[0])-w;if(hx<0){y[0]=zero-y[0];y[1]=zero-y[1];return -n;}return n;
 }
 if(ix>=0x7ff00000){y[0]=y[1]=x-x;return 0;}
 LO(z)=LO(x);e0=(ix>>20)-1046;HI(z)=ix-(e0<<20);
 for(i=0;i<2;i++){tx[i]=(double)(int)z;z=(z-tx[i])*two24;}
 tx[2]=z;nx=3;while(tx[nx-1]==zero)--nx;
 n=Math_ReduceChunkedDoubleAngleByHalfPi(tx,y,e0,nx,2,MathReduceDoubleAngleByHalfPi_UnknownRoleInitializedBytes_Variant2);
 if(hx<0){y[0]=zero-y[0];y[1]=zero-y[1];return -n;}return n;
}
