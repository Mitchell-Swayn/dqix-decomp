// Original data: arm9/ov017 @ 0x21d73d8; symbol: data_ov017_021d73d8.
// Four floating point 180/30 bounds used by field resource setup.
// Observed values: hex 00003443000034430000f0410000f041.
// Span: 16 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Four floating point 180/30 bounds used by field resource setup.
extern "C" {
float ProgramData_ResourceSetupBounds[4] = { 180.0f, 180.0f, 30.0f, 30.0f };
}
