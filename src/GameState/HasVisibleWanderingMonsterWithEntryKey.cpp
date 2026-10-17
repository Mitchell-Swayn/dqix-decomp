#include <globaldefs.h>
#include <GameState/GameState.h>
struct Context {unsigned short unused;struct Bits {unsigned short kind:2,other:14;} bits;char pad4[20];char entries[1];};
extern "C" unsigned char* Object_GetBoundedSixteenByteRecord(void*,unsigned short);
// Original: arm9/main @ 0x02073D58; symbol: func_02073d58; size: 0xA4.
extern "C" int HasVisibleWanderingMonsterWithEntryKey(unsigned key,Context* p,int excluded) {GameState* state=GameState::GetInstance();for(int i=0;i<12;i++){int id=(p->bits.kind*12+0x70)+i;if(excluded!=-1&&id==excluded)continue;GameObject* object=state->GetMaybeWanderingMonsterByIndex(id);if(!object)continue;if(!object->obj3D_.IsVisible())continue;unsigned char* entry=Object_GetBoundedSixteenByteRecord(p->entries,*(unsigned short*)((char*)object+0xb8));if(entry&&*entry==key)return 1;}return 0;}
