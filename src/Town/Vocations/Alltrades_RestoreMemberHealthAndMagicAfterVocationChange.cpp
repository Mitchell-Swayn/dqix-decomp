#include <globaldefs.h>
#include "GameState/GameState.h"
ARM
#pragma force_active on
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsSessionActive(int*);
extern "C" void Network_QueueCurrentPartyMemberState(int,int,int,int);
// Original: arm9/ov003 @ 0x02155740; symbol: func_ov003_02155740; size: 0xEC.
extern "C" void Alltrades_RestoreMemberHealthAndMagicAfterVocationChange(void* menu) {
    char* self=(char*)menu;
    GameObject* object=GameState::GetInstance()->GetPartyMemberByIndex(*(signed char*)(self+0x1f7));
    if(!object) return;
    if(*(unsigned*)(self+0x1fc)&1) {
        BaseCombatStats* stats=object->baseStats_;
        unsigned short maximumHp=stats->primaryStats.maxHP;
        int hp=(int)(*(float*)(self+0x330)*(float)(int)maximumHp);
        unsigned short maximumMp=stats->primaryStats.maxMP;
        int mp=(int)(*(float*)(self+0x334)*(float)(int)maximumMp);
        if(hp<=0) hp=1;
        if(mp<=0) mp=0;
        if(maximumHp<hp) hp=maximumHp;
        *(short*)(*(char**)((char*)object+0x130)+4)=hp;
        if(maximumMp<mp) mp=maximumMp;
        *(short*)(*(char**)((char*)object+0x130)+6)=mp;
    } else {
        *(short*)(*(char**)((char*)object+0x130)+4)=object->baseStats_->primaryStats.maxHP;
        *(short*)(*(char**)((char*)object+0x130)+6)=object->baseStats_->primaryStats.maxMP;
    }
    if(Network_IsSessionActive((int*)Network_GetConnectionManager())) Network_QueueCurrentPartyMemberState(*(signed char*)(self+0x1f7),1,0,1);
}
