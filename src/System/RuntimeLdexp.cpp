#pragma optimize_for_size off
extern "C" double func_0200911c(double, int*);
extern "C" double func_020091d8(double, int);
extern "C" double func_0200aae4(double value, int shift)
{
    int exponent;
    value = func_0200911c(value, &exponent);
    exponent += shift;
    return func_020091d8(value, exponent);
}
