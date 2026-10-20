#include <globaldefs.h>
ARM
extern "C" int Combat_TestMonsterDescriptorMode(void*,int,int,int);
struct StridedHalfword { short value;short following; };
// Original data: arm9/ov024 @ 0x21fe820; symbol: data_ov024_021fe820.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0200.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" StridedHalfword LookupModeValueUnlessPackedModeRejected_UnknownRoleInitializedBytes[];
// Original data: arm9/ov024 @ 0x21fe822; symbol: data_ov024_021fe822.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 12000300130004001400050015000600160007001c0008001b00ffffffff.
// Observed span: 30 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" StridedHalfword LookupModeValueUnlessPackedModeRejected_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov024 @ 0x021E8FA4; symbol: func_ov024_021e8fa4; size: 0x74.
// Looks up a paired signed-halfword value; mode2 is rejected when the packed-mode test succeeds.
extern "C" int LookupModeValueUnlessPackedModeRejected(char* self,int index,int mode) {
 if(mode==2 && Combat_TestMonsterDescriptorMode(*(void**)(self+16),index,0,2))return 0;
 for(int i=0;LookupModeValueUnlessPackedModeRejected_UnknownRoleInitializedBytes[i].value!=-1;++i) {
  if(mode==LookupModeValueUnlessPackedModeRejected_UnknownRoleInitializedBytes[i].value)return LookupModeValueUnlessPackedModeRejected_UnknownRoleInitializedBytes_Variant2[i].value;
 }
 return 0;
}
