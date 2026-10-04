#pragma optimize_for_size off

// Binary64 words and polynomial evaluation order follow the ARM runtime ABI.
extern "C" double func_020076f0(double x, double y)
{
    int high = ((int*)&x)[1] & 0x7fffffff;
    if (high < 0x3e400000) {
        if ((int)x == 0)
            return 1.0;
    }
    double z = x * x;
    double r = z * (0.0416666666666666
        + z * (-0.001388888888887411
        + z * (2.480158728947673e-05
        + z * (-2.7557314351390663e-07
        + z * (2.087572321298175e-09 + -1.1359647557788195e-11 * z)))));
    if (high < 0x3fd33333)
        return 1.0 - (0.5 * z - (z * r - x * y));
    double qx;
    if (high > 0x3fe90000)
        qx = 0.28125;
    else {
        ((int*)&qx)[1] = high - 0x00200000;
        ((int*)&qx)[0] = 0;
    }
    double hz = 0.5 * z - qx;
    double a = 1.0 - qx;
    return a - (hz - (z * r - x * y));
}
