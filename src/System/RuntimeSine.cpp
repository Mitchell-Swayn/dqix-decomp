#pragma optimize_for_size off

// Binary64 word access follows the pinned little-endian ARM runtime ABI.
extern "C" double RuntimeSineKernel_EvaluateReducedSinePolynomial(double, double, int);
extern "C" double Runtime_ComputeCosineKernel(double, double);
extern "C" int func_02007028(double, double*);
// Original: arm9/main @ 0x02009424; symbol: func_02009424; size: 0x174.
extern "C" double Runtime_ComputeSine(double value)
{
    double zero = 0.0;
    int high = ((int*)&value)[1] & 0x7fffffff;
    if (high <= 0x3fe921fb)
        return RuntimeSineKernel_EvaluateReducedSinePolynomial(value, zero, 0);
    if (high >= 0x7ff00000)
        return value - value;
    double reduced[2];
    int quadrant = func_02007028(value, reduced);
    switch (quadrant & 3) {
    case 0:
        return RuntimeSineKernel_EvaluateReducedSinePolynomial(reduced[0], reduced[1], 1);
    case 1:
        return Runtime_ComputeCosineKernel(reduced[0], reduced[1]);
    case 2:
        return -RuntimeSineKernel_EvaluateReducedSinePolynomial(reduced[0], reduced[1], 1);
    default:
        return -Runtime_ComputeCosineKernel(reduced[0], reduced[1]);
    }
}
