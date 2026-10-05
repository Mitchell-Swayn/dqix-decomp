#pragma once

// Observed linked-record layout shared by the World script helpers.
struct WorldScriptRecordNode
{
    short key;
    union
    {
        unsigned short rawSelector;
        struct
        {
            unsigned short selectorLow : 9, selectorValue : 6, unknown15 : 1;
        } selectorBits;
    } selector;
    unsigned int opaque4;
    WorldScriptRecordNode* next;
};

typedef char WorldScriptRecordNodeSizeCheck[
    sizeof(WorldScriptRecordNode) == 12 ? 1 : -1];

struct WorldScriptRecordList
{
    WorldScriptRecordNode* head;
    short count;
};

typedef char WorldScriptRecordListSizeCheck[
    sizeof(WorldScriptRecordList) == 8 ? 1 : -1];
