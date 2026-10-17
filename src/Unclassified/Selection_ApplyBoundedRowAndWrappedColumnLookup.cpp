#include <globaldefs.h>
ARM
struct Selection { unsigned char pad[0xBE]; unsigned char row, padBF, column; };
extern "C" signed char data_020ef9c4[9][13];
extern "C" void Object_SelectRegularAnimationAndStoreIndex(Selection*, int);
// Original: arm9/main @ 0x02033DD4; symbol: func_02033dd4; size: 0x44.
extern "C" void Selection_ApplyBoundedRowAndWrappedColumnLookup(Selection* self) {
 if (self->row >= 9) return;
 if (self->column >= 12) self->column = 0;
 Object_SelectRegularAnimationAndStoreIndex(self, data_020ef9c4[self->row][self->column]);
}
