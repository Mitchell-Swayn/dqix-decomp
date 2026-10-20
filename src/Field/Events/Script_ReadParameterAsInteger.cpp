#include <globaldefs.h>
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
// Original: arm9/ov017 @ 0x021D60F4; symbol: func_ov017_021d60f4; size: 0x1C.
extern "C" ARM int Script_ReadParameterAsInteger(IntegerParameterView* parameter) { unsigned type=parameter->type; int value=parameter->value.integer; if(type != 1) return value; return (int)parameter->value.real; }
