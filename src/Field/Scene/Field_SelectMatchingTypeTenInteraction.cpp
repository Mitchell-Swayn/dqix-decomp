#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/ZoneFeatures.h>
#pragma always_inline on
#pragma force_active on
ARM
extern "C" bool GameObject_HasQueuedActions(signed char*);
extern "C" bool GameObject_IsMovementPauseActive(char*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* GameState_ReadUnknownB0(GameState*);
extern "C" int ZoneFeatures_TestPointInsideEntry(ZoneFeatures::Opcode6aEntry*,const Vector3fix*);
extern "C" void Field_InitializeInteractionCandidate(unsigned char*);
extern "C" void Field_SelectBetterInteractionCandidate(void*,void*);
// Original: arm9/ov017 @ 0x02198618; symbol: func_ov017_02198618; size: 0xE4.
// Selects the first containing type-ten region matching the zone's stored entry and zone identifiers.
extern "C" void Field_SelectMatchingTypeTenInteraction(void* owner)
{
    GameState* game=GameState::GetInstance();
    GameObject* actor=game->GetUnknownGameObject();
    if (!actor || GameObject_HasQueuedActions((signed char*)actor) || GameObject_IsMovementPauseActive((char*)actor)) return;
    unsigned char* zone=(unsigned char*)Zone3D_GetMainInstance();
    GameState_ReadUnknownB0(game);
    ZoneFeatures::Opcode6aEntry* entry=((ZoneFeatures*)(zone+0x6c))->GetTypeEntries(10);
    Vector3fix position=*(Vector3fix*)((unsigned char*)actor+0x44);
    while(entry) {
        if (ZoneFeatures_TestPointInsideEntry(entry,&position)) {
            if (*(unsigned short*)((unsigned char*)entry+0x2c)==*(short*)(zone+0x2784) && *(unsigned short*)zone==*(unsigned short*)(zone+0x2786)) {
                unsigned char candidate[20];
                Field_InitializeInteractionCandidate(candidate);
                candidate[0]=11;
                *(void**)(candidate+8)=entry;
                candidate[4]=1;
                Field_SelectBetterInteractionCandidate(owner,candidate);
                break;
            }
        }
        entry=*(ZoneFeatures::Opcode6aEntry**)((unsigned char*)entry+0x70);
    }
}
