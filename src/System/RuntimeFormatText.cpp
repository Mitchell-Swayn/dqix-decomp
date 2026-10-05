#include "System/RuntimeFormatText.h"

// Fixed-width spellings selected by the floating-point formatter, followed by
// the two separate empty-string fields referenced by the output engine.
// A single record preserves field order; original field symbols remain aliases.
RuntimeFormatText data_020eeef0 = {
    "0x0p0", "-INF", "-inf", "INF", "inf",
    "-NAN", "-nan", "NAN", "nan", {0, 0}, ""
};
