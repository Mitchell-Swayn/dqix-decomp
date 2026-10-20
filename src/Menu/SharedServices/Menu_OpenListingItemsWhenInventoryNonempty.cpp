#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_TestRecordWithMode65(void*);
extern "C" int GetTypeSevenRowMajorIndex(void*,int);
extern "C" int Menu_GetSelectedInventoryPartyMember(void*);
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" int Inventory_CountPositiveQuantitySlots(void*,int);
extern "C" int Inventory_CountOccupiedSlots(void*);
extern "C" int CharacterState_CountCarriedItems(char*);
extern "C" void Menu_QueueScriptEntry(void*,unsigned);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
// Counts selected quantity/flag/halfword slots; updates selected key in indexed mode, then notifies with 0x6A for a positive count.
// Original: arm9/ov004 @ 0x0215AA10; symbol: func_ov004_0215aa10; size: 0xE0.
extern "C" ARM int Menu_OpenListingItemsWhenInventoryNonempty(void* self) {
    void* state=_ZN9GameState11GetInstanceEv();
    int count=0;
    if (GameState_TestRecordWithMode65(self)) {
        int index=GetTypeSevenRowMajorIndex(self,0x65);
        if (index<0) return 0;
        unsigned char* list=(unsigned char*)GameState_GetIndexList(state);
        if (!list) return 0;
        unsigned char key=*(unsigned char*)(*(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage+8)+index+0x7c);
        count=Inventory_CountPositiveQuantitySlots(list+0x1d4,key);
        *(unsigned*)(*(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage+8)+0x74)=key;
    } else {
        int selected=Menu_GetSelectedInventoryPartyMember(self);
        if (selected==-1) {
            void* list=GameState_GetIndexList(state);
            if (!list) return 0;
            count=Inventory_CountOccupiedSlots(list);
        } else {
            void* object=GameState_GetObjectWithFlag100(state,selected);
            if (!object) return 0;
            count=CharacterState_CountCarriedItems((char*)GameObject_GetLinkedIndexedState(object));
        }
    }
    if (count>0) Menu_QueueScriptEntry(self,0x6a);
    return 0;
}
