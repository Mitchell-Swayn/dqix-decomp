#include <globaldefs.h>
ARM
struct Pair { unsigned int key; unsigned int value; };
// Original data: arm9/ov004 @ 0x21702bc; symbol: data_ov004_021702bc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex d8000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Pair ResourceEncodeTypeAndKeyCode_UnknownRoleInitializedBytes[12];
// Original data: arm9/ov004 @ 0x21702c0; symbol: data_ov004_021702c0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 22000000ea00000023000000e100000024000000e3000000250000004c010000260000004201000027000000db000000280000004f0100002900000050010000 ...; full span in module reference.
// Observed span: 92 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Pair ResourceEncodeTypeAndKeyCode_UnknownRoleInitializedBytes_Variant2[12];
// Original: arm9/ov004 @ 0x0216F990; symbol: Resource_EncodeTypeAndKeyCode; size: 0x78.
// Maps type 1 keys through paired 12-entry tables; type 2 computes the 13-wide code for keys 1–13 and nonzero value.
extern "C" unsigned int Resource_EncodeTypeAndKeyCode(unsigned int type, unsigned int key, unsigned int value) {
 if (type == 1) {
  for (int i = 0; i < 12; ++i)
   if (ResourceEncodeTypeAndKeyCode_UnknownRoleInitializedBytes[i].key == key) return ResourceEncodeTypeAndKeyCode_UnknownRoleInitializedBytes_Variant2[i].key;
 } else if (type == 2 && key >= 1 && key <= 13 && value != 0) {
  return key + 0x2d + (value - 1) * 13;
 }
 return 0;
}
