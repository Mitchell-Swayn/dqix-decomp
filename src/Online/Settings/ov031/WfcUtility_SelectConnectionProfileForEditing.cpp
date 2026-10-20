#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" unsigned char *NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" unsigned char WfcUtilitySelectConnectionProfileForEditing_UnknownRoleInitializedBytes[];
extern "C" int RuntimeMemory_CompareByteRanges(const void *, const void *, unsigned);
extern "C" void Util_WriteLeadingBitMaskBytes(unsigned int, unsigned char *);
struct BytePair { unsigned char first,second; };
// Original: arm9/ov031 @ 0x02236094; symbol: WfcUtility_SelectConnectionProfileForEditing; size: 0xE0.
// Copies the selected page, checks its four-byte header fields, and writes its leading-bit mask.
extern "C" void WfcUtility_SelectConnectionProfileForEditing(unsigned index) {
 unsigned char *base=NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
 unsigned char *page=base+(index<<8);
 int count=120;
 BytePair *dest=(BytePair *)(base+0x400);
 BytePair *source=(BytePair *)page;
 do { unsigned char a=source->first; unsigned char b=source->second; ++source; dest->first=a; dest->second=b; ++dest; } while(--count);
 base[0x4f4]=index;
 if(RuntimeMemory_CompareByteRanges(page+0xc0,WfcUtilitySelectConnectionProfileForEditing_UnknownRoleInitializedBytes,4)!=0) NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[0x4f5]=0;
 else NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[0x4f5]=1;
 if(RuntimeMemory_CompareByteRanges(page+0xc8,WfcUtilitySelectConnectionProfileForEditing_UnknownRoleInitializedBytes,4)!=0 || RuntimeMemory_CompareByteRanges(page+0xcc,WfcUtilitySelectConnectionProfileForEditing_UnknownRoleInitializedBytes,4)!=0) NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[0x4f6]=0;
 else NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[0x4f6]=1;
 Util_WriteLeadingBitMaskBytes(page[0xd0],NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x4f0);
}
