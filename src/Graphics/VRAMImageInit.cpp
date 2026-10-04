#include "Graphics/VRAMAllocations.h"
#include "Graphics/VRAMImagePool.h"

extern Struct_020f1f14* data_020f1ef8[7];
extern "C" unsigned int func_020bb588(unsigned int, unsigned int, unsigned int);

#pragma dont_inline on
void SetTextureImageVRAMPoolOrder(int first, int second, int third, int fourth, int fifth)
{
    data_020f1ef8[2] = &data_020f1f14[first];
    data_020f1ef8[3] = &data_020f1f14[second];
    data_020f1ef8[4] = &data_020f1f14[third];
    data_020f1ef8[5] = &data_020f1f14[fourth];
    data_020f1ef8[6] = &data_020f1f14[fifth];
}

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
        data_020f1ee8 = func_020bb588;
        data_020f1eec = FreeTextureImageVRAM;
    }
}
