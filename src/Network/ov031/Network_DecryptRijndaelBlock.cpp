#include <globaldefs.h>
THUMB
typedef unsigned int u32;
typedef unsigned char u8;
extern "C" {extern const u32 data_ov031_02246510[],data_ov031_02246110[],data_ov031_02248110[],data_ov031_02248510[],data_ov031_02246910[];}
#define Td0 data_ov031_02248110
#define Td1 data_ov031_02248510
#define Td2 data_ov031_02246110
#define Td3 data_ov031_02246510
#define Td4 data_ov031_02246910
#define GETU32(p) (((u32)(p)[0]<<24)^((u32)(p)[1]<<16)^((u32)(p)[2]<<8)^((u32)(p)[3]))
#define PUTU32(p,v) (p)[0]=(u8)((v)>>24);(p)[1]=(u8)((v)>>16);(p)[2]=(u8)((v)>>8);(p)[3]=(u8)(v)
// Original: arm9/ov031 @ 0x02221AC8; symbol: func_ov031_02221ac8; size: 0x3BC.
extern "C" void Network_DecryptRijndaelBlock(const u32* rk,int Nr,const u8* ct,u8* pt){
u32 s0,s1,s2,s3,t0,t1,t2,t3;int r;
s0=GETU32(ct)^rk[0];s1=GETU32(ct+4)^rk[1];s2=GETU32(ct+8)^rk[2];s3=GETU32(ct+12)^rk[3];
r=Nr>>1;
for(;;){
t0=Td0[s0>>24]^Td1[(s3>>16)&0xff]^Td2[(s2>>8)&0xff]^Td3[s1&0xff]^rk[4];
t1=Td0[s1>>24]^Td1[(s0>>16)&0xff]^Td2[(s3>>8)&0xff]^Td3[s2&0xff]^rk[5];
t2=Td0[s2>>24]^Td1[(s1>>16)&0xff]^Td2[(s0>>8)&0xff]^Td3[s3&0xff]^rk[6];
t3=Td0[s3>>24]^Td1[(s2>>16)&0xff]^Td2[(s1>>8)&0xff]^Td3[s0&0xff]^rk[7];
rk+=8; if(--r==0)break;
s0=Td0[t0>>24]^Td1[(t3>>16)&0xff]^Td2[(t2>>8)&0xff]^Td3[t1&0xff]^rk[0];
s1=Td0[t1>>24]^Td1[(t0>>16)&0xff]^Td2[(t3>>8)&0xff]^Td3[t2&0xff]^rk[1];
s2=Td0[t2>>24]^Td1[(t1>>16)&0xff]^Td2[(t0>>8)&0xff]^Td3[t3&0xff]^rk[2];
s3=Td0[t3>>24]^Td1[(t2>>16)&0xff]^Td2[(t1>>8)&0xff]^Td3[t0&0xff]^rk[3];
}
s0=(Td4[t0>>24]&0xff000000)^(Td4[(t3>>16)&0xff]&0x00ff0000)^(Td4[(t2>>8)&0xff]&0x0000ff00)^(Td4[t1&0xff]&0x000000ff)^rk[0];
PUTU32(pt+0,s0);
s1=(Td4[t1>>24]&0xff000000)^(Td4[(t0>>16)&0xff]&0x00ff0000)^(Td4[(t3>>8)&0xff]&0x0000ff00)^(Td4[t2&0xff]&0x000000ff)^rk[1];
PUTU32(pt+4,s1);
s2=(Td4[t2>>24]&0xff000000)^(Td4[(t1>>16)&0xff]&0x00ff0000)^(Td4[(t0>>8)&0xff]&0x0000ff00)^(Td4[t3&0xff]&0x000000ff)^rk[2];
PUTU32(pt+8,s2);
s3=(Td4[t3>>24]&0xff000000)^(Td4[(t2>>16)&0xff]&0x00ff0000)^(Td4[(t1>>8)&0xff]&0x0000ff00)^(Td4[t0&0xff]&0x000000ff)^rk[3];
PUTU32(pt+12,s3);
}
