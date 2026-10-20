#include "World/WorldObjectInstanceList.h"
#include "World/WorldPlacementSource.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"

extern "C" {
    Zone3D* Zone3D_GetMainInstance();
    int LinkedQueue_GetFrontKindOrInvalid(void*);
    bool GameResources_GetMaskedSecondaryFlags(GameResources*, unsigned int);
}

// Original: arm9/main @ 0x0208F410; symbol: _ZN23WorldObjectInstanceList4DrawEv; size: 0xAC.
void WorldObjectInstanceList::Draw()
{
    if (!object) return;
    GameResources* resources = GameResources_GetInstance();
    if (LinkedQueue_GetFrontKindOrInvalid(resources->unknown_ptr_array_36fc[0]) == 10) return;
    if (GameResources_GetMaskedSecondaryFlags(resources, 2)) return;
    Zone3D_StructPtr_8* info = Zone3D_GetMainInstance()->pUnknownStruct_8_;
    WorldPlacementSource* state = WorldPlacementSource::GetInstance();
    if (!info) return;
    if (!state->IsMapEligible(info->mapShortName_)) return;
    for (Instance* entry = head; entry; entry = entry->next)
    {
        object->SetCurrentAnimationTime(entry->animationTime);
        object->position_ = entry->position;
        object->Draw(true);
    }
}
