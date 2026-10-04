#include "World/Zone3D.h"

extern "C" void* func_0205ec34();

void Zone3D::ApplyType2FeatureMask(unsigned int mask)
{
    func_0205ec34();
    for (int i = 0; i < 16; ++i)
    {
        if (mask & (1 << i))
        {
            ZoneFeatures::Opcode6aEntry* feature = GetType2Feature(i);
            if (!feature) continue;
            if (!(feature->unk_2c.type2.unk_2_high & 8))
                feature->unk_2c.type2.unk_2_high |= 0x101;
            ActivateType2Feature(feature, false, false, 0);
        }
    }
    unknown_281e_ = 0;
}
