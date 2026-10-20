#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
struct Object;struct State;
ARM

extern "C" {


void* MonsterData_FindByRecordId(void*, int);
void InitializeFlag400ObjectAndEmbeddedFields(unsigned short*);
void InitializeLinkedStateBufferVectorsAndIDSentinels(Object*, State*);
void Object3D_ShallowCloneAndRebindExtendedFields(Object3D*, Object3D*);

void GameObject_BuildDisplayNameWithInstanceSuffix(char*);
void* MonsterBattleData_FindEntryById(void*, int);
void GameObject_ReplaceNameRecordPreservingName(unsigned char*, unsigned char*);

void GameObject_SetBattleMotionExclusionFlag80(char*);
void GameObject_SetBattleMotionFlag200(unsigned char*);
void GameObject_SetMotionStateAndRefreshAnimation(unsigned char*, unsigned char);
void GameState_SetIndexedObjectAndSlot(GameState*, int, GameObject*);
void Graphics_AssignPaletteToEligibleTextureRecord(void*, char*, char*);
int AssignCombatantToFirstRadiusCompatibleSlot(char*, int);

void Field_UpdateCombatantAppearanceFlags(void*, int, int, unsigned);
}

// Original: arm9/ov000 @ 0x02166540; symbol: BattleScene_CloneMonsterIntoCombatantSlot; size: 0x244.
// Creates an indexed object from the matching source record and registers its linked state.
extern "C" void BattleScene_CloneMonsterIntoCombatantSlot(
    unsigned char* self, int index, int sourceKey, unsigned char value) {
    if (index < 0xc0 || index > 0xc7) return;

    GameState* gameState = GameState::GetInstance();
    GameResources* gameResources = GameResources_GetInstance();
    unsigned char* recordTable = *(unsigned char**)(self + 0x2a0) + 0x278;
    int relativeIndex = index - 0xc0;
    void* sourceRecord = 0;
    for (int i = 0; i < 4; ++i) {
        void* candidate = *(void**)(self + 0xeb8 + i * 4);
        if (candidate && sourceKey == *(short*)((unsigned char*)candidate + 2)) {
            sourceRecord = candidate;
            break;
        }
    }
    if (!sourceRecord) return;

    unsigned char* destination = self + 0x5e24 + relativeIndex * 0x190;
    if (!destination) return;
    InitializeFlag400ObjectAndEmbeddedFields((unsigned short*)destination);
    unsigned char* linkedState = self + 0x6aa4 + relativeIndex * 0x70;
    if (!linkedState) return;
    InitializeLinkedStateBufferVectorsAndIDSentinels((Object*)destination, (State*)linkedState);
    destination[0xc2] |= 0x20;
    Object3D_ShallowCloneAndRebindExtendedFields((Object3D*)sourceRecord, (Object3D*)destination);
    ((Object3D*)destination)->SetField06(*(unsigned short*)(self + 0xec8));
    destination[0x17c] = value;
    unsigned char* destinationRecordBase = *(unsigned char**)(self + 0x2a0) + 0x158;
    *(unsigned char**)(destination + 0x138) = destinationRecordBase + relativeIndex * 0xa4;
    GameObject_BuildDisplayNameWithInstanceSuffix((char*)destination);

    unsigned char* destinationRecord = *(unsigned char**)(destination + 0x138);
    unsigned short replacementKey = *(unsigned short*)(destinationRecord + 0x36);
    if (replacementKey != 0) {
        void* replacement = MonsterBattleData_FindEntryById(*(unsigned char**)(self + 0x2a0) + 0x684, replacementKey);
        if (replacement) GameObject_ReplaceNameRecordPreservingName(destination, (unsigned char*)replacement);
    }
    ((Object3D*)destination)->EnableFlag(8);

    unsigned short* linkedComponent = *(unsigned short**)((unsigned char*)sourceRecord + 0xb0);
    if (linkedComponent) {
        if (((unsigned)*(unsigned*)(linkedComponent + 8) << 3) >> 31 == 0) {
            GameObject_SetBattleMotionExclusionFlag80((char*)destination);
        }
        if (((unsigned)*linkedComponent << 16) >> 31 == 0) {
            GameObject_SetBattleMotionFlag200(destination);
        }
    }

    void* keyedRecord = MonsterData_FindByRecordId(recordTable + 0x400, (short)sourceKey);
    if (keyedRecord) {
        int scaledKey = *(short*)((unsigned char*)keyedRecord + 0xc) * 4;
        unsigned short fieldValue = 0x324;
        if (scaledKey >= 0x4000) fieldValue = 0xc9;
        else if (scaledKey >= 0x3000) fieldValue = 0x10c;
        else if (scaledKey >= 0x2000) fieldValue = 0x192;
        *(unsigned short*)(destination + 0xb0) = fieldValue;
    }

    GameObject_SetMotionStateAndRefreshAnimation(destination, 0);
    GameState_SetIndexedObjectAndSlot(gameState, index, (GameObject*)destination);
    Graphics_AssignPaletteToEligibleTextureRecord(self, (char*)sourceRecord, (char*)destination);
    AssignCombatantToFirstRadiusCompatibleSlot((char*)self, index);

    void* combatant = gameState->GetCombatantByIndex(index);
    if (combatant && ((*(unsigned*)(*(unsigned char**)((unsigned char*)combatant + 0x138) + 0x14)) & 0x01000000)) {
        Field_UpdateCombatantAppearanceFlags(gameResources, 1, index, 4);
    }
}
