#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02207E90; symbol: func_ov031_02207e90; size: 0x80.
extern "C" unsigned int Util_ParsePackedDate(const unsigned char *p, int format) {
    unsigned int year = p[0] * 10 + p[1] - 528;
    p += 2;
    unsigned int fullYear;
    if (format == 23) {
        if (year < 50) fullYear = year + 2000;
        else fullYear = year + 1900;
    } else {
        fullYear = year * 100 + (p[0] * 10 + p[1] - 528);
        p += 2;
    }
    unsigned int month = p[0] * 10 + p[1];
    p += 2;
    unsigned int day = p[0] * 10 + p[1];
    unsigned int result = (fullYear << 16) + ((month - 528) << 8);
    return result + (day - 528);
}
