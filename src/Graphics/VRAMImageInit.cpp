#include "Graphics/VRAMAllocations.h"
#include "Graphics/VRAMImagePool.h"

extern Struct_020f1f14* data_020f1ef8[7];
extern "C" unsigned int NNS_GfdAllocFrmTexVram(unsigned int, unsigned int, unsigned int);

#pragma dont_inline on
// Original: arm9/main @ 0x020BB444; symbol: _Z28SetTextureImageVRAMPoolOrderiiiii; size: 0x48.
void SetTextureImageVRAMPoolOrder(int first, int second, int third, int fourth, int fifth)
{
    data_020f1ef8[2] = &data_020f1f14[first];
    data_020f1ef8[3] = &data_020f1f14[second];
    data_020f1ef8[4] = &data_020f1f14[third];
    data_020f1ef8[5] = &data_020f1f14[fourth];
    data_020f1ef8[6] = &data_020f1f14[fifth];
}

// Original: arm9/main @ 0x020BB48C; symbol: _Z26InitializeTextureImageVRAMjb; size: 0x88.
void InitializeTextureImageVRAM(unsigned int banks, bool setDefault)
{
    if (banks <= 2)
        SetTextureImageVRAMPoolOrder(4, 3, 2, 0, 1);
    else
        SetTextureImageVRAMPoolOrder(4, 3, 0, 2, 1);
    data_0210cf84.bankCount = banks;
    ResetTextureImageVRAM();
    if (setDefault)
    {
        data_020f1ee8 = NNS_GfdAllocFrmTexVram;
        data_020f1eec = FreeTextureImageVRAM;
    }
}
