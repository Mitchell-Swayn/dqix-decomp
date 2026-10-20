#include <globaldefs.h>
#include <GameState/GameState.h>
struct Owner {char pad[0xf78];unsigned char party[4],count;};
extern "C" void* GameState_GetObjectWithFlag100(GameState*,unsigned);extern "C" void* GameObject_GetLinkedIndexedState(void*);extern "C" short CharacterState_CountCarriedItemCopies(void*,int);extern "C" int CharacterState_FindEquipmentDescriptorByItemId(void*,int);extern "C" short PartyInventory_GetTotalItemQuantity(Owner*,int);
// Original: arm9/main @ 0x02086AEC; symbol: func_02086aec; size: 0xAC.
extern "C" short SumIndexedValuesAcrossPresentPartyIds(Owner* self,int index) {if(index<0)return 0;short total=0;GameState* state=GameState::GetInstance();for(unsigned char i=0;i<self->count;++i) {void* object=GameState_GetObjectWithFlag100(state,self->party[i]);if(object) {object=GameObject_GetLinkedIndexedState(object);if(object) {total+=CharacterState_CountCarriedItemCopies(object,index);if(CharacterState_FindEquipmentDescriptorByItemId(object,index))++total;}}}return total+PartyInventory_GetTotalItemQuantity(self,index);}
