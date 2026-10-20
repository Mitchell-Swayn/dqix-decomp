#pragma optimize_for_size off

// Binary64 words and polynomial evaluation order follow the ARM runtime ABI.
extern "C" double RuntimeSineKernel_EvaluateReducedSinePolynomial(double, double, int);
extern "C" double Runtime_ComputeCosineKernel(double, double);
extern "C" int Math_ReduceDoubleAngleByHalfPi(double, double*);
// Original: arm9/main @ 0x02008DCC; symbol: func_02008dcc; size: 0x170.
extern "C" double RuntimeCosine_EvaluateCosine(double value)
{
    double zero = 0.0;
    int high = ((int*)&value)[1] & 0x7fffffff;
    if (high <= 0x3fe921fb)
        return Runtime_ComputeCosineKernel(value, zero);
    if (high >= 0x7ff00000)
        return value - value;
    double reduced[2];
    int quadrant = Math_ReduceDoubleAngleByHalfPi(value, reduced);
    switch (quadrant & 3) {
    case 0:
        return Runtime_ComputeCosineKernel(reduced[0], reduced[1]);
    case 1:
        return -RuntimeSineKernel_EvaluateReducedSinePolynomial(reduced[0], reduced[1], 1);
    case 2:
        return -Runtime_ComputeCosineKernel(reduced[0], reduced[1]);
    default:
        return RuntimeSineKernel_EvaluateReducedSinePolynomial(reduced[0], reduced[1], 1);
    }
}
