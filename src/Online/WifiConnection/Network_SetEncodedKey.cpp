#include <globaldefs.h>
ARM
#include <System/Memory.h>
struct KeyFlags { unsigned char lengthClass:2; unsigned char plain:6; };
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" int WfcUtility_CountNonzeroBytePrefix(const char*,int);
extern "C" unsigned int Util_ConvertHexAsciiToValue(unsigned int);
// Original: arm9/ov031 @ 0x02235CDC; symbol: func_ov031_02235cdc; size: 0x198.
extern "C" void Network_SetEncodedKey(const char* input) {
 int i;
 VectorizedMemset(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x480,0,16);
 int length=WfcUtility_CountNonzeroBytePrefix(input,32);
 switch(length) {
 case 0: case 10: case 26: case 32: {
 ((KeyFlags*)(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x4e6))->plain=0;
 unsigned char* output=(unsigned char*)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x480;
 i=0;
 if(length>0) do {
 const char* pair=input+i;
 unsigned high=Util_ConvertHexAsciiToValue((unsigned char)input[i]);
 unsigned low=Util_ConvertHexAsciiToValue((unsigned char)pair[1]);
 *output++=low+(high<<4);
 i+=2;
 } while(i<length);
 break;
 }
 default:
 ((KeyFlags*)(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x4e6))->plain=1;
 MI_CpuCopy8(input,NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x480,16);
 break;
 }
 switch(length) {
 case 0: ((KeyFlags*)(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x4e6))->lengthClass=0; break;
 case 5: case 10: ((KeyFlags*)(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x4e6))->lengthClass=1; break;
 case 13: case 26: ((KeyFlags*)(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x4e6))->lengthClass=2; break;
 default: ((KeyFlags*)(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+0x4e6))->lengthClass=3; break;
 }
}
