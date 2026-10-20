#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <World/Zone3DEmbeddedState.h>
#include <std_library_functions.h>

ARM

extern "C" {
void __clear(void*, unsigned int);
void* Zone3D_GetMainInstance();
void* LinkedList_FindNodeByUnsignedKey(void*, int);
void Text_MapInputBytesToVariableLengthOutputSequences(void*, void*, int);
extern char World_BuildLabelNodesFromMappedZoneEntries_TextN047A[], World_BuildLabelNodesFromMappedZoneEntries_TextN031A[], World_BuildLabelNodesFromMappedZoneEntries_TextN016A[], World_BuildLabelNodesFromMappedZoneEntries_TextN005A[];
extern char World_BuildLabelNodesFromMappedZoneEntries_TextN001A[];
extern char World_BuildLabelNodesFromMappedZoneEntries_TextN033A[], World_BuildLabelNodesFromMappedZoneEntries_TextN034A[], World_BuildLabelNodesFromMappedZoneEntries_TextN010A[], World_BuildLabelNodesFromMappedZoneEntries_TextN029A[];
extern char World_BuildLabelNodesFromMappedZoneEntries_TextN065A[], World_BuildLabelNodesFromMappedZoneEntries_TextN028A[], World_BuildLabelNodesFromMappedZoneEntries_TextN077A[], World_BuildLabelNodesFromMappedZoneEntries_TextN080A[];
extern char World_BuildLabelNodesFromMappedZoneEntries_TextN056A[], World_BuildLabelNodesFromMappedZoneEntries_TextN001A[], World_BuildLabelNodesFromMappedZoneEntries_TextN048A[], World_BuildLabelNodesFromMappedZoneEntries_TextN032A[];
extern char World_BuildLabelNodesFromMappedZoneEntries_TextN048A[], World_BuildLabelNodesFromMappedZoneEntries_TextN032A[], World_BuildLabelNodesFromMappedZoneEntries_TextN017A[], World_BuildLabelNodesFromMappedZoneEntries_TextN035A[], World_BuildLabelNodesFromMappedZoneEntries_TextN059A[], World_BuildLabelNodesFromMappedZoneEntries_TextN073A[];
extern char World_BuildLabelNodesFromMappedZoneEntries_TextN021A[], World_BuildLabelNodesFromMappedZoneEntries_TextN072A[], World_BuildLabelNodesFromMappedZoneEntries_TextN053A[], World_BuildLabelNodesFromMappedZoneEntries_TextN085A[];
extern char World_BuildLabelNodesFromMappedZoneEntries_TextN078A[], World_BuildLabelNodesFromMappedZoneEntries_TextN082A[], World_BuildLabelNodesFromMappedZoneEntries_TextN057A[], World_BuildLabelNodesFromMappedZoneEntries_TextN002A[];
}

struct LabelNode {
    unsigned short index;
    unsigned char kindFlag;
    unsigned char visibleFlag;
    char label[12];
    LabelNode* next;
};

// Original: arm9/main @ 0x02064E88; symbol: func_02064e88; size: 0x404.
extern "C" int World_BuildLabelNodesFromMappedZoneEntries(LabelNode** list, void* object, SafeAllocator* allocator) {
    char* game = (char*)Zone3D_GetMainInstance();
    ZoneState0840* state = (ZoneState0840*)(game + 0x840);
    int currentValue = *(unsigned short*)game;
    int kind = state->GetMappedValueRemainder(currentValue);
    int threshold = state->GetKindThreshold(kind);
    state->ClearEntryStates();
    kind = state->GetMappedValueRemainder(currentValue);
    ZoneState0840::Entry* entries[10];
    char formatted[0x30];
    int count = state->CollectEntriesOfKind(kind, entries);

    for (int i = 0; i < count; ++i) {
        int index = i + 1 + threshold;
        if (LinkedList_FindNodeByUnsignedKey(object, index)) {
            LabelNode* node = (LabelNode*)allocator->Allocate(0x14);
            if (!node) break;
            node->index = (unsigned short)index;
            node->kindFlag = ((*(unsigned int*)((char*)entries[i] + 0x0c) << 1) >> 31) ? 4 : 0;
            __clear(formatted, 0x30);
            Text_MapInputBytesToVariableLengthOutputSequences(entries[i], formatted, 1);

            if (!entries[i]->configuration1a.flags14.low) {
                switch (entries[i]->flags.low) {
                case 0: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN047A); break;
                case 1: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN031A); break;
                case 2: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN016A); break;
                case 3: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN005A); break;
                case 4: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN033A); break;
                case 5: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN034A); break;
                case 6: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN010A); break;
                case 7: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN029A); break;
                case 8: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN065A); break;
                case 9: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN028A); break;
                case 10: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN077A); break;
                case 11: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN080A); break;
                case 12: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN056A); break;
                default: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN001A); break;
                }
            } else {
                switch (entries[i]->flags.low) {
                case 0: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN048A); break;
                case 1: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN032A); break;
                case 2: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN017A); break;
                case 3: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN035A); break;
                case 4: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN059A); break;
                case 5: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN073A); break;
                case 6: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN021A); break;
                case 7: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN072A); break;
                case 8: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN053A); break;
                case 9: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN085A); break;
                case 10: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN078A); break;
                case 11: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN082A); break;
                case 12: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN057A); break;
                default: sprintf(node->label, World_BuildLabelNodesFromMappedZoneEntries_TextN002A); break;
                }
            }
            node->visibleFlag = !entries[i]->configuration1a.flags14.low ? 0 : 2;
            entries[i]->flags.state = (unsigned int)index & 0x3f;
            node->next = *list;
            *list = node;
        }
    }
    return count;
}
