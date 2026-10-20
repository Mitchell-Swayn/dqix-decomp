#include <globaldefs.h>
struct FloatParameterView { unsigned type; union { int integer; float real; } value; };
// Original: arm9/ov017 @ 0x021D6110; symbol: func_ov017_021d6110; size: 0x1C.
extern "C" ARM float Script_ReadParameterAsFloat(FloatParameterView* parameter) { unsigned type=parameter->type; float value=parameter->value.real; if(type != 0) return value; return (float)parameter->value.integer; }
