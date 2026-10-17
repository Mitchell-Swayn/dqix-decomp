#include <globaldefs.h>
THUMB
#pragma optimization_level 4
extern "C" unsigned data_ov031_02247910[],data_ov031_02247510[],data_ov031_02246d10[],data_ov031_02247110[],data_ov031_02247d10[];
#define T0 data_ov031_02246d10
#define T1 data_ov031_02247110
#define T2 data_ov031_02247510
#define T3 data_ov031_02247910
#define T4 data_ov031_02247d10
#define GET(p) (((unsigned)(p)[0]<<24)^((unsigned)(p)[1]<<16)^((unsigned)(p)[2]<<8)^((p)[3]))
#define ROUND(a,b,c,d,k) (T0[(a)>>24]^T1[((b)>>16)&255]^T2[((c)>>8)&255]^T3[(d)&255]^(k))
#define FINAL(a,b,c,d,k) ((T4[(a)>>24]&0xff000000)^(T4[((b)>>16)&255]&0xff0000)^(T4[((c)>>8)&255]&0xff00)^(T4[(d)&255]&255)^(k))
#define PUT(p,v) (p)[0]=(v)>>24;(p)[1]=(v)>>16;(p)[2]=(v)>>8;(p)[3]=(v)
// Original: arm9/ov031 @ 0x0222170C; symbol: func_ov031_0222170c; size: 0x3BC.
extern "C" void Crypto_EncryptAESBlockWithRoundKeys(const unsigned* rk,int rounds,const unsigned char* input,unsigned char* output) {
unsigned s0,s1,s2,s3,t0,t1,t2,t3;int r;
s0=GET(input)^rk[0];s1=GET(input+4)^rk[1];s2=GET(input+8)^rk[2];s3=GET(input+12)^rk[3];
r=rounds>>1;
for(;;) {
t0=ROUND(s0,s1,s2,s3,rk[4]);
t1=ROUND(s1,s2,s3,s0,rk[5]);
t2=ROUND(s2,s3,s0,s1,rk[6]);
t3=ROUND(s3,s0,s1,s2,rk[7]);
rk+=8;if(--r==0) break;
s0=ROUND(t0,t1,t2,t3,rk[0]);
s1=ROUND(t1,t2,t3,t0,rk[1]);
s2=ROUND(t2,t3,t0,t1,rk[2]);
s3=ROUND(t3,t0,t1,t2,rk[3]);
}
s0=FINAL(t0,t1,t2,t3,rk[0]);PUT(output,s0);
s1=FINAL(t1,t2,t3,t0,rk[1]);PUT(output+4,s1);
s2=FINAL(t2,t3,t0,t1,rk[2]);PUT(output+8,s2);
s3=FINAL(t3,t0,t1,t2,rk[3]);PUT(output+12,s3);
}
