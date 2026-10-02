#include "World/Zone3D.h"

extern "C" void* func_0205ec34();
extern "C" void func_02018300(Zone3D*, ZoneFeatures::Opcode6aEntry*, int, int, int);

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
            func_02018300(this, feature, 0, 0, 0);
        }
    }
    unknown_281e_ = 0;
}
