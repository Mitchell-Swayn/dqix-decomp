#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct Random;
struct ByteTable { char bytes[12]; };
extern "C" ByteTable data_ov000_02182a85;
extern "C" int _Z17NextRandomBetweenP6Randomii(Random*, int, int);
// Original: arm9/ov000 @ 0x0215FBE0; symbol: func_ov000_0215fbe0; size: 0x80.
extern "C" int Util_GetRandomizedTableByte(Random* random, int index) {
    ByteTable table = data_ov000_02182a85;
    table.bytes[3] = _Z17NextRandomBetweenP6Randomii(random, 3, 4);
    table.bytes[11] = _Z17NextRandomBetweenP6Randomii(random, 6, 8);
    char* bytes = table.bytes;
    return index < 0 || index >= 12 ? 0 : bytes[index];
}
