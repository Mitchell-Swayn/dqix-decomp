#include <globaldefs.h>
// func_0203dd10: 0x0203dd10–0x0203dd20, arm; 16 bytes
// Original: arm9/main @ 0x0203DD10; symbol: func_0203dd10; size: 0x10.
extern "C" void SetOneOfThirtyTwoWordEntries(int self, unsigned int index, unsigned int value) {
    if (index < 0x20) {
            *(unsigned int*)(self + index * 4 + 0x0c) = value;
        }
}
