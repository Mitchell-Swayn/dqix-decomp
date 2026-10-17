#include <Resource/Script.h>
// Combat resource script opcode dispatch. Registration at0216d1f4 calls
// Script::SetOpcodeLookup, which sorts eight-byte opcode/procedure records in place.
// Shared Script::OpcodeProc contract is int(Parameter*, int argumentCount).
// Opcode zero and null callback terminate the table.
extern "C" {
int func_ov000_02169bf0(Script::Parameter*, int);
int func_ov000_02169d00(Script::Parameter*, int);
int Script_AllocateAndQueueStringRecord(Script::Parameter*, int);
int Resource_AllocateAndInitializeLinkedCoordinateEntry(Script::Parameter*, int);
int func_ov000_02169e80(Script::Parameter*, int);
int Script_AllocateTypeSixEntryFromFloats(Script::Parameter*, int);
int Script_AllocateTypeSevenHalfwordEntry(Script::Parameter*, int);
int AllocateScriptValueWithOptionalFlag(Script::Parameter*, int);
int func_ov000_0216a208(Script::Parameter*, int);
int AllocateScriptParameterRecord(Script::Parameter*, int);
int func_ov000_0216a350(Script::Parameter*, int);
int Script_QueueTypedFloatVectorNode(Script::Parameter*, int);
int func_ov000_0216a420(Script::Parameter*, int);
int CombatScript_IgnoreOpcodeAndReturnTrue(Script::Parameter*, int);
int func_ov000_0216a430(Script::Parameter*, int);
int func_ov000_0216a438(Script::Parameter*, int);
int func_ov000_0216a4c0(Script::Parameter*, int);
int Script_QueuePatchedStringNode(Script::Parameter*, int);
int func_ov000_0216a55c(Script::Parameter*, int);
int func_ov000_0216a570(Script::Parameter*, int);
int func_ov000_0216a68c(Script::Parameter*, int);
int AllocateScriptBytePairRecord(Script::Parameter*, int);
int func_ov000_0216a934(Script::Parameter*, int);
int func_ov000_0216a948(Script::Parameter*, int);
int Script_QueueIndexedFixedPointNode(Script::Parameter*, int);
int func_ov000_0216a9dc(Script::Parameter*, int);
int Script_AllocateTaggedHalfwordEntry(Script::Parameter*, int);
int Script_AllocateTypeTwentyEightEntry(Script::Parameter*, int);
int Resource_ScriptAllocateAndSubmitType1DEntry(Script::Parameter*, int);
int Resource_ScriptQueueType1ERecord(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With1F(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With20(Script::Parameter*, int);
int Script_QueueCopiedStringNode(Script::Parameter*, int);
int Script_CreateTag22RecordFromStringParameter(Script::Parameter*, int);
int func_ov000_0216ad7c(Script::Parameter*, int);
int func_ov000_0216ad90(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With25(Script::Parameter*, int);
int func_ov000_0216adb8(Script::Parameter*, int);
int Script_AllocateType39EntryFromParameter(Script::Parameter*, int);
int Script_AllocateType40EntryFromParameterMinus26(Script::Parameter*, int);
int Script_AllocateType29BytePairEntry(Script::Parameter*, int);
int Resource_ScriptQueueType42VectorRecord(Script::Parameter*, int);
int Resource_ScriptQueueType2BRecord(Script::Parameter*, int);
int func_ov000_0216b110(Script::Parameter*, int);
int Ov000_ApplyValue2DAndReturnOne(Script::Parameter*, int);
int Script_AllocateTypeFortySixRecordWithOptionalString(Script::Parameter*, int);
int Script_AllocateTaggedBytePairHalfwordEntry(Script::Parameter*, int);
int func_ov000_0216b26c(Script::Parameter*, int);
int func_ov000_0216b2bc(Script::Parameter*, int);
int func_ov000_0216b328(Script::Parameter*, int);
int CreateAllocatedStringParameterRecord(Script::Parameter*, int);
int Resource_ScriptAllocateAndSubmitType34Entry(Script::Parameter*, int);
int func_ov000_0216b464(Script::Parameter*, int);
int func_ov000_0216b478(Script::Parameter*, int);
int Script_QueueCommand37WithOptionalValues(Script::Parameter*, int);
int Ov000_AllocateAndInitializeLinkedEntry(Script::Parameter*, int);
int AllocateScriptHalfwordRecord(Script::Parameter*, int);
int Script_AllocateTaggedIntegerEntry3A(Script::Parameter*, int);
int Resource_ScriptQueueType3BWithCopiedString(Script::Parameter*, int);
int func_ov000_0216b870(Script::Parameter*, int);
int func_ov000_0216b884(Script::Parameter*, int);
int func_ov000_0216b898(Script::Parameter*, int);
int Script_AllocateCoordinateHalfwordEntry(Script::Parameter*, int);
int Resource_ScriptAllocateAndSubmitType40Entry(Script::Parameter*, int);
int func_ov000_0216b954(Script::Parameter*, int);
int Network_AllocateAndEnqueueTypeSixtySixNode(Script::Parameter*, int);
int func_ov000_0216ba00(Script::Parameter*, int);
int Resource_AllocateScriptType44Entry(Script::Parameter*, int);
int Script_AllocateType69EntryWithTwoIntegers(Script::Parameter*, int);
int func_ov000_0216bac8(Script::Parameter*, int);
int Script_AllocateTaggedHalfwordEntry47(Script::Parameter*, int);
int Script_AllocateAndInitializeType48Record(Script::Parameter*, int);
int func_ov000_0216bbc4(Script::Parameter*, int);
int func_ov000_0216bbd8(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With4B(Script::Parameter*, int);
int Script_TryAllocateTypedParameterEntry(Script::Parameter*, int);
int func_ov000_0216bc54(Script::Parameter*, int);
int Script_AllocateType4EIntegerEntry(Script::Parameter*, int);
int Script_AllocateTypeSeventyNineBitfieldRecord(Script::Parameter*, int);
int func_ov000_0216bd9c(Script::Parameter*, int);
int Script_AllocateType84EntryFromFloatParameter(Script::Parameter*, int);
int func_ov000_0216be58(Script::Parameter*, int);
int func_ov000_0216be6c(Script::Parameter*, int);
int func_ov000_0216bf40(Script::Parameter*, int);
int Script_AllocateVectorAndThreeFixedPointScalars(Script::Parameter*, int);
int Script_QueueTwoVectorCommand59(Script::Parameter*, int);
int func_ov000_0216c0f4(Script::Parameter*, int);
int Script_QueueOptionalStringNode(Script::Parameter*, int);
int Network_AllocateAndEnqueueTypeNinetyTwoNode(Script::Parameter*, int);
int Script_AllocateType5DHalfwordEntry(Script::Parameter*, int);
int Network_AllocateAndEnqueueTypeNinetyFourNode(Script::Parameter*, int);
int func_ov000_0216c2c4(Script::Parameter*, int);
int func_ov000_0216c314(Script::Parameter*, int);
int Script_AllocateTypeNinetySevenEntry(Script::Parameter*, int);
int func_ov000_0216c3ec(Script::Parameter*, int);
int func_ov000_0216c400(Script::Parameter*, int);
int Resource_AllocateType100ScriptCommand(Script::Parameter*, int);
int func_ov000_0216c490(Script::Parameter*, int);
int Script_AllocateTaggedHalfwordIntEntry(Script::Parameter*, int);
int Ov000_ApplyValue67AndReturnOne(Script::Parameter*, int);
int Script_AllocateTwoHalfwordParameterEntry(Script::Parameter*, int);
int func_ov000_0216c570(Script::Parameter*, int);
int Script_AllocateTypedParameterEntry(Script::Parameter*, int);
int AllocateScriptIntegerRecord(Script::Parameter*, int);
int Script_AllocateTaggedByteAndHalfwordEntry(Script::Parameter*, int);
int func_ov000_0216c680(Script::Parameter*, int);
int Script_AllocateTaggedHalfwordEntry6E(Script::Parameter*, int);
int func_ov000_0216c720(Script::Parameter*, int);
int Script_TryAllocateOptionalHalfwordEntry(Script::Parameter*, int);
int Script_AllocateScaledFloatParameterEntry(Script::Parameter*, int);
int Script_AllocateTypeOneHundredFourteenEntry(Script::Parameter*, int);
int Resource_AllocateType115ScriptCommand(Script::Parameter*, int);
int func_ov000_0216c8e4(Script::Parameter*, int);
int func_ov000_0216c95c(Script::Parameter*, int);
int Network_AllocateAndEnqueueTypeNinetyEightNode(Script::Parameter*, int);
int func_ov000_0216c9fc(Script::Parameter*, int);
int Script_QueueOpcode76FixedPointParameters(Script::Parameter*, int);
int Script_AllocateBooleanParameterEntry(Script::Parameter*, int);
int func_ov000_0216ccd8(Script::Parameter*, int);
int Script_AllocateScaledFloatEntry(Script::Parameter*, int);
int func_ov000_0216cd90(Script::Parameter*, int);
int Ov000_AllocateOptionalLinkedEntry(Script::Parameter*, int);
int Util_CallFunctionWithConstant7E(Script::Parameter*, int);
int AllocateScriptFixedPointRecord(Script::Parameter*, int);
int func_ov000_0216cec0(Script::Parameter*, int);
int func_ov000_0216cf04(Script::Parameter*, int);
int Script_AllocateType82ConditionalByteEntry(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With83(Script::Parameter*, int);
int Script_AllocateTypeOneHundredThirtyTwoEntry(Script::Parameter*, int);
int func_ov000_0216cfd4(Script::Parameter*, int);
int func_ov000_0216cfe8(Script::Parameter*, int);
int Ov000_ApplyValue87AndReturnOne(Script::Parameter*, int);
int func_ov000_0216d010(Script::Parameter*, int);
int func_ov000_0216d024(Script::Parameter*, int);
int Script_AllocateTypeOneHundredThirtyEightVectorEntry(Script::Parameter*, int);
int Ov000_AllocateConditionalLinkedEntry(Script::Parameter*, int);
int Script_QueueFixedRadianCommand8C(Script::Parameter*, int);
int CombatScript_InvokeHandler02169bb4With8D(Script::Parameter*, int);
int func_ov000_0216d1b0(Script::Parameter*, int);
Script::OpcodeLookupEntry data_ov000_02183b5c[140] = {
    {1, func_ov000_02169bf0},
    {2, func_ov000_02169d00},
    {3, Script_AllocateAndQueueStringRecord},
    {4, Resource_AllocateAndInitializeLinkedCoordinateEntry},
    {5, func_ov000_02169e80},
    {6, Script_AllocateTypeSixEntryFromFloats},
    {7, Script_AllocateTypeSevenHalfwordEntry},
    {8, AllocateScriptValueWithOptionalFlag},
    {9, func_ov000_0216a208},
    {10, AllocateScriptParameterRecord},
    {11, func_ov000_0216a350},
    {12, Script_QueueTypedFloatVectorNode},
    {13, func_ov000_0216a420},
    {14, CombatScript_IgnoreOpcodeAndReturnTrue},
    {15, func_ov000_0216a430},
    {16, func_ov000_0216a438},
    {17, func_ov000_0216a4c0},
    {18, Script_QueuePatchedStringNode},
    {19, func_ov000_0216a55c},
    {20, func_ov000_0216a570},
    {21, func_ov000_0216a68c},
    {22, AllocateScriptBytePairRecord},
    {23, func_ov000_0216a934},
    {24, func_ov000_0216a948},
    {25, Script_QueueIndexedFixedPointNode},
    {26, func_ov000_0216a9dc},
    {27, Script_AllocateTaggedHalfwordEntry},
    {28, Script_AllocateTypeTwentyEightEntry},
    {29, Resource_ScriptAllocateAndSubmitType1DEntry},
    {30, Resource_ScriptQueueType1ERecord},
    {31, CombatScript_InvokeHandler02169bb4With1F},
    {32, CombatScript_InvokeHandler02169bb4With20},
    {33, Script_QueueCopiedStringNode},
    {34, Script_CreateTag22RecordFromStringParameter},
    {35, func_ov000_0216ad7c},
    {36, func_ov000_0216ad90},
    {37, CombatScript_InvokeHandler02169bb4With25},
    {38, func_ov000_0216adb8},
    {39, Script_AllocateType39EntryFromParameter},
    {40, Script_AllocateType40EntryFromParameterMinus26},
    {41, Script_AllocateType29BytePairEntry},
    {42, Resource_ScriptQueueType42VectorRecord},
    {43, Resource_ScriptQueueType2BRecord},
    {44, func_ov000_0216b110},
    {45, Ov000_ApplyValue2DAndReturnOne},
    {46, Script_AllocateTypeFortySixRecordWithOptionalString},
    {47, Script_AllocateTaggedBytePairHalfwordEntry},
    {48, func_ov000_0216b26c},
    {49, func_ov000_0216b2bc},
    {50, func_ov000_0216b328},
    {51, CreateAllocatedStringParameterRecord},
    {52, Resource_ScriptAllocateAndSubmitType34Entry},
    {53, func_ov000_0216b464},
    {54, func_ov000_0216b478},
    {55, Script_QueueCommand37WithOptionalValues},
    {56, Ov000_AllocateAndInitializeLinkedEntry},
    {57, AllocateScriptHalfwordRecord},
    {58, Script_AllocateTaggedIntegerEntry3A},
    {59, Resource_ScriptQueueType3BWithCopiedString},
    {60, func_ov000_0216b870},
    {61, func_ov000_0216b884},
    {62, func_ov000_0216b898},
    {63, Script_AllocateCoordinateHalfwordEntry},
    {64, Resource_ScriptAllocateAndSubmitType40Entry},
    {65, func_ov000_0216b954},
    {66, Network_AllocateAndEnqueueTypeSixtySixNode},
    {67, func_ov000_0216ba00},
    {68, Resource_AllocateScriptType44Entry},
    {69, Script_AllocateType69EntryWithTwoIntegers},
    {70, func_ov000_0216bac8},
    {71, Script_AllocateTaggedHalfwordEntry47},
    {72, Script_AllocateAndInitializeType48Record},
    {73, func_ov000_0216bbc4},
    {74, func_ov000_0216bbd8},
    {75, CombatScript_InvokeHandler02169bb4With4B},
    {76, Script_TryAllocateTypedParameterEntry},
    {77, func_ov000_0216bc54},
    {78, Script_AllocateType4EIntegerEntry},
    {79, Script_AllocateTypeSeventyNineBitfieldRecord},
    {80, func_ov000_0216bd9c},
    {84, Script_AllocateType84EntryFromFloatParameter},
    {85, func_ov000_0216be58},
    {86, func_ov000_0216be6c},
    {87, func_ov000_0216bf40},
    {88, Script_AllocateVectorAndThreeFixedPointScalars},
    {89, Script_QueueTwoVectorCommand59},
    {90, func_ov000_0216c0f4},
    {91, Script_QueueOptionalStringNode},
    {92, Network_AllocateAndEnqueueTypeNinetyTwoNode},
    {93, Script_AllocateType5DHalfwordEntry},
    {94, Network_AllocateAndEnqueueTypeNinetyFourNode},
    {95, func_ov000_0216c2c4},
    {96, func_ov000_0216c314},
    {97, Script_AllocateTypeNinetySevenEntry},
    {98, func_ov000_0216c3ec},
    {99, func_ov000_0216c400},
    {100, Resource_AllocateType100ScriptCommand},
    {101, func_ov000_0216c490},
    {102, Script_AllocateTaggedHalfwordIntEntry},
    {103, Ov000_ApplyValue67AndReturnOne},
    {104, Script_AllocateTwoHalfwordParameterEntry},
    {105, func_ov000_0216c570},
    {106, Script_AllocateTypedParameterEntry},
    {107, AllocateScriptIntegerRecord},
    {108, Script_AllocateTaggedByteAndHalfwordEntry},
    {109, func_ov000_0216c680},
    {110, Script_AllocateTaggedHalfwordEntry6E},
    {111, func_ov000_0216c720},
    {112, Script_TryAllocateOptionalHalfwordEntry},
    {113, Script_AllocateScaledFloatParameterEntry},
    {114, Script_AllocateTypeOneHundredFourteenEntry},
    {115, Resource_AllocateType115ScriptCommand},
    {116, func_ov000_0216c8e4},
    {117, func_ov000_0216c9fc},
    {118, Script_QueueOpcode76FixedPointParameters},
    {119, Script_AllocateBooleanParameterEntry},
    {120, func_ov000_0216ccd8},
    {121, func_ov000_0216c95c},
    {122, Network_AllocateAndEnqueueTypeNinetyEightNode},
    {123, Script_AllocateScaledFloatEntry},
    {124, func_ov000_0216cd90},
    {125, Ov000_AllocateOptionalLinkedEntry},
    {126, Util_CallFunctionWithConstant7E},
    {127, AllocateScriptFixedPointRecord},
    {128, func_ov000_0216cec0},
    {129, func_ov000_0216cf04},
    {130, Script_AllocateType82ConditionalByteEntry},
    {131, CombatScript_InvokeHandler02169bb4With83},
    {132, Script_AllocateTypeOneHundredThirtyTwoEntry},
    {133, func_ov000_0216cfd4},
    {134, func_ov000_0216cfe8},
    {135, Ov000_ApplyValue87AndReturnOne},
    {136, func_ov000_0216d010},
    {137, func_ov000_0216d024},
    {138, Script_AllocateTypeOneHundredThirtyEightVectorEntry},
    {139, Ov000_AllocateConditionalLinkedEntry},
    {140, Script_QueueFixedRadianCommand8C},
    {141, CombatScript_InvokeHandler02169bb4With8D},
    {142, func_ov000_0216d1b0},
    {0, 0},
};
}
