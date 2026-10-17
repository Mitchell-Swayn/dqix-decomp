#include "World/Zone3D.h"

extern "C" void* ReadGlobalValueAt02108844();

// Original: arm9/main @ 0x02018C74; symbol: _ZN6Zone3D21ApplyType2FeatureMaskEj; size: 0xB4.
void Zone3D::ApplyType2FeatureMask(unsigned int mask)
{
    ReadGlobalValueAt02108844();
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
