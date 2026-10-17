#pragma optimize_for_size off

// Binary64 words and polynomial evaluation order follow the ARM runtime ABI.
// Original: arm9/main @ 0x020085CC; symbol: func_020085cc; size: 0x27C.
extern "C" double RuntimeSineKernel_EvaluateReducedSinePolynomial(double x, double y, int tail)
{
    int high = ((int*)&x)[1] & 0x7fffffff;
    if (high < 0x3e400000) {
        if ((int)x == 0)
            return x;
    }
    double z = x * x;
    double v = z * x;
    double r = 0.00833333333332249
        + z * (-0.0001984126982985795
        + z * (2.7557313707070068e-06
        + z * (-2.5050760253406863e-08 + 1.58969099521155e-10 * z)));
    if (tail == 0)
        return x + v * (-0.16666666666666632 + z * r);
    return x - ((z * (0.5 * y - v * r) - y) - -0.16666666666666632 * v);
}
