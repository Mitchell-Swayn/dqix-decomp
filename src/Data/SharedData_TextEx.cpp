// Original data: arm9/ov025 @ 0x21ef89a; symbol: data_ov025_021ef89a.
// Source-defined character literal. Text: "ex". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "ex".
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
#include <globaldefs.h>
// Combat action/resource identifier, path or formatting text.
// Exact fixed storage preserves original zero padding.
extern "C" {
__declspec(align(1)) char SharedData_TextEx[3] = "ex";
}
