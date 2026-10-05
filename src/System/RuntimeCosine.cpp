#pragma optimize_for_size off

// Binary64 words and polynomial evaluation order follow the ARM runtime ABI.
extern "C" double func_020085cc(double, double, int);
extern "C" double func_020076f0(double, double);
extern "C" int func_02007028(double, double*);
extern "C" double func_02008dcc(double value)
{
    double zero = 0.0;
    int high = ((int*)&value)[1] & 0x7fffffff;
    if (high <= 0x3fe921fb)
        return func_020076f0(value, zero);
    if (high >= 0x7ff00000)
        return value - value;
    double reduced[2];
    int quadrant = func_02007028(value, reduced);
    switch (quadrant & 3) {
    case 0:
        return func_020076f0(reduced[0], reduced[1]);
    case 1:
        return -func_020085cc(reduced[0], reduced[1], 1);
    case 2:
        return -func_020076f0(reduced[0], reduced[1]);
    default:
        return func_020085cc(reduced[0], reduced[1], 1);
    }
}
