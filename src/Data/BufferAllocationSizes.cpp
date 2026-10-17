// Buffer allocation/clear byte counts, indexed by object byte0x1f and word0x18.
// The two row/category meanings remain unresolved; stride and units are observed.
extern "C" {
extern const unsigned int data_020e7b98[2][4] = {
    {2 * 1024, 4 * 1024, 4 * 1024, 8 * 1024},
    {512, 2 * 1024, 8 * 1024, 32 * 1024}
};
}
typedef char BufferAllocationElementWidth[sizeof(unsigned int) == 4 ? 1 : -1];
typedef char BufferAllocationTableSize[sizeof(data_020e7b98) == 32 ? 1 : -1];
