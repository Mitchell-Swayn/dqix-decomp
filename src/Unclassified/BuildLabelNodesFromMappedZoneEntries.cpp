#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <World/Zone3DEmbeddedState.h>
#include <std_library_functions.h>

ARM

extern "C" {
void __clear(void*, unsigned int);
void* ReadGlobalValueAt020FB3F0();
void* LinkedList_FindNodeByUnsignedKey(void*, int);
void Text_MapInputBytesToVariableLengthOutputSequences(void*, void*, int);
extern char data_020f0618[], data_020f061e[], data_020f0624[], data_020f062a[];
extern char data_020f0666[];
extern char data_020f0630[], data_020f0636[], data_020f063c[], data_020f0642[];
extern char data_020f0648[], data_020f064e[], data_020f0654[], data_020f065a[];
extern char data_020f0660[], data_020f0666[], data_020f066c[], data_020f0672[];
extern char data_020f066c[], data_020f0672[], data_020f0678[], data_020f067e[], data_020f0684[], data_020f068a[];
extern char data_020f0690[], data_020f0696[], data_020f069c[], data_020f06a2[];
extern char data_020f06a8[], data_020f06ae[], data_020f06b4[], data_020f06ba[];
}

struct LabelNode {
    unsigned short index;
    unsigned char kindFlag;
    unsigned char visibleFlag;
    char label[12];
    LabelNode* next;
};

// Original: arm9/main @ 0x02064E88; symbol: func_02064e88; size: 0x404.
extern "C" int BuildLabelNodesFromMappedZoneEntries(LabelNode** list, void* object, SafeAllocator* allocator) {
    char* game = (char*)ReadGlobalValueAt020FB3F0();
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
                case 0: sprintf(node->label, data_020f0618); break;
                case 1: sprintf(node->label, data_020f061e); break;
                case 2: sprintf(node->label, data_020f0624); break;
                case 3: sprintf(node->label, data_020f062a); break;
                case 4: sprintf(node->label, data_020f0630); break;
                case 5: sprintf(node->label, data_020f0636); break;
                case 6: sprintf(node->label, data_020f063c); break;
                case 7: sprintf(node->label, data_020f0642); break;
                case 8: sprintf(node->label, data_020f0648); break;
                case 9: sprintf(node->label, data_020f064e); break;
                case 10: sprintf(node->label, data_020f0654); break;
                case 11: sprintf(node->label, data_020f065a); break;
                case 12: sprintf(node->label, data_020f0660); break;
                default: sprintf(node->label, data_020f0666); break;
                }
            } else {
                switch (entries[i]->flags.low) {
                case 0: sprintf(node->label, data_020f066c); break;
                case 1: sprintf(node->label, data_020f0672); break;
                case 2: sprintf(node->label, data_020f0678); break;
                case 3: sprintf(node->label, data_020f067e); break;
                case 4: sprintf(node->label, data_020f0684); break;
                case 5: sprintf(node->label, data_020f068a); break;
                case 6: sprintf(node->label, data_020f0690); break;
                case 7: sprintf(node->label, data_020f0696); break;
                case 8: sprintf(node->label, data_020f069c); break;
                case 9: sprintf(node->label, data_020f06a2); break;
                case 10: sprintf(node->label, data_020f06a8); break;
                case 11: sprintf(node->label, data_020f06ae); break;
                case 12: sprintf(node->label, data_020f06b4); break;
                default: sprintf(node->label, data_020f06ba); break;
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
