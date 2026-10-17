#include <globaldefs.h>
#include "Resource/Script.h"
// Opcodes3..22 for scripted placements; the zero opcode terminates lookup.
extern "C" {
int Script_InsertOrRemoveVectorNodeBySerial(Script::Parameter*, int);
int Script_AddFilteredPositionRecord(Script::Parameter*, int);
int Script_RegisterConditionalLinkedEntry(Script::Parameter*, int);
int func_0206c4e8(Script::Parameter*, int);
int func_0206c614(Script::Parameter*, int);
int Script_SetAngledRadiusBounds(Script::Parameter*, int);
int Script_CreateCircularPositionPathForSelectedNode(Script::Parameter*, int);
int Script_AllocatePointListForMatchingNode(Script::Parameter*, int);
int Script_SetFlagsOnMatchingSerialNode(Script::Parameter*, int);
int func_0206cad8(Script::Parameter*, int);
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
extern "C" Script::OpcodeLookupEntry data_020f0994[21] = {
    {3, Script_InsertOrRemoveVectorNodeBySerial},
    {4, Script_AddFilteredPositionRecord},
    {5, Script_RegisterConditionalLinkedEntry},
    {6, func_0206c4e8},
    {7, func_0206c614},
    {8, Script_SetAngledRadiusBounds},
    {9, Script_CreateCircularPositionPathForSelectedNode},
    {10, Script_AllocatePointListForMatchingNode},
    {11, Script_SetFlagsOnMatchingSerialNode},
    {12, func_0206cad8},
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
