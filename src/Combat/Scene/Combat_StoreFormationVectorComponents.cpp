#pragma thumb off
#pragma force_active on
struct ThreeWords { unsigned int first, second, third; };
// Original: arm9/ov000 @ 0x02167B54; symbol: StoreThreeArgumentWords; size: 0x8.
extern "C" void Combat_StoreFormationVectorComponents(ThreeWords* destination, unsigned int first, unsigned int second, unsigned int third)
{
    destination->first = first;
    destination->second = second;
    destination->third = third;
}
