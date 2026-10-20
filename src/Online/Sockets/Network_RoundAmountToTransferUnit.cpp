#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e1d0; symbol: data_ov031_0224e1d0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern unsigned char* OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[]; extern int NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant3[]; int _Z20DisableIRQInterruptsv(); int _Z20SetIRQInterruptStatei(int); }
// Original: arm9/ov031 @ 0x022066B4; symbol: func_ov031_022066b4; size: 0xA4.
extern "C" int Network_RoundAmountToTransferUnit(int amount) {
 unsigned char* limits=*(unsigned char**)(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[1]+0xa4);
 int irq=_Z20DisableIRQInterruptsv();
 int unit;
 if(limits) {
  int first=*(unsigned short*)(limits+0x2e);
  int second;
  if(first && (second=*(unsigned short*)(limits+0x2c))) {
   int maximum=NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant3[9];
   if(first>second) first=second;
   if(first>maximum) first=maximum;
   unit=first*2;
  } else unit=NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant3[9]*2;
 } else unit=NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant3[9]*2;
 _Z20SetIRQInterruptStatei(irq);
 if(unit>0) {
  int quotient=amount/unit;
  if(quotient>0) return unit*quotient;
 }
 return amount;
}
