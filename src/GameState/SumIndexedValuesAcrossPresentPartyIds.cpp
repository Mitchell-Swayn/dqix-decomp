#include <globaldefs.h>
#include <GameState/GameState.h>
struct Owner {char pad[0xf78];unsigned char party[4],count;};
extern "C" void* GameState_GetObjectWithFlag100(GameState*,unsigned);extern "C" void* ReadWordFieldAtOffset150(void*);extern "C" short CountMatchingKeyInEightHalfwordSlots(void*,int);extern "C" int FindKeyAmongElevenThirtyTwoByteEntries(void*,int);extern "C" short Object_SumKeyValuesAcrossThreeContainers(Owner*,int);
// Original: arm9/main @ 0x02086AEC; symbol: func_02086aec; size: 0xAC.
extern "C" short SumIndexedValuesAcrossPresentPartyIds(Owner* self,int index) {if(index<0)return 0;short total=0;GameState* state=GameState::GetInstance();for(unsigned char i=0;i<self->count;++i) {void* object=GameState_GetObjectWithFlag100(state,self->party[i]);if(object) {object=ReadWordFieldAtOffset150(object);if(object) {total+=CountMatchingKeyInEightHalfwordSlots(object,index);if(FindKeyAmongElevenThirtyTwoByteEntries(object,index))++total;}}}return total+Object_SumKeyValuesAcrossThreeContainers(self,index);}
