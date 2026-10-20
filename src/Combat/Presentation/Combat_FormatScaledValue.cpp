#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef520; symbol: data_ov025_021ef520.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 64f41e02dbf41e02f2f41e0209f51e02aff41e02c5f41e02.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" const char *CombatFormatScaledValue_UnknownRoleDataReferences[];
extern "C" int sprintf(char *, const char *, ...);
// Original: arm9/ov025 @ 0x021E278C; symbol: func_ov025_021e278c; size: 0x3C.
extern "C" int Combat_FormatScaledValue(int value, char *buffer) {
    int quotient = value / 1000000;
    int remainder = value - quotient * 1000000;
    return sprintf(buffer, CombatFormatScaledValue_UnknownRoleDataReferences[quotient], remainder);
}
