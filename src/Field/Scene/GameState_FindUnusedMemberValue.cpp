#include <globaldefs.h>
ARM
struct GameState;struct GameObject;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameObject* GameState_FindIndexedObjectWithFlag1000(GameState*,int);
extern "C" int GameObject_GetAssociatedPartyMemberIndex(GameObject*);
extern "C" unsigned char GameObject_GetSecondaryPartyMemberIndex(void*);
// Original: arm9/ov017 @ 0x02191764; symbol: func_ov017_02191764; size: 0x8C.
extern "C" int GameState_FindUnusedMemberValue(int excluded,int key) {
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
unsigned used=0;
for(int i=0;i<4;++i) {
GameObject* p=GameState_FindIndexedObjectWithFlag1000(state,i);
if(p && i!=excluded && key==GameObject_GetAssociatedPartyMemberIndex(p)) used|=1<<GameObject_GetSecondaryPartyMemberIndex(p);
}
int result=0;
for(int i=0;i<4;++i) if(!(used&(1<<i))) {result=i;break;}
return result;
}
