#pragma opt_propagation off
#pragma opt_arithtransformation off
#include <globaldefs.h>
struct Flags { unsigned char low:4; unsigned char high:4; };
struct Owner {char pad[0x1c];Flags flags;};
extern "C" void (*data_020f01d8[4][4])(unsigned int);
// Original: arm9/main @ 0x0204B5B4; symbol: func_0204b5b4; size: 0x34.
extern "C" ARM void DispatchModeThroughTwoDimensionalFlagTable(Owner* self,unsigned int mode) {
 Flags* flags=&self->flags;
 void (*function)(unsigned int)=data_020f01d8[flags->low][flags->high];
 mode &= 3;
 function(mode);
}
