#include <globaldefs.h>
#pragma opt_common_subs off
#include <GameState/GameState.h>
extern "C" void Graphics_SetObjectSlotPositionOrTranslation(void*,int,Vector3fix);extern "C" void UpdateDelayedObjectAndPositionStep(void*,int);
struct Slot {char pad[80];Vector3fix angle;char gap[116];int mode;char tail[4];};struct State {Slot slots[12];unsigned pad;unsigned short mask;};
// Original: arm9/main @ 0x020D7534; symbol: func_020d7534; size: 0x104.
extern "C" void UpdateTwelveEnabledObjectSlotsAndAngles(State* owner){unsigned char* p=(unsigned char*)owner;GameState* state=GameState::GetInstance();unsigned tick=state->GetTickCount();for(int i=0;i<12;i++){if(*(unsigned short*)(p+2596)&(1u<<i)){int index=i;if(i>3)index=i+188;GameObject* member=state->GetGameObjectByIndex(index);if(member){Object3D* object=&member->obj3D_;Vector3fix point=*(Vector3fix*)((char*)object+132);point.y=object->GetHeight();Graphics_SetObjectSlotPositionOrTranslation(p,i,point);unsigned offset=i*sizeof(Slot);Slot* slot=(Slot*)(p+offset);if(slot->mode==4){Vector3fix angle=slot->angle;angle.y+=614;if(angle.y>25736)angle.y-=25736;slot->angle=angle;}UpdateDelayedObjectAndPositionStep((Slot*)(p+offset),tick);}}}}
