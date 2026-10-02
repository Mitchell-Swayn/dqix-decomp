#include "System/RuntimeLocale.h"

// C-locale formats and paired abbreviated/full weekday and month names.
// Fixed array extents preserve original trailing zero padding.
char data_020eed34[12] = "%I:%M:%S %p";
char data_020eed40[16] = "%a %b %e %T %Y";
char data_020eed50[88] =
    "Sun|Sunday|Mon|Monday|Tue|Tuesday|Wed|Wednesday|Thu|Thursday|Fri|Friday|Sat|Saturday";
char data_020eeda8[136] =
    "Jan|January|Feb|February|Mar|March|Apr|April|May|May|Jun|June|Jul|July|Aug|August|"
    "Sep|September|Oct|October|Nov|November|Dec|December";

// The locale auxiliary descriptor points to this 16-bit character-order table.
unsigned short data_020eee30[96] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
    33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 17, 18, 19, 20, 21, 22,
    23, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71,
    73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 24, 25, 26, 27, 28,
    0, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72,
    74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 29, 30, 31, 32, 0,
};
