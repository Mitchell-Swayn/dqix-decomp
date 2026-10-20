#include <globaldefs.h>
#include "GameState/GameState.h"

// Original: arm9/main @ 0x0200FD70; symbol: _ZN9GameState20GetGameObjectByIndexEi; size: 0x20.
GameObject* GameState::GetGameObjectByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    return objects_[idx];
}

// Original: arm9/main @ 0x0200FD90; symbol: _ZN9GameState31GetMaybeWanderingMonsterByIndexEi; size: 0x3C.
GameObject* GameState::GetMaybeWanderingMonsterByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    if (objects_[idx] == NULL)
        return NULL;
    if (!(objects_[idx]->obj3D_.unknown_0_ & 2))
        return NULL;
    return objects_[idx];
}

// Original: arm9/main @ 0x0200FDCC; symbol: _ZN9GameState14GetProtagonistEv; size: 0x10.
GameObject* GameState::GetProtagonist()
{
    return GetGameObjectByIndex(protagonistObjectIndex_);
}

// Original: arm9/main @ 0x0200FDDC; symbol: _ZN9GameState20GetUnknownGameObjectEv; size: 0x14.
GameObject* GameState::GetUnknownGameObject()
{
#if defined(usa)
    return GetGameObjectByIndex(indexList_.objectIndices_[0]);
#else
    return GetGameObjectByIndex(unknownObjectIndex_397c_);
#endif
}

// Original: arm9/main @ 0x0200FDF0; symbol: _ZN9GameState21GetPartyMemberByIndexEi; size: 0x3C.
GameObject* GameState::GetPartyMemberByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    if (objects_[idx] == NULL)
        return NULL;
    if (!(objects_[idx]->obj3D_.unknown_0_ & 0x800))
        return NULL;
    return objects_[idx];
}

// Original: arm9/main @ 0x0200FE2C; symbol: _ZN9GameState27GetMaybeFieldMonsterByIndexEi; size: 0x3C.
GameObject* GameState::GetMaybeFieldMonsterByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    if (objects_[idx] == NULL)
        return NULL;
    if (!(objects_[idx]->obj3D_.unknown_0_ & 0x20))
        return NULL;
    return objects_[idx];
}

// Original: arm9/main @ 0x0200FE68; symbol: _ZN9GameState19GetCombatantByIndexEi; size: 0x3C.
GameObject* GameState::GetCombatantByIndex(int idx)
{
    if (idx < 0)
        return NULL;
    if (idx >= 0xe9)
        return NULL;
    if (objects_[idx] == NULL)
        return NULL;
    if (!(objects_[idx]->obj3D_.unknown_0_ & 0x80))
        return NULL;
    return objects_[idx];
}
