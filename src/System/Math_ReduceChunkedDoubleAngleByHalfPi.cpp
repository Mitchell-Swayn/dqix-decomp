#include <globaldefs.h>
ARM
extern "C" double Runtime_ScaleNormalizedDoubleByPowerOfTwo(double,int);
extern "C" double Runtime_CeilDouble(double);
// Original data: arm9/main @ 0x20e6c74; symbol: data_020e6c74.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 02000000030000000400000006000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int MathReduceChunkedDoubleAngleByHalfPi_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x20e6c84; symbol: data_020e6c84.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000040fb21f93f000000002d44743e000000809846f83c0000006051cc783b00000080831bf0390000004020257a38000000802282e336000000001df36935.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" double MathReduceChunkedDoubleAngleByHalfPi_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/main @ 0x02007A10; symbol: Math_ReduceChunkedDoubleAngleByHalfPi.
extern "C" int Math_ReduceChunkedDoubleAngleByHalfPi(double*x,double*y,int e0,int nx,int prec,int*ipio2){
int jz,jx,jv,jp,jk,carry,n,iq[20],i,j,k,m,q0,ih; double z,fw,f[20],fq[20],q[20];
jk=MathReduceChunkedDoubleAngleByHalfPi_UnknownRoleInitializedBytes[prec];jp=jk;jx=nx-1;jv=(e0-3)/24;if(jv<0)jv=0;q0=e0-24*(jv+1);j=jv-jx;m=jx+jk;
i=0;if(m>=0)for(;i<=m;i++,j++)f[i]=j<0?0.0:(double)ipio2[j];
for(i=0;i<=jk;i++){for(j=0,fw=0.0;j<=jx;j++)fw+=x[j]*f[jx+i-j];q[i]=fw;}
jz=jk;
recompute:
i=0;j=jz;z=q[jz];if(jz>0)for(;j>0;i++,j--){fw=(double)(int)(0.000000059604644775390625*z);iq[i]=(int)(z-16777216.0*fw);z=q[j-1]+fw;}
z=Runtime_ScaleNormalizedDoubleByPowerOfTwo(z,q0);z-=8.0*Runtime_CeilDouble(z*0.125);n=(int)z;z-=(double)n;ih=0;
if(q0>0){i=iq[jz-1]>>(24-q0);n+=i;iq[jz-1]-=i<<(24-q0);ih=iq[jz-1]>>(23-q0);}else if(q0==0)ih=iq[jz-1]>>23;else if(z>=0.5)ih=2;
if(ih>0){n+=1;carry=0;for(i=0;i<jz;i++){j=iq[i];if(carry==0){if(j!=0){carry=1;iq[i]=0x1000000-j;}}else iq[i]=0xffffff-j;}
if(q0>0){switch(q0){case 1:iq[jz-1]&=0x7fffff;break;case 2:iq[jz-1]&=0x3fffff;break;}}
if(ih==2){z=1.0-z;if(carry!=0)z-=Runtime_ScaleNormalizedDoubleByPowerOfTwo(1.0,q0);}}
if(z==0.0){j=0;for(i=jz-1;i>=jk;i--)j|=iq[i];if(j==0){for(k=1;iq[jk-k]==0;k++);for(i=jz+1;i<=jz+k;i++){f[jx+i]=(double)ipio2[jv+i];for(j=0,fw=0.0;j<=jx;j++)fw+=x[j]*f[jx+i-j];q[i]=fw;}jz+=k;goto recompute;}}
if(z==0.0){jz--;q0-=24;while(iq[jz]==0){jz--;q0-=24;}}else{z=Runtime_ScaleNormalizedDoubleByPowerOfTwo(z,-q0);if(z>=16777216.0){fw=(double)(int)(0.000000059604644775390625*z);iq[jz]=(int)(z-16777216.0*fw);jz++;q0+=24;iq[jz]=(int)fw;}else iq[jz]=(int)z;}
fw=Runtime_ScaleNormalizedDoubleByPowerOfTwo(1.0,q0);for(i=jz;i>=0;i--){q[i]=fw*(double)iq[i];fw*=0.000000059604644775390625;}
for(i=jz;i>=0;i--){for(fw=0.0,k=0;k<=jp&&k<=jz-i;k++)fw+=MathReduceChunkedDoubleAngleByHalfPi_UnknownRoleInitializedBytes_Variant2[k]*q[i+k];fq[jz-i]=fw;}
switch(prec){case 0:fw=0.0;for(i=jz;i>=0;i--)fw+=fq[i];y[0]=ih==0?fw:0.0-fw;break;
case 1:case 2:fw=0.0;for(i=jz;i>=0;i--)fw+=fq[i];y[0]=ih==0?fw:0.0-fw;fw=fq[0]-fw;for(i=1;i<=jz;i++)fw+=fq[i];y[1]=ih==0?fw:0.0-fw;break;
case 3:for(i=jz;i>0;i--){fw=fq[i-1]+fq[i];fq[i]+=(fq[i-1]-fw);fq[i-1]=fw;}for(i=jz;i>1;i--){fw=fq[i-1]+fq[i];fq[i]+=(fq[i-1]-fw);fq[i-1]=fw;}for(fw=0.0,i=jz;i>=2;i--)fw+=fq[i];if(ih==0){y[0]=fq[0];y[1]=fq[1];y[2]=fw;}else{y[0]=0.0-fq[0];y[1]=0.0-fq[1];y[2]=0.0-fw;}}
return n&7;
}
