// Original data: arm9/main @ 0x20eeef0; symbol: data_020eeef0.
// RuntimeFormatText stores fixed-width hexadecimal zero, infinity and NaN spellings plus empty-string fields. Interior aliases address the individual fields.
#include "System/RuntimeFormatText.h"

// Fixed-width spellings selected by the floating-point formatter, followed by
// the two separate empty-string fields referenced by the output engine.
// A single record preserves field order; original field symbols remain aliases.
RuntimeFormatText Runtime_FloatingPointSpellings = {
    "0x0p0", "-INF", "-inf", "INF", "inf",
    "-NAN", "-nan", "NAN", "nan", {0, 0}, ""
};
