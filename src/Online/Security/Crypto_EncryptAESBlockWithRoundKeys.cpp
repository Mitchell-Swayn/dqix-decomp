#include <globaldefs.h>
THUMB
#pragma optimization_level 4
// Original data: arm9/ov031 @ 0x2246d10; symbol: data_ov031_02246d10.
// AES forward MixColumns, byte order 3/1/1/2. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex a56363c6847c7cf8997777ee8d7b7bf60df2f2ffbd6b6bd6b16f6fde54c5c5915030306003010102a96767ce7d2b2b5619fefee762d7d7b5e6abab4d9a7676ec ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2247110; symbol: data_ov031_02247110.
// AES forward MixColumns, byte order 1/1/2/3. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex 6363c6a57c7cf8847777ee997b7bf68df2f2ff0d6b6bd6bd6f6fdeb1c5c5915430306050010102036767cea92b2b567dfefee719d7d7b562abab4de67676ec9a ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2247510; symbol: data_ov031_02247510.
// AES forward MixColumns, byte order 1/2/3/1. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex 63c6a5637cf8847c77ee99777bf68d7bf2ff0df26bd6bd6b6fdeb16fc59154c5306050300102030167cea9672b567d2bfee719fed7b562d7ab4de6ab76ec9a76 ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2247910; symbol: data_ov031_02247910.
// AES forward MixColumns, byte order 2/3/1/1. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex c6a56363f8847c7cee997777f68d7b7bff0df2f2d6bd6b6bdeb16f6f9154c5c56050303002030101cea96767567d2b2be719fefeb562d7d74de6ababec9a7676 ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2247d10; symbol: data_ov031_02247d10.
// AES forward S-box replicated into each byte. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex 636363637c7c7c7c777777777b7b7b7bf2f2f2f26b6b6b6b6f6f6f6fc5c5c5c53030303001010101676767672b2b2b2bfefefefed7d7d7d7abababab76767676 ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned CryptoEncryptAESBlockWithRoundKeys_AESForwardMixColumnsByteOrder2311[],CryptoEncryptAESBlockWithRoundKeys_AESForwardMixColumnsByteOrder1231[],CryptoEncryptAESBlockWithRoundKeys_AESForwardMixColumnsByteOrder3112[],CryptoEncryptAESBlockWithRoundKeys_AESForwardMixColumnsByteOrder1123[],CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[];
#define T0 CryptoEncryptAESBlockWithRoundKeys_AESForwardMixColumnsByteOrder3112
#define T1 CryptoEncryptAESBlockWithRoundKeys_AESForwardMixColumnsByteOrder1123
#define T2 CryptoEncryptAESBlockWithRoundKeys_AESForwardMixColumnsByteOrder1231
#define T3 CryptoEncryptAESBlockWithRoundKeys_AESForwardMixColumnsByteOrder2311
#define T4 CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte
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
