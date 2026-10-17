#pragma optimize_for_size off

extern "C" double Runtime_ComputeDoubleArctangent2(double, double);
extern "C" double func_02005ea0(double, double);

// Original: arm9/main @ 0x02009598; symbol: func_02009598; size: 0xC.
extern "C" double RuntimeMathEntries_ComputeAtan2(double y, double x)
{
    return Runtime_ComputeDoubleArctangent2(y, x);
}

// Original: arm9/main @ 0x020095A4; symbol: func_020095a4; size: 0xC.
extern "C" double Runtime_ComputeDoublePower(double value, double exponent)
{
    return func_02005ea0(value, exponent);
}
