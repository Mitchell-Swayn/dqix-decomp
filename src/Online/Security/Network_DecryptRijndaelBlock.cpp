#include <globaldefs.h>
THUMB
typedef unsigned int u32;
typedef unsigned char u8;
// Original data: arm9/ov031 @ 0x2246110; symbol: data_ov031_02246110.
// AES inverse MixColumns, byte order 9/14/11/13. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex f45150a7417e5365171ac3a4273a965eab3bcb6b9d1ff145faacab58e34b9303302055fa76adf66dcc88917602f5254ce54ffcd72ac5d7cb3526804462b58fa3 ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2246510; symbol: data_ov031_02246510.
// AES inverse MixColumns, byte order 14/11/13/9. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex 5150a7f47e5365411ac3a4173a965e273bcb6bab1ff1459dacab58fa4b9303e32055fa30adf66d76889176ccf5254c024ffcd7e5c5d7cb2a26804435b58fa362 ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2246910; symbol: data_ov031_02246910.
// AES inverse S-box replicated into each byte. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex 52525252090909096a6a6a6ad5d5d5d53030303036363636a5a5a5a538383838bfbfbfbf40404040a3a3a3a39e9e9e9e81818181f3f3f3f3d7d7d7d7fbfbfbfb ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248110; symbol: data_ov031_02248110.
// AES inverse MixColumns, byte order 11/13/9/14. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex 50a7f4515365417ec3a4171a965e273acb6bab3bf1459d1fab58faac9303e34b55fa3020f66d76ad9176cc88254c02f5fcd7e54fd7cb2ac5804435268fa362b5 ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248510; symbol: data_ov031_02248510.
// AES inverse MixColumns, byte order 13/9/14/11. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex a7f4515065417e53a4171ac35e273a966bab3bcb459d1ff158faacab03e34b93fa3020556d76adf676cc88914c02f525d7e54ffccb2ac5d744352680a362b58f ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern const u32 NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1411139[],NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder9141113[],NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1113914[],NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1391411[],NetworkDecryptRijndaelBlock_AESInverseSBoxReplicatedIntoEachByte[];}
#define Td0 NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1113914
#define Td1 NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1391411
#define Td2 NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder9141113
#define Td3 NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1411139
#define Td4 NetworkDecryptRijndaelBlock_AESInverseSBoxReplicatedIntoEachByte
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
