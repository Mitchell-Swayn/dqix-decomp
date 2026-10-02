#include "World/WorldObjectInstanceList.h"
#include "World/WorldPlacementSource.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"

extern "C" {
    Zone3D* func_02012fe4();
    int func_02046b24(void*);
    bool func_0203b4fc(GameResources*, unsigned int);
}

void WorldObjectInstanceList::Draw()
{
    if (!object) return;
    GameResources* resources = func_ov017_0218b5b0();
    if (func_02046b24(resources->unknown_ptr_array_36fc[0]) == 10) return;
    if (func_0203b4fc(resources, 2)) return;
    Zone3D_StructPtr_8* info = func_02012fe4()->pUnknownStruct_8_;
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
