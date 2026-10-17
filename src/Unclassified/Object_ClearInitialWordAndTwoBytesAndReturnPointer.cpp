#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void Object_ClearInitialWordAndTwoBytes(void *);
// Original: arm9/main @ 0x0209CE00; symbol: func_0209ce00; size: 0x14.
void *Object_ClearInitialWordAndTwoBytesAndReturnPointer(void *p){Object_ClearInitialWordAndTwoBytes(p);return p;}
}
