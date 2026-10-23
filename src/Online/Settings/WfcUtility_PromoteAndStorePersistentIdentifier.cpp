#include <globaldefs.h>
ARM
#pragma force_active on

typedef unsigned long long IdentifierWords;
struct IdentifierHeader { IdentifierWords current, candidate; unsigned short counter, check; };
extern "C" void WfcUtility_DecodePersistentIdentifierFields(IdentifierHeader *);
extern "C" int WfcUtility_WriteIdentifierHeaderToSettingsPages(IdentifierHeader *, unsigned);
// Original: arm9/ov031 @ 0x0221C208; symbol: func_ov031_0221c208; size: 0x50.
// Promotes the candidate identifier, replaces it with the stored candidate and writes the settings header.
extern "C" int WfcUtility_PromoteAndStorePersistentIdentifier(IdentifierHeader *identifier, unsigned settings)
{
    IdentifierHeader stored;
    WfcUtility_DecodePersistentIdentifierFields(&stored);
    identifier->current = identifier->candidate;
    identifier->candidate = stored.candidate;
    return WfcUtility_WriteIdentifierHeaderToSettingsPages(identifier, settings) ? 1 : 0;
}
#pragma force_active reset
