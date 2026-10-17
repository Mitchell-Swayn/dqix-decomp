#include "World/WorldObjectInstanceList.h"
#include "World/WorldPlacementSource.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"

extern "C" {
    Zone3D* ReadGlobalValueAt020FB3F0();
    int ReadIndirectByteOrMinusOne(void*);
    bool TestFieldBitsAtOffset4(GameResources*, unsigned int);
}

// Original: arm9/main @ 0x0208F410; symbol: _ZN23WorldObjectInstanceList4DrawEv; size: 0xAC.
void WorldObjectInstanceList::Draw()
{
    if (!object) return;
    GameResources* resources = GameResources_GetInstance();
    if (ReadIndirectByteOrMinusOne(resources->unknown_ptr_array_36fc[0]) == 10) return;
    if (TestFieldBitsAtOffset4(resources, 2)) return;
    Zone3D_StructPtr_8* info = ReadGlobalValueAt020FB3F0()->pUnknownStruct_8_;
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
