#include <globaldefs.h>
ARM
// Preserve the state-field snapshots and arithmetic intermediates in the original.
#pragma opt_propagation off
#include <GameState/GameState.h>
struct Inventory { short* ids; signed char* counts; short capacity; };
struct CatalogueNode { CatalogueNode* next; char* record; };
struct Catalogue;
struct Table;
struct List;
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" int GetInventoryItemByID(char*, int, int);
extern "C" int Inventory_CountOccupiedSlots(char*);
extern "C" void Menu_ClearCatalogueSelection(Table*);
extern "C" void World_LinkKeyedRecordsAndSetEnabledFlags(List*, void*);
extern "C" void Resource_BuildLinkedNodeChainWithExtraArgument(void**, unsigned, unsigned, unsigned, unsigned);
extern "C" void Menu_BuildAlternateCatalogueByPrimaryRank(void**, int, int, int, int);
extern "C" void* memset(void*, int, unsigned);
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" void Inventory_ClearSlots(char*);
extern "C" int Inventory_AddItemCountWithNinetyNineLimit(Inventory*, int, int);
extern "C" int Inventory_FindItemSlot(unsigned char*, int);
extern "C" void Window_SetEnabledSelectionIndices(char*, int);
struct WindowCanvasOwner;
struct WindowCanvasRecord;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*, unsigned);
extern "C" void PartyMenu_RebuildPanelTextById(char*, int, int);
// Original: arm9/ov002 @ 0x0215B458; symbol: func_ov002_0215b458; size: 0x1F0.
// Toggles the bag catalogue ordering, rebuilds inventory order and optionally preserves the selected item.
extern "C" void PartyMenu_ToggleBagSortOrder(char* self, int keepSelection)
{
    register char* catalogue;
    register int selected;
    register Inventory* inventory = (Inventory*)GameState_GetIndexList(GameState::GetInstance());
    selected = GetInventoryItemByID(self, *(short*)(self + 0x1be8), self[0x1c20]);
    register int count;
    short* ids = *(short**)((char*)inventory);
    signed char* counts = *(signed char**)((char*)inventory + 4);
    count = Inventory_CountOccupiedSlots((char*)inventory);
    if (!count) return;
    catalogue = self + 4;
    Menu_ClearCatalogueSelection((Table*)(catalogue + 0x800));
    World_LinkKeyedRecordsAndSetEnabledFlags((List*)(catalogue + 0x800), self + 0x7ec);
    if ((unsigned char)self[0x248d] == 2) {
        Resource_BuildLinkedNodeChainWithExtraArgument((void**)(catalogue + 0x800), 1, -1, -1, 0);
        self[0x248d] = 1;
    } else {
        Menu_BuildAlternateCatalogueByPrimaryRank((void**)(catalogue + 0x800), 1, -1, -1, 0);
        self[0x248d] = 2;
    }
    memset(*(void**)(self + 0x2534), 0, 0x140);
    memset(*(void**)(self + 0x2538), 0, 0xa0);
    memcpy(*(void**)(self + 0x2534), ids, count * 2);
    memcpy(*(void**)(self + 0x2538), counts, count);
    Inventory_ClearSlots((char*)inventory);
    for (CatalogueNode* node = *(CatalogueNode**)(catalogue + 0x800); node; node = node->next) {
        if (node->record) {
            int key = *(short*)(node->record + 0x18);
            for (short i = 0; i < count; ++i) {
                if (key == (*(short**)(self + 0x2534))[i]) {
                    Inventory_AddItemCountWithNinetyNineLimit(inventory, key, (*(signed char**)(self + 0x2538))[i]);
                    break;
                }
            }
        }
    }
    if (selected >= 0 && keepSelection) {
        int slot = Inventory_FindItemSlot((unsigned char*)inventory, selected);
        if (slot >= 0) {
            *(short*)(self + 0x1be8) = slot;
            Window_SetEnabledSelectionIndices(self + 0xec8, slot);
            unsigned char* canvas = (unsigned char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), 5);
            if (canvas) canvas[0xc5] &= ~2;
        }
    }
    PartyMenu_RebuildPanelTextById(self, 5, 0);
}
