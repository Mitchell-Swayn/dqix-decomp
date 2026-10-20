#include <globaldefs.h>

extern "C" int rand(void);
extern "C" int _dfix(double);

// Original: arm9/main @ 0x02032370; symbol: func_02032370; size: 0x54.
extern "C" void Random_ScaleIntegerByRandFraction(int value, int, int, int)
{
    int random = rand();
    double converted = (double)value;
    double factor = (double)(random - 1) / 32767.0;
    double result = converted * factor;
    (void)_dfix(result);
}
