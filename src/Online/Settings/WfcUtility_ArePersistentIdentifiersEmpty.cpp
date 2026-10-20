#include <globaldefs.h>
ARM
// Fields mirrors the existing owning definition in DecodePackedGlobalIdentifierFields.cpp.
struct Fields { unsigned long long a,b; unsigned short c,d; };
extern "C" void WfcUtility_DecodePersistentIdentifierFields(Fields*);
// Original: arm9/ov031 @ 0x0221C44C; symbol: func_ov031_0221c44c; size: 0x50.
// Tests the two decoded 64-bit fields; the trailing halfword fields are ignored.
extern "C" int WfcUtility_ArePersistentIdentifiersEmpty()
{
 Fields fields;
 WfcUtility_DecodePersistentIdentifierFields(&fields);
 if(fields.b==0){if(fields.a==0)return 1;}
 return 0;
}
