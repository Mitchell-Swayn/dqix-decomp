#include <globaldefs.h>
THUMB
extern "C" int Crypto_ExpandAesEncryptionRoundKeys(unsigned*, const unsigned char*, int);
extern "C" const unsigned CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[];
extern "C" const unsigned NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1411139[];
extern "C" const unsigned NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder9141113[];
extern "C" const unsigned NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1391411[];
extern "C" const unsigned NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1113914[];
#define INVERSE_MIX(word) (NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1113914[CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[(word)>>24]&255] ^ NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1391411[CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[((word)>>16)&255]&255] ^ NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder9141113[CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[((word)>>8)&255]&255] ^ NetworkDecryptRijndaelBlock_AESInverseMixColumnsByteOrder1411139[CryptoEncryptAESBlockWithRoundKeys_AESForwardSBoxReplicatedIntoEachByte[(word)&255]&255])
// Original: ARM9 arm9/ov031 @ 0x0222157C; Crypto_ExpandAesDecryptionRoundKeys; size 0x190.
// Reverses encryption round keys and applies inverse MixColumns to intermediate rounds.
extern "C" int Crypto_ExpandAesDecryptionRoundKeys(unsigned* roundKeys, const unsigned char* key, int bits) {
    int rounds = Crypto_ExpandAesEncryptionRoundKeys(roundKeys, key, bits);
    int i, j;
    unsigned temp;
    for (i = 0, j = rounds * 4; i < j; i += 4, j -= 4) {
        temp = roundKeys[i]; roundKeys[i] = roundKeys[j]; roundKeys[j] = temp;
        temp = roundKeys[i+1]; roundKeys[i+1] = roundKeys[j+1]; roundKeys[j+1] = temp;
        temp = roundKeys[i+2]; roundKeys[i+2] = roundKeys[j+2]; roundKeys[j+2] = temp;
        temp = roundKeys[i+3]; roundKeys[i+3] = roundKeys[j+3]; roundKeys[j+3] = temp;
    }
    for (i = 1; i < rounds; ++i) {
        roundKeys += 4;
        roundKeys[0] = INVERSE_MIX(roundKeys[0]);
        roundKeys[1] = INVERSE_MIX(roundKeys[1]);
        roundKeys[2] = INVERSE_MIX(roundKeys[2]);
        roundKeys[3] = INVERSE_MIX(roundKeys[3]);
    }
    return rounds;
}
