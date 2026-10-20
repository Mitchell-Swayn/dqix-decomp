#include <globaldefs.h>
THUMB
#pragma always_inline on
// Original data: arm9/ov031 @ 0x22460e8; symbol: data_ov031_022460e8.
// AES key schedule round constants; powers of x in GF(2^8), high byte packing.
// Initial values: hex 00000001000000020000000400000008000000100000002000000040000000800000001b00000036.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const unsigned CryptoExpandAesEncryptionRoundKeys_AESKeyScheduleRoundConstants[];
// Original data: arm9/ov031 @ 0x2247d10; symbol: data_ov031_02247d10.
// AES forward S-box replicated into each byte. Index is the input byte. Entries use GF(2^8), polynomial 0x11b; the substituted byte is multiplied by the indicated coefficients. Numeric words below preserve the original little-endian table packing.
// Initial values: hex 636363637c7c7c7c777777777b7b7b7bf2f2f2f26b6b6b6b6f6f6f6fc5c5c5c53030303001010101676767672b2b2b2bfefefefed7d7d7d7abababab76767676 ...; full span in module reference.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const unsigned CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[];
inline unsigned ReadKeyWord(const unsigned char* key){return ((unsigned)key[0]<<24)^((unsigned)key[1]<<16)^((unsigned)key[2]<<8)^key[3];}
#define ROTATE_SUB_XOR(base,word) ((base)^(CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[((word)>>16)&255]&0xff000000)^(CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[((word)>>8)&255]&0xff0000)^(CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[(word)&255]&0xff00)^(CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[(word)>>24]&255))
#define SUB_XOR(base,word) ((base)^(CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[(word)>>24]&0xff000000)^(CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[((word)>>16)&255]&0xff0000)^(CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[((word)>>8)&255]&0xff00)^(CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[(word)&255]&255))
// Original: arm9/ov031 @ 0x022212C4; symbol: func_ov031_022212c4; size: 0x2B8.
// Expands 128/192/256-bit cipher keys using rotated substitution words and round constants; returns10/12/14 rounds.
extern "C" int Crypto_ExpandAesEncryptionRoundKeys(unsigned* roundKeys,const unsigned char* key,int bits){
int i=0;
roundKeys[0]=ReadKeyWord(key);roundKeys[1]=ReadKeyWord(key+4);roundKeys[2]=ReadKeyWord(key+8);roundKeys[3]=ReadKeyWord(key+12);
if(bits==128){for(;;){unsigned temp=roundKeys[3];roundKeys[4]=ROTATE_SUB_XOR(roundKeys[0],temp)^CryptoExpandAesEncryptionRoundKeys_AESKeyScheduleRoundConstants[i];roundKeys[5]=roundKeys[1]^roundKeys[4];roundKeys[6]=roundKeys[2]^roundKeys[5];roundKeys[7]=roundKeys[3]^roundKeys[6];if(++i>=10)return 10;roundKeys+=4;}}
roundKeys[4]=ReadKeyWord(key+16);roundKeys[5]=ReadKeyWord(key+20);
if(bits==192){for(;;){unsigned temp=roundKeys[5];roundKeys[6]=ROTATE_SUB_XOR(roundKeys[0],temp)^CryptoExpandAesEncryptionRoundKeys_AESKeyScheduleRoundConstants[i];roundKeys[7]=roundKeys[1]^roundKeys[6];roundKeys[8]=roundKeys[2]^roundKeys[7];roundKeys[9]=roundKeys[3]^roundKeys[8];if(++i>=8)return 12;roundKeys[10]=roundKeys[4]^roundKeys[9];roundKeys[11]=roundKeys[5]^roundKeys[10];roundKeys+=6;}}
roundKeys[6]=ReadKeyWord(key+24);roundKeys[7]=ReadKeyWord(key+28);
if(bits==256){for(;;){unsigned temp=roundKeys[7];roundKeys[8]=ROTATE_SUB_XOR(roundKeys[0],temp)^CryptoExpandAesEncryptionRoundKeys_AESKeyScheduleRoundConstants[i];roundKeys[9]=roundKeys[1]^roundKeys[8];roundKeys[10]=roundKeys[2]^roundKeys[9];roundKeys[11]=roundKeys[3]^roundKeys[10];if(++i>=7)return 14;temp=roundKeys[11];roundKeys[12]=SUB_XOR(roundKeys[4],temp);roundKeys[13]=roundKeys[5]^roundKeys[12];roundKeys[14]=roundKeys[6]^roundKeys[13];roundKeys[15]=roundKeys[7]^roundKeys[14];roundKeys+=8;}}
return 0;
}
