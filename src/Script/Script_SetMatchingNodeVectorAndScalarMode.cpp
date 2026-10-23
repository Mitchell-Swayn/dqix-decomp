#include <globaldefs.h>
#include <Resource/Script.h>
ARM

struct E;
extern "C" E *LinkedList_FindNodeByUnsignedKey(E **, unsigned);

struct MatchingNode {
    unsigned char unknown00[0x1f];
    unsigned char mode;
    unsigned char unknown20[4];
    int values[4];
    unsigned char unknown34[0x10];
    unsigned short serial;
    unsigned char unknown46[0x2a];
    MatchingNode *next;
};

// Original data: arm9/main @ 0x02108CEC; symbol: data_02108cec.
// The selected serial is at +0x0a and the keyed-list pointer is at +0x10.
extern "C" unsigned char ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage[];

// Original: arm9/main @ 0x0206C614; symbol: func_0206c614; size: 0xE0.
// Sets four 20.12 fixed-point values on the selected serial node and selects mode 7.
extern "C" int Script_SetMatchingNodeVectorAndScalarMode(Script::Parameter *params, int)
{
    unsigned key = params[0].ToInt();
    MatchingNode *node = (MatchingNode *)LinkedList_FindNodeByUnsignedKey(
        *(E ***)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage + 0x10), key);
    if (!node)
        return 0;
    while (node) {
        if (node->serial == *(unsigned short *)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage + 0x0a))
            break;
        node = node->next;
    }
    if (!node)
        return 0;
    node->values[0] = (int)(4096.0f * params[1].ToFloat());
    node->values[1] = (int)(4096.0f * params[2].ToFloat());
    node->values[2] = (int)(4096.0f * params[3].ToFloat());
    node->values[3] = (int)(4096.0f * params[4].ToFloat());
    node->mode = 7;
    return 1;
}
