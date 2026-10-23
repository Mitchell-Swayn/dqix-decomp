#include <globaldefs.h>
ARM
#pragma force_active on

extern "C" int WfcUtility_GenerateMissingPersistentIdentifier(void *);
extern "C" int WfcUtility_WriteIdentifierHeaderToSettingsPages(void *, unsigned);
// Original: arm9/ov031 @ 0x0221C1C4; symbol: func_ov031_0221c1c4; size: 0x44.
// Generates a persistent identifier and returns whether its settings write succeeds.
extern "C" int WfcUtility_GenerateAndStorePersistentIdentifier(unsigned settings)
{
    unsigned identifier[5];
    if (!WfcUtility_GenerateMissingPersistentIdentifier(identifier)) return 0;
    return WfcUtility_WriteIdentifierHeaderToSettingsPages(identifier, settings) ? 1 : 0;
}
#pragma force_active reset
