#include <globaldefs.h>
#include "GameState/GameState.h"

typedef unsigned int undefined4;
struct Record;

// The resolved linked-stat block stores its appearance selections in bytes 20-21.
struct EquipmentPaletteSelections {
    char unknown_00_[20];
    unsigned char gender_ : 1;
    unsigned char firstPalette_ : 3;
    unsigned char secondPalette_ : 4;
    unsigned char largePalette_ : 4;
    unsigned char unknown_15_ : 4;
};

extern "C" {
int GameState_ReadProtagonistObjectIndex(GameState*);
GameObject* GameState_GetObjectWithFlag100(GameState*, int);
unsigned GameObject_GetLinkedIndexedState(int);
char* GameObject_ResolveLinkedStatsOrNull(char**);
void* CharacterPalette_GetGlobalConfiguration();
void GameState_BuildEquipmentObjectIdsAndDefaultValues(int, int*, short*);
char* CharacterState_FindEquipmentDescriptorByItemId(char*, int);
unsigned ZoneSerializedRecord_GetSelectedPaletteParameter(Record*, int, int);
void CharacterPalette_ReplaceModelPaletteSliceFromConfiguration(void*, unsigned, unsigned, unsigned);
void Graphics_ReplaceThreeIndexedModelPaletteSlices(Model3D*, int, int, int);
}

// Original: arm9/main @ 0x020730E0; symbol: func_020730e0; size: 0x160.
extern "C" ARM void PartyAppearance_ApplyEquipmentPalette(int objectIndex, int slot) {
    GameState* state = GameState::GetInstance();
    if (objectIndex < 0)
        objectIndex = GameState_ReadProtagonistObjectIndex(state);
    GameObject* object = GameState_GetObjectWithFlag100(state, objectIndex);
    if (!object || !*(char**)((char*)object + 0x154))
        return;
    // This existing accessor's owning definition uses a 32-bit integer address.
    char* indexedState = (char*)GameObject_GetLinkedIndexedState((int)object);
    if (!indexedState)
        return;
    EquipmentPaletteSelections* selections =
        (EquipmentPaletteSelections*)GameObject_ResolveLinkedStatsOrNull((char**)object);
    CharacterPalette_GetGlobalConfiguration();
    int objectIds[11];
    short itemIds[11];
    GameState_BuildEquipmentObjectIdsAndDefaultValues(objectIndex, objectIds, itemIds);
    int itemId = itemIds[slot];
    if (itemId < 0)
        return;
    char* descriptor = CharacterState_FindEquipmentDescriptorByItemId(indexedState, itemId);
    if (!descriptor)
        return;
    unsigned selected = ZoneSerializedRecord_GetSelectedPaletteParameter(
        (Record*)descriptor, 1, selections->gender_);
    GameObject* equipmentObject = state->GetGameObjectByIndex(objectIds[slot]);
    if (!equipmentObject)
        return;
    switch (slot) {
    case 0: case 1: case 5: case 6: case 7:
        CharacterPalette_ReplaceModelPaletteSliceFromConfiguration(
            equipmentObject->obj3D_.pModel_, selected, selections->firstPalette_, 4);
        break;
    case 4:
        CharacterPalette_ReplaceModelPaletteSliceFromConfiguration(
            equipmentObject->obj3D_.pModel_, selected, selections->firstPalette_, 16);
        break;
    case 2:
        Graphics_ReplaceThreeIndexedModelPaletteSlices(
            equipmentObject->obj3D_.pModel_, selections->firstPalette_,
            selections->largePalette_, selections->secondPalette_);
        break;
    }
}
