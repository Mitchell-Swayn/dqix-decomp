#include <globaldefs.h>
#include "GameState/GameState.h"
ARM
#pragma force_active on
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
// Non-owning view of the packed action fields read by this calculation.
// Word +4: lower bound bits 12..21 and upper bound bits 22..31.
// Word +0x14: lower probability bits 7..13, upper probability bits 14..20.
// Word +0x18: effect selector bits 16..17. Flag 0x8000 enables scaling.
struct RevivalScalingFields {
    unsigned unknown00;
    unsigned unknown04:12,minimumMending:10,maximumMending:10;
    unsigned unknown08,unknown0c;
    unsigned flags;
    unsigned unknown14:7,minimumChance:7,maximumChance:7,unknown14b:11;
    unsigned unknown18:16,effectKind:2,unknown18b:14;
};
// Original: arm9/ov002 @ 0x02153BE0; symbol: func_ov002_02153be0; size: 0xEC.
extern "C" int PartyMenu_ComputeRevivalSuccessRate(void*,void* action,int member) {
    RevivalScalingFields* fields=(RevivalScalingFields*)action;
    int chance=0;
    if(fields->effectKind==1) {
        GameObject* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),member);
        if(!object) return chance;
        if(fields->flags&0x8000) {
            unsigned short mending=object->baseStats_->primaryStats.magicalMending;
            if(mending<=fields->minimumMending) chance=fields->minimumChance;
            else if(mending>=fields->maximumMending) chance=fields->maximumChance;
            else {
                float slope=(float)(fields->maximumChance-fields->minimumChance)/(float)(fields->maximumMending-fields->minimumMending);
                chance=fields->minimumChance+(int)(slope*(float)(mending-fields->minimumMending));
            }
        }
    }
    return chance;
}
