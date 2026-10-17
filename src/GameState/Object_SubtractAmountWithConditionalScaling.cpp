#include <globaldefs.h>
#include <GameState/GameState.h>
struct Data {char pad[6];unsigned short amount;};struct Owner {char pad[4];short index;char pad2[0x12a];Data* data;};extern "C" void* GameState_GetObjectWithFlag100(GameState*,int);extern "C" void* ReadWordFieldAtOffset150(void*);extern "C" int Object_ReadIndexedBitAtOffset8EC(void*,unsigned);
// Original: arm9/main @ 0x02048350; symbol: func_02048350; size: 0xA0.
extern "C" int Object_SubtractAmountWithConditionalScaling(Owner* self,int amount) {unsigned available=self->data->amount;void* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),self->index);if(object && amount>0 && (object=ReadWordFieldAtOffset150(object)) && Object_ReadIndexedBitAtOffset8EC(object,0x106)){amount=(int)(0.75f+0.75f*(float)amount);if(amount<=0)amount=0;}if((int)available<=amount){self->data->amount=0;return available;}else {self->data->amount=available-amount;return amount;}}
