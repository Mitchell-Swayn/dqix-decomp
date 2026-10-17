#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma always_inline on
struct Slots{signed char entries[9];};
extern "C" const Slots data_020e87b4;
extern "C" char *ReadWordFieldAtOffset150(GameObject*);
extern "C" int ReadNonnegativeIndexedBit(void*,void*,unsigned);
extern "C" void BitArray_SetIndexedBoolean(void*,void*,unsigned,int);
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void*);
extern "C" int GameState_Copy176BytesAtOffset7540(const void*);
extern "C" void AddToField14ValueClamped1500(void*,unsigned);
struct TypeBits{unsigned kind:4;unsigned rest:28;};struct IdBits{unsigned low:12;unsigned id:11;unsigned rest:9;};
inline bool normalKind(char *entry){return ((TypeBits*)(entry+8))->kind<=7;}
// Original: arm9/main @ 0x0206E424; symbol: func_0206e424; size: 0x134.
extern "C" void RecordUnseenPartySlotIdsAndCountChanges(char *state,int index){bool valid;if(index>=0&&index<=3)valid=true;else valid=false;if(valid){GameObject *party=GameState::GetInstance()->GetPartyMemberByIndex(index);if(party){char *object=ReadWordFieldAtOffset150(party);if(object){Slots slots=data_020e87b4;unsigned char changes=0;for(unsigned char i=0;slots.entries[i]>=0;i++){char *entry=object+0x194+slots.entries[i]*32;bool normal=normalKind(entry);if(normal){unsigned short id=((IdBits*)(entry+12))->id;if(id&&!ReadNonnegativeIndexedBit(state,state+0x8c,id+0xc76)){BitArray_SetIndexedBoolean(state,state+0x8c,id+0xc76,1);++changes;}}}unsigned work[44];GameState_CopyB0ByteStateBufferToOutput(work);AddToField14ValueClamped1500(work,changes);GameState_Copy176BytesAtOffset7540(work);}}}}
