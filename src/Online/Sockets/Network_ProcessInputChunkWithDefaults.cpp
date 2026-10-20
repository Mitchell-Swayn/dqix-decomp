#include <globaldefs.h>
ARM
extern "C" int Network_SendSocketData(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02207360; symbol: Network_ProcessInputChunkWithDefaults; size: 0x20.
// Processes an input chunk with its three optional arguments set to zero.
extern "C" int Network_ProcessInputChunkWithDefaults(unsigned int destination, unsigned int source, unsigned int length) {
    return Network_SendSocketData(destination, source, length, 0, 0, 0);
}
