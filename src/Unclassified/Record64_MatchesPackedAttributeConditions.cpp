// Original: arm9/main @ 0x0209DCDC; symbol: func_0209dcdc; size: 0x4f0.
#include <globaldefs.h>
#include <std_library_functions.h>
struct PackedAttributeStates {
 signed state0:3;
 signed state1:3;
 signed state2:3;
 signed state3:3;
 signed state4:3;
 signed state5:3;
 signed state6:3;
 signed state7:3;
 signed state8:3;
 signed state9:3;
 unsigned reserved:2;
};
struct PackedAttributeModeBits {unsigned short mode:2; unsigned short reserved:14;};
struct PackedAttributeSelectorBits {unsigned char reserved:4; unsigned char selector:4;};
struct PackedAttributeStateRecord {
 unsigned long long primaryFlags;
 unsigned long long alternateFlags;
 unsigned unknown10,unknown14;
 PackedAttributeModeBits primaryMode,alternateMode;
 PackedAttributeSelectorBits primarySelector,alternateSelector;
 unsigned char unknown1E[10];
 PackedAttributeStates primaryStates,alternateStates;
 unsigned unknown30[4];
};
// Original ARM9 main @ 0x0209dcdc, symbol func_0209dcdc.
extern "C" ARM int Record64_MatchesPackedAttributeConditions(void*,const PackedAttributeStateRecord* record,int alternate,unsigned requested)
{
 unsigned selector;
 unsigned flagsLow,flagsHigh;
 unsigned mode;
 PackedAttributeStates states;
 if (!alternate) {
  unsigned long long rawFlags=record->primaryFlags;
  flagsLow=(unsigned)rawFlags;
  flagsHigh=(unsigned)(rawFlags>>32);
  mode=record->primaryMode.mode;
  selector=record->primarySelector.selector;
  memcpy(&states,&record->primaryStates,4);
 } else {
  unsigned long long rawFlags=record->alternateFlags;
  flagsLow=(unsigned)rawFlags;
  flagsHigh=(unsigned)(rawFlags>>32);
  mode=record->alternateMode.mode;
  selector=record->alternateSelector.selector;
  memcpy(&states,&record->alternateStates,4);
 }
 if ((requested & 0x1U) && (flagsLow & 0x2U) && mode == 1) return 1;
 if ((requested & 0x2U) && (flagsLow & 0x2U) && mode == 2) return 1;
 if ((requested & 0x4U) && (flagsLow & 0x400U) && states.state0 == 2) return 1;
 if ((requested & 0x8U) && (flagsLow & 0x400U) && states.state0 == 1) return 1;
 if ((requested & 0x10U) && (flagsLow & 0x400U) && states.state0 == -1) return 1;
 if ((requested & 0x20U) && (flagsLow & 0x400U) && states.state0 == -2) return 1;
 if ((requested & 0x40U) && (flagsLow & 0x800U) && states.state1 == 2) return 1;
 if ((requested & 0x80U) && (flagsLow & 0x800U) && states.state1 == 1) return 1;
 if ((requested & 0x100U) && (flagsLow & 0x800U) && states.state1 == -1) return 1;
 if ((requested & 0x200U) && (flagsLow & 0x800U) && states.state1 == -2) return 1;
 if ((requested & 0x400U) && (flagsLow & 0x1000U) && states.state2 == 2) return 1;
 if ((requested & 0x800U) && (flagsLow & 0x1000U) && states.state2 == 1) return 1;
 if ((requested & 0x1000U) && (flagsLow & 0x1000U) && states.state2 == -1) return 1;
 if ((requested & 0x2000U) && (flagsLow & 0x1000U) && states.state2 == -2) return 1;
 if ((requested & 0x4000U) && (flagsLow & 0x2000U) && states.state3 == 1) return 1;
 if ((requested & 0x8000U) && (flagsLow & 0x4000U) && states.state4 == 2) return 1;
 if ((requested & 0x10000U) && (flagsLow & 0x4000U) && states.state4 == 1) return 1;
 if ((requested & 0x20000U) && (flagsLow & 0x8000U) && states.state5 == 2) return 1;
 if ((requested & 0x40000U) && (flagsLow & 0x8000U) && states.state5 == 1) return 1;
 if ((requested & 0x80000U) && (flagsLow & 0x10000U) && states.state6 == 2) return 1;
 if ((requested & 0x100000U) && (flagsLow & 0x10000U) && states.state6 == 1) return 1;
 if ((requested & 0x200000U) && (flagsLow & 0x10000U) && states.state6 == -1) return 1;
 if ((requested & 0x400000U) && (flagsLow & 0x10000U) && states.state6 == -2) return 1;
 if ((requested & 0x800000U) && (flagsLow & 0x20000U) && states.state7 == 2) return 1;
 if ((requested & 0x1000000U) && (flagsLow & 0x20000U) && states.state7 == 1) return 1;
 if ((requested & 0x2000000U) && (flagsHigh & 0x1U) && states.state8 == 2) return 1;
 if ((requested & 0x4000000U) && (flagsLow & 0x2000000U) && states.state9 == 2) return 1;
 if ((requested & 0x8000000U) && (flagsLow & 0x800000U) && selector == 1) return 1;
 if ((requested & 0x10000000U) && (flagsLow & 0x800000U) && selector == 2) return 1;
 if ((requested & 0x20000000U) && (flagsLow & 0x800000U) && selector == 3) return 1;
 return 0;
}
