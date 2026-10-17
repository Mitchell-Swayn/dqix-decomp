#include <globaldefs.h>
#include "std_library_functions.h"
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
// Original: arm9/main @ 0x02069BE4; symbol: func_02069be4; size: 0x38.
unsigned int Text_WriteControlCodeFromSignedInputByte(void** output, signed char* input) {
 int byte = *input;
 unsigned int base = 0xffe0;
 void* destination = *output;
 unsigned short delta = (unsigned short)(byte - 0x40);
 unsigned short value = (unsigned short)(base + delta);
 memcpy(destination, &value, 2);
 return 2;
}
