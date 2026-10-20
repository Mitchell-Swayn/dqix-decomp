// Original data: arm9/ov000 @ 0x2183b5c; symbol: data_ov000_02183b5c.
// Combat resource script opcode dispatch. Registration at0216d1f4 calls Script::SetOpcodeLookup, which sorts eight-byte opcode/procedure records in place. Shared Script::OpcodeProc contract is int(Parameter*, int argumentCount). Opcode zero and null callback terminate the table.
// Initial values: hex 01000000f09b160202000000009d160203000000089d160204000000549e160205000000809e160206000000a49f16020700000018a0160208000000a4a11602 ...; full span in module reference.
// Observed span: 1120 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
#include <Resource/Script.h>
// Combat resource script opcode dispatch. Registration at0216d1f4 calls
// Script::SetOpcodeLookup, which sorts eight-byte opcode/procedure records in place.
// Shared Script::OpcodeProc contract is int(Parameter*, int argumentCount).
// Opcode zero and null callback terminate the table.
extern "C" {
int CombatScript_BeginActionKeyCommandGroup(Script::Parameter*, int);
int CombatScript_AcceptOpcode02(Script::Parameter*, int);
int Script_AllocateAndQueueStringRecord(Script::Parameter*, int);
int Resource_AllocateAndInitializeLinkedCoordinateEntry(Script::Parameter*, int);
int CombatScript_QueueFixedPointPairAndScalar(Script::Parameter*, int);
int CombatScript_QueueOpcode06FixedPointPair(Script::Parameter*, int);
int Script_AllocateTypeSevenHalfwordEntry(Script::Parameter*, int);
int AllocateScriptValueWithOptionalFlag(Script::Parameter*, int);
int CombatScript_QueueOpcode09TypedArguments(Script::Parameter*, int);
int AllocateScriptParameterRecord(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryForOpcode11(Script::Parameter*, int);
int Script_QueueTypedFloatVectorNode(Script::Parameter*, int);
int CombatScript_AcceptOpcode0D(Script::Parameter*, int);
int CombatScript_IgnoreOpcodeAndReturnTrue(Script::Parameter*, int);
int CombatScript_AcceptOpcode0F(Script::Parameter*, int);
int CombatScript_BeginDefaultActionKeyCommandGroup(Script::Parameter*, int);
int CombatScript_AcceptOpcode11(Script::Parameter*, int);
int Script_QueuePatchedStringNode(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryForOpcode19(Script::Parameter*, int);
int CombatScript_QueueCharacterPathWithOptionalSelector(Script::Parameter*, int);
int CombatScript_QueueOpcode15StringOrIndexedParameters(Script::Parameter*, int);
int AllocateScriptBytePairRecord(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryForOpcode23(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryForOpcode24(Script::Parameter*, int);
int Script_QueueIndexedFixedPointNode(Script::Parameter*, int);
int Script_AllocateTaggedFixedPointEntry(Script::Parameter*, int);
int Script_AllocateTaggedHalfwordEntry(Script::Parameter*, int);
int Script_AllocateTypeTwentyEightEntry(Script::Parameter*, int);
int Resource_ScriptAllocateAndSubmitType1DEntry(Script::Parameter*, int);
int Resource_ScriptQueueType1ERecord(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With1F(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With20(Script::Parameter*, int);
int Script_QueueCopiedStringNode(Script::Parameter*, int);
int CombatScript_QueueOpcode22CopiedString(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryWithCode23(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryWithCode24(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With25(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryWithCode26(Script::Parameter*, int);
int CombatScript_QueueOpcode27Byte(Script::Parameter*, int);
int CombatScript_QueueOpcode28BiasedSelector(Script::Parameter*, int);
int Script_AllocateType29BytePairEntry(Script::Parameter*, int);
int Resource_ScriptQueueType42VectorRecord(Script::Parameter*, int);
int Resource_ScriptQueueType2BRecord(Script::Parameter*, int);
int Resource_AllocateType0x2CEntryFromScriptParameters(Script::Parameter*, int);
int CombatScript_QueueOpcode2D(Script::Parameter*, int);
int Script_AllocateTypeFortySixRecordWithOptionalString(Script::Parameter*, int);
int CombatScript_QueueBytePairAndHalfword(Script::Parameter*, int);
int CombatScript_QueueOpcode30FixedPointVector(Script::Parameter*, int);
int Script_QueueType49CoordinateNode(Script::Parameter*, int);
int Script_AllocateType50VectorOptionalByteEntry(Script::Parameter*, int);
int CombatScript_QueueOpcode33OptionalCopiedString(Script::Parameter*, int);
int CombatScript_QueueOpcode34BytePair(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryWithCode35(Script::Parameter*, int);
int CombatScript_QueueOpcode15ExplicitStringParameters(Script::Parameter*, int);
int Script_QueueCommand37WithOptionalValues(Script::Parameter*, int);
int Ov000_AllocateAndInitializeLinkedEntry(Script::Parameter*, int);
int AllocateScriptHalfwordRecord(Script::Parameter*, int);
int Script_AllocateTaggedIntegerEntry3A(Script::Parameter*, int);
int Resource_ScriptQueueType3BWithCopiedString(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryWithCode3C(Script::Parameter*, int);
int Combat_AllocateAndRegisterOwnerEntryWithCode3D(Script::Parameter*, int);
int CombatScript_QueueValue3EEntry(Script::Parameter*, int);
int Script_AllocateCoordinateHalfwordEntry(Script::Parameter*, int);
int CombatScript_TryQueueOpcode40Integer(Script::Parameter*, int);
int CombatScript_TryQueueOpcode41Integer(Script::Parameter*, int);
int Network_AllocateAndEnqueueTypeSixtySixNode(Script::Parameter*, int);
int CombatScript_QueueValue43Entry(Script::Parameter*, int);
int CombatScript_TryQueueOpcode44Integer(Script::Parameter*, int);
int CombatScript_TryQueueOpcode45HalfwordPair(Script::Parameter*, int);
int Resource_AllocateType0x46EntryFromScriptInteger(Script::Parameter*, int);
int Script_AllocateTaggedHalfwordEntry47(Script::Parameter*, int);
int CombatScript_TryQueueOpcode48Integer(Script::Parameter*, int);
int CombatScript_QueueValue49Entry(Script::Parameter*, int);
int CombatScript_QueueValue4AEntry(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With4B(Script::Parameter*, int);
int Script_TryAllocateTypedParameterEntry(Script::Parameter*, int);
int CreateScriptFixedPointOpcode4DEntry(Script::Parameter*, int);
int Script_AllocateType4EIntegerEntry(Script::Parameter*, int);
int Script_AllocateTypeSeventyNineBitfieldRecord(Script::Parameter*, int);
int Resource_ScriptQueueType50FixedPointAndIntegerRecord(Script::Parameter*, int);
int CombatScript_QueueOpcode54FixedPointHalfword(Script::Parameter*, int);
int CombatScript_QueueValue55Entry(Script::Parameter*, int);
int CombatScript_QueueVectorAndFixedPointScalars(Script::Parameter*, int);
int CombatScript_QueueOpcode57FixedPointHalfword(Script::Parameter*, int);
int Script_AllocateVectorAndThreeFixedPointScalars(Script::Parameter*, int);
int Script_QueueTwoVectorCommand59(Script::Parameter*, int);
int CombatScript_QueueOpcode5AByte(Script::Parameter*, int);
int Script_QueueOptionalStringNode(Script::Parameter*, int);
int Network_AllocateAndEnqueueTypeNinetyTwoNode(Script::Parameter*, int);
int Script_AllocateType5DHalfwordEntry(Script::Parameter*, int);
int Network_AllocateAndEnqueueTypeNinetyFourNode(Script::Parameter*, int);
int CombatScript_QueueOpcode5FInteger(Script::Parameter*, int);
int Resource_ScriptQueueType60FixedPointAndIntegerRecord(Script::Parameter*, int);
int Script_AllocateTypeNinetySevenEntry(Script::Parameter*, int);
int CombatScript_QueueValue62Entry(Script::Parameter*, int);
int CombatScript_QueueValue63Entry(Script::Parameter*, int);
int Resource_AllocateType100ScriptCommand(Script::Parameter*, int);
int CombatScript_QueueValue65Entry(Script::Parameter*, int);
int Script_AllocateTaggedHalfwordIntEntry(Script::Parameter*, int);
int CombatScript_QueueOpcode67(Script::Parameter*, int);
int Script_AllocateTwoHalfwordParameterEntry(Script::Parameter*, int);
int CombatScript_QueueValue69Entry(Script::Parameter*, int);
int Script_AllocateTypedParameterEntry(Script::Parameter*, int);
int AllocateScriptIntegerRecord(Script::Parameter*, int);
int Script_AllocateTaggedByteAndHalfwordEntry(Script::Parameter*, int);
int CombatScript_QueueOpcode6DHalfword(Script::Parameter*, int);
int Script_AllocateTaggedHalfwordEntry6E(Script::Parameter*, int);
int CombatScript_QueueValue6FEntry(Script::Parameter*, int);
int Script_TryAllocateOptionalHalfwordEntry(Script::Parameter*, int);
int Script_AllocateScaledFloatParameterEntry(Script::Parameter*, int);
int Script_AllocateTypeOneHundredFourteenEntry(Script::Parameter*, int);
int Resource_AllocateType115ScriptCommand(Script::Parameter*, int);
int CombatScript_TryQueueFixedPointAndIntegerPair(Script::Parameter*, int);
int CombatScript_QueueOpcode79Byte(Script::Parameter*, int);
int Network_AllocateAndEnqueueTypeNinetyEightNode(Script::Parameter*, int);
int CombatScript_QueueModeSelectedHalfwordPair(Script::Parameter*, int);
int Script_QueueOpcode76FixedPointParameters(Script::Parameter*, int);
int Script_AllocateBooleanParameterEntry(Script::Parameter*, int);
int CombatScript_QueueOpcode78Boolean(Script::Parameter*, int);
int CombatScript_QueueOptionalFixedPointWithDefault(Script::Parameter*, int);
int CreateScriptOpcode7CEntry(Script::Parameter*, int);
int Ov000_AllocateOptionalLinkedEntry(Script::Parameter*, int);
int CombatScript_QueueOpcode7E(Script::Parameter*, int);
int AllocateScriptFixedPointRecord(Script::Parameter*, int);
int CreateScriptOpcode80Entry(Script::Parameter*, int);
int CombatScript_QueueValue81Entry(Script::Parameter*, int);
int Script_AllocateType82ConditionalByteEntry(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With83(Script::Parameter*, int);
int Script_AllocateTypeOneHundredThirtyTwoEntry(Script::Parameter*, int);
int CombatScript_QueueValue85Entry(Script::Parameter*, int);
int CombatScript_QueueOpcode86(Script::Parameter*, int);
int CombatScript_QueueOpcode87(Script::Parameter*, int);
int CombatScript_QueueOpcode88(Script::Parameter*, int);
int CombatScript_QueueOpcode89(Script::Parameter*, int);
int Script_AllocateTypeOneHundredThirtyEightVectorEntry(Script::Parameter*, int);
int Ov000_AllocateConditionalLinkedEntry(Script::Parameter*, int);
int Script_QueueFixedRadianCommand8C(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With8D(Script::Parameter*, int);
int CombatScript_QueueOpcode8E(Script::Parameter*, int);
Script::OpcodeLookupEntry CombatScriptCompileBufferToCommandGroups_CombatResourceScriptOpcodeDispatch[140] = {
    {1, CombatScript_BeginActionKeyCommandGroup},
    {2, CombatScript_AcceptOpcode02},
    {3, Script_AllocateAndQueueStringRecord},
    {4, Resource_AllocateAndInitializeLinkedCoordinateEntry},
    {5, CombatScript_QueueFixedPointPairAndScalar},
    {6, CombatScript_QueueOpcode06FixedPointPair},
    {7, Script_AllocateTypeSevenHalfwordEntry},
    {8, AllocateScriptValueWithOptionalFlag},
    {9, CombatScript_QueueOpcode09TypedArguments},
    {10, AllocateScriptParameterRecord},
    {11, Combat_AllocateAndRegisterOwnerEntryForOpcode11},
    {12, Script_QueueTypedFloatVectorNode},
    {13, CombatScript_AcceptOpcode0D},
    {14, CombatScript_IgnoreOpcodeAndReturnTrue},
    {15, CombatScript_AcceptOpcode0F},
    {16, CombatScript_BeginDefaultActionKeyCommandGroup},
    {17, CombatScript_AcceptOpcode11},
    {18, Script_QueuePatchedStringNode},
    {19, Combat_AllocateAndRegisterOwnerEntryForOpcode19},
    {20, CombatScript_QueueCharacterPathWithOptionalSelector},
    {21, CombatScript_QueueOpcode15StringOrIndexedParameters},
    {22, AllocateScriptBytePairRecord},
    {23, Combat_AllocateAndRegisterOwnerEntryForOpcode23},
    {24, Combat_AllocateAndRegisterOwnerEntryForOpcode24},
    {25, Script_QueueIndexedFixedPointNode},
    {26, Script_AllocateTaggedFixedPointEntry},
    {27, Script_AllocateTaggedHalfwordEntry},
    {28, Script_AllocateTypeTwentyEightEntry},
    {29, Resource_ScriptAllocateAndSubmitType1DEntry},
    {30, Resource_ScriptQueueType1ERecord},
    {31, CombatScript_InvokeHandler02169bb4With1F},
    {32, CombatScript_InvokeHandler02169bb4With20},
    {33, Script_QueueCopiedStringNode},
    {34, CombatScript_QueueOpcode22CopiedString},
    {35, Combat_AllocateAndRegisterOwnerEntryWithCode23},
    {36, Combat_AllocateAndRegisterOwnerEntryWithCode24},
    {37, CombatScript_InvokeHandler02169bb4With25},
    {38, Combat_AllocateAndRegisterOwnerEntryWithCode26},
    {39, CombatScript_QueueOpcode27Byte},
    {40, CombatScript_QueueOpcode28BiasedSelector},
    {41, Script_AllocateType29BytePairEntry},
    {42, Resource_ScriptQueueType42VectorRecord},
    {43, Resource_ScriptQueueType2BRecord},
    {44, Resource_AllocateType0x2CEntryFromScriptParameters},
    {45, CombatScript_QueueOpcode2D},
    {46, Script_AllocateTypeFortySixRecordWithOptionalString},
    {47, CombatScript_QueueBytePairAndHalfword},
    {48, CombatScript_QueueOpcode30FixedPointVector},
    {49, Script_QueueType49CoordinateNode},
    {50, Script_AllocateType50VectorOptionalByteEntry},
    {51, CombatScript_QueueOpcode33OptionalCopiedString},
    {52, CombatScript_QueueOpcode34BytePair},
    {53, Combat_AllocateAndRegisterOwnerEntryWithCode35},
    {54, CombatScript_QueueOpcode15ExplicitStringParameters},
    {55, Script_QueueCommand37WithOptionalValues},
    {56, Ov000_AllocateAndInitializeLinkedEntry},
    {57, AllocateScriptHalfwordRecord},
    {58, Script_AllocateTaggedIntegerEntry3A},
    {59, Resource_ScriptQueueType3BWithCopiedString},
    {60, Combat_AllocateAndRegisterOwnerEntryWithCode3C},
    {61, Combat_AllocateAndRegisterOwnerEntryWithCode3D},
    {62, CombatScript_QueueValue3EEntry},
    {63, Script_AllocateCoordinateHalfwordEntry},
    {64, CombatScript_TryQueueOpcode40Integer},
    {65, CombatScript_TryQueueOpcode41Integer},
    {66, Network_AllocateAndEnqueueTypeSixtySixNode},
    {67, CombatScript_QueueValue43Entry},
    {68, CombatScript_TryQueueOpcode44Integer},
    {69, CombatScript_TryQueueOpcode45HalfwordPair},
    {70, Resource_AllocateType0x46EntryFromScriptInteger},
    {71, Script_AllocateTaggedHalfwordEntry47},
    {72, CombatScript_TryQueueOpcode48Integer},
    {73, CombatScript_QueueValue49Entry},
    {74, CombatScript_QueueValue4AEntry},
    {75, CombatScript_InvokeHandler02169bb4With4B},
    {76, Script_TryAllocateTypedParameterEntry},
    {77, CreateScriptFixedPointOpcode4DEntry},
    {78, Script_AllocateType4EIntegerEntry},
    {79, Script_AllocateTypeSeventyNineBitfieldRecord},
    {80, Resource_ScriptQueueType50FixedPointAndIntegerRecord},
    {84, CombatScript_QueueOpcode54FixedPointHalfword},
    {85, CombatScript_QueueValue55Entry},
    {86, CombatScript_QueueVectorAndFixedPointScalars},
    {87, CombatScript_QueueOpcode57FixedPointHalfword},
    {88, Script_AllocateVectorAndThreeFixedPointScalars},
    {89, Script_QueueTwoVectorCommand59},
    {90, CombatScript_QueueOpcode5AByte},
    {91, Script_QueueOptionalStringNode},
    {92, Network_AllocateAndEnqueueTypeNinetyTwoNode},
    {93, Script_AllocateType5DHalfwordEntry},
    {94, Network_AllocateAndEnqueueTypeNinetyFourNode},
    {95, CombatScript_QueueOpcode5FInteger},
    {96, Resource_ScriptQueueType60FixedPointAndIntegerRecord},
    {97, Script_AllocateTypeNinetySevenEntry},
    {98, CombatScript_QueueValue62Entry},
    {99, CombatScript_QueueValue63Entry},
    {100, Resource_AllocateType100ScriptCommand},
    {101, CombatScript_QueueValue65Entry},
    {102, Script_AllocateTaggedHalfwordIntEntry},
    {103, CombatScript_QueueOpcode67},
    {104, Script_AllocateTwoHalfwordParameterEntry},
    {105, CombatScript_QueueValue69Entry},
    {106, Script_AllocateTypedParameterEntry},
    {107, AllocateScriptIntegerRecord},
    {108, Script_AllocateTaggedByteAndHalfwordEntry},
    {109, CombatScript_QueueOpcode6DHalfword},
    {110, Script_AllocateTaggedHalfwordEntry6E},
    {111, CombatScript_QueueValue6FEntry},
    {112, Script_TryAllocateOptionalHalfwordEntry},
    {113, Script_AllocateScaledFloatParameterEntry},
    {114, Script_AllocateTypeOneHundredFourteenEntry},
    {115, Resource_AllocateType115ScriptCommand},
    {116, CombatScript_TryQueueFixedPointAndIntegerPair},
    {117, CombatScript_QueueModeSelectedHalfwordPair},
    {118, Script_QueueOpcode76FixedPointParameters},
    {119, Script_AllocateBooleanParameterEntry},
    {120, CombatScript_QueueOpcode78Boolean},
    {121, CombatScript_QueueOpcode79Byte},
    {122, Network_AllocateAndEnqueueTypeNinetyEightNode},
    {123, CombatScript_QueueOptionalFixedPointWithDefault},
    {124, CreateScriptOpcode7CEntry},
    {125, Ov000_AllocateOptionalLinkedEntry},
    {126, CombatScript_QueueOpcode7E},
    {127, AllocateScriptFixedPointRecord},
    {128, CreateScriptOpcode80Entry},
    {129, CombatScript_QueueValue81Entry},
    {130, Script_AllocateType82ConditionalByteEntry},
    {131, CombatScript_InvokeHandler02169bb4With83},
    {132, Script_AllocateTypeOneHundredThirtyTwoEntry},
    {133, CombatScript_QueueValue85Entry},
    {134, CombatScript_QueueOpcode86},
    {135, CombatScript_QueueOpcode87},
    {136, CombatScript_QueueOpcode88},
    {137, CombatScript_QueueOpcode89},
    {138, Script_AllocateTypeOneHundredThirtyEightVectorEntry},
    {139, Ov000_AllocateConditionalLinkedEntry},
    {140, Script_QueueFixedRadianCommand8C},
    {141, CombatScript_InvokeHandler02169bb4With8D},
    {142, CombatScript_QueueOpcode8E},
    {0, 0},
};
}
