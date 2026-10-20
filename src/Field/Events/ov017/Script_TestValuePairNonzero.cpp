#include <globaldefs.h>
ARM
struct TwoWordValue {unsigned first,second;};
// Original: arm9/ov017 @ 0x021D49AC; symbol: Script_TestValuePairNonzero; size: 0x24.
// Tests the first two words of a two-word value passed in registers by the execution interpreter.
extern "C" int Script_TestValuePairNonzero(TwoWordValue value) {
 return value.first!=0 || value.second!=0;
}
