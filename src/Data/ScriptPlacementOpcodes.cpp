#include <globaldefs.h>
#include "Resource/Script.h"
// Opcodes3..22 for scripted placements; the zero opcode terminates lookup.
extern "C" {
int Script_InsertOrRemoveVectorNodeBySerial(Script::Parameter*, int);
int Script_AddFilteredPositionRecord(Script::Parameter*, int);
int Script_RegisterConditionalLinkedEntry(Script::Parameter*, int);
int Script_AppendMatchingNodePlanarBounds(Script::Parameter*, int);
int Script_SetMatchingNodeVectorAndScalarMode(Script::Parameter*, int);
int Script_SetAngledRadiusBounds(Script::Parameter*, int);
int Script_CreateCircularPositionPathForSelectedNode(Script::Parameter*, int);
int Script_AllocatePointListForMatchingNode(Script::Parameter*, int);
int Script_SetFlagsOnMatchingSerialNode(Script::Parameter*, int);
int Script_SetMatchingNodeOptionByte(Script::Parameter*, int);
int Script_SetSelectedNodeFixedPointValue(Script::Parameter*, int);
int Script_AllocateFilteredRankedEntry(Script::Parameter*, int);
int Script_SetMatchingNodeFixedPointValue(Script::Parameter*, int);
int Script_SetMatchedNodeFlagAndVectorFromParameters(Script::Parameter*, int);
int Script_AppendConditionalZoneVectorRecord(Script::Parameter*, int);
int Script_SetSelectedNodeModeAndOptionalFixedPointValue(Script::Parameter*, int);
int Script_AllocateMatchingNodeStrings(Script::Parameter*, int);
int Script_AllocateMatchedNodeFixedPointValueArray(Script::Parameter*, int);
int Script_QueueFilteredRecord(Script::Parameter*, int);
int Script_SetSelectedNodePackedRGBAndFlag80(Script::Parameter*, int);
}
// Original data: arm9/main @ 0x20f0994; symbol: data_020f0994.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0300000010c0060204000000f8c0060205000000c0c2060206000000e8c406020700000014c6060208000000f4c60602090000002cc806020a00000038c90602 ...; full span in module reference.
// Observed span: 168 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Script::OpcodeLookupEntry ScriptInitializeOutputContextAndExecuteCode_UnknownRoleProcedureReferenceRecords[21] = {
    {3, Script_InsertOrRemoveVectorNodeBySerial},
    {4, Script_AddFilteredPositionRecord},
    {5, Script_RegisterConditionalLinkedEntry},
    {6, Script_AppendMatchingNodePlanarBounds},
    {7, Script_SetMatchingNodeVectorAndScalarMode},
    {8, Script_SetAngledRadiusBounds},
    {9, Script_CreateCircularPositionPathForSelectedNode},
    {10, Script_AllocatePointListForMatchingNode},
    {11, Script_SetFlagsOnMatchingSerialNode},
    {12, Script_SetMatchingNodeOptionByte},
    {13, Script_SetSelectedNodeFixedPointValue},
    {14, Script_AllocateFilteredRankedEntry},
    {15, Script_SetMatchingNodeFixedPointValue},
    {16, Script_SetMatchedNodeFlagAndVectorFromParameters},
    {17, Script_AppendConditionalZoneVectorRecord},
    {18, Script_SetSelectedNodeModeAndOptionalFixedPointValue},
    {19, Script_AllocateMatchingNodeStrings},
    {20, Script_AllocateMatchedNodeFixedPointValueArray},
    {21, Script_QueueFilteredRecord},
    {22, Script_SetSelectedNodePackedRGBAndFlag80},
    {0, 0},
};
