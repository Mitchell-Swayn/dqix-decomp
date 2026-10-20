#include <globaldefs.h>
ARM
struct Header {unsigned words[16];};
extern "C" int Network_ValidateHeaderChecksum(unsigned*);
extern "C" void* SwcaRecord_GetAssociatedIdentifier(void*);
extern "C" void CRC_InitializeEightBitPolynomialTable(unsigned char*,unsigned);
extern "C" unsigned char CRC_ComputeEightBitStateStartingAtZero(const unsigned char*,const unsigned char*,unsigned);
// Original: arm9/ov031 @ 0x022457E0; symbol: OnlineTransfer_DeriveIdentityAndGameCrc; size: 0x78.
// Validates the by-value header and packs its word1C with a seven-bit CRC tag.
extern "C" unsigned long long OnlineTransfer_DeriveIdentityAndGameCrc(unsigned unused,Header header){
 unsigned char table[256];
 unsigned payload[2];
 if(!Network_ValidateHeaderChecksum(header.words))return 0;
 // The canonical getter returns a pointer; the packet tag serializes its32-bit representation.
 unsigned word=(unsigned)SwcaRecord_GetAssociatedIdentifier(&header);
 payload[0]=word;payload[1]=0x5944514a;
 CRC_InitializeEightBitPolynomialTable(table,7);
 unsigned crc=CRC_ComputeEightBitStateStartingAtZero(table,(const unsigned char*)payload,8)&127;
 return ((unsigned long long)crc<<32)|word;
}
