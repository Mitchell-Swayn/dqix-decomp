#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma always_inline on
struct PlainVector {int words[3];};
extern "C" void GameObject_GetAuthorityPosition(Vector3fix*,Object3D*);
// Original: arm9/main @ 0x02073DFC; symbol: func_02073dfc; size: 0xC8.
extern "C" int GameState_TestNearbyMatchingPartyMemberPosition(unsigned short* id,const Vector3fix* position){GameState* state=GameState::GetInstance();PlainVector point,base;GameObject* member;for(int i=0;i<4;i++){member=state->GetPartyMemberByIndex(i);if(member){Object3D* object=&member->obj3D_;unsigned objectID=object->GetField06();GameObject_GetAuthorityPosition((Vector3fix*)&base,object);point=base;unsigned alternate=*(unsigned*)((char*)object+348);if(alternate!=~0u){objectID=alternate;if(i==0||(*(unsigned short*)object&4096))*(Vector3fix*)&point=*(Vector3fix*)((char*)object+352);}if(*id==objectID&&Vector3fix_Distance(position,(Vector3fix*)&point)<14336)return 1;}}return 0;}
