#include <globaldefs.h>
ARM
// Mirrors the current DecodePackedGlobalIdentifierFields owning projection.
struct Fields { unsigned long long a,b; unsigned short c,d; };
struct IdentifierState { unsigned long long identifier,other; int present; };
extern "C" void WfcUtility_DecodePersistentIdentifierFields(Fields*);
// Original: arm9/ov031 @ 0x0221C3F8; symbol: func_ov031_0221c3f8; size: 0x54.
// Copies the two decoded wide fields and marks whether the first identifier is present.
extern "C" void System_CopyDecodedIdentifierAndPresence(IdentifierState* output) {
 Fields fields;
 WfcUtility_DecodePersistentIdentifierFields(&fields);
 output->identifier=fields.a;
 output->other=fields.b;
 output->present=fields.a!=0;
}
