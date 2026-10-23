#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
ARM
struct CombatCommandNode;
struct CombatActionRecord;
struct CombatExecutionState;
struct CombatSelectionContext;
struct State;
struct TemplateEffectCommand { unsigned char prefix[8]; const char* name; unsigned char kind; signed char slot; unsigned short templateId; unsigned char atTargets; unsigned char unknown11; short offsets[3]; short minimumValue; unsigned char detached; };
struct TemplateEffectAction { unsigned char prefix[9]; unsigned char targetCount; };
struct TemplateEffectActor { unsigned char prefix[0x20]; unsigned short actorId; };
struct TemplateEffectTarget { unsigned char prefix[0xe]; short actorId; };
struct TemplateEffectObject { unsigned char prefix[0x24]; int value; };
struct TemplateEffectDescriptor {
    char name[16]; unsigned char kind;
    unsigned char detached:1, unknownFlag1:1, attached:1, remainingFlags:5;
    short unknown12, actorId;
    unsigned char unknown16[0x16];
    Vector3fix position;
    int unknown38, heading, unknown40;
    Vector3fix scale;
};
extern "C" {
void* Object_GetGlobalSixteenEntryDisplayState();
void* Combat_GetCommandActorSnapshot(void*, int);
void* Combat_GetIndexedActionTarget(void*, int);
void Object_InitializeRenderValuesAndUnitScales(State*);
void __clear(void*, unsigned);
char* strcpy(char*, const char*);
unsigned BattleScene_GetActiveInstance();
int ObjectPool_SpawnFromTemplateKey(void*, int, void*);
void* Combat_GetDisplayRecordSlot(void*, int);
// Original data: arm9/ov025 @ 0x021EF988; symbol: data_ov025_021ef988.
extern unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
}
#pragma force_active on
// Original: arm9/ov025 @ 0x021E41A0; symbol: func_ov025_021e41a0; size: 0x2A8.
// Spawns an action effect attached to the actor or positioned at the target centroid.
extern "C" int Combat_SpawnActionEffectFromTemplate(CombatCommandNode* node, CombatActionRecord* action, CombatExecutionState*, CombatSelectionContext*)
{
    TemplateEffectCommand* command = (TemplateEffectCommand*)node;
    TemplateEffectAction* record = (TemplateEffectAction*)action;
    GameState* game = GameState::GetInstance();
    void* pool = Object_GetGlobalSixteenEntryDisplayState();
    TemplateEffectActor* actor = (TemplateEffectActor*)Combat_GetCommandActorSnapshot(record, 0);
    if (!actor) return 0;
    int actorId = actor->actorId;
    int value = ((TemplateEffectObject*)game->GetGameObjectByIndex(actorId))->value;
    if (command->minimumValue > 0 && value < command->minimumValue) return 0;
    TemplateEffectDescriptor effect;
    Object_InitializeRenderValuesAndUnitScales((State*)&effect);
    effect.attached = 0;
    int attachToActor = 1;
    if (command->atTargets & 1) {
        Vector3fix position;
        __clear(&position, sizeof(position));
        for (int i = 0; i < record->targetCount; ++i) {
            TemplateEffectTarget* target = (TemplateEffectTarget*)Combat_GetIndexedActionTarget(record, i);
            if (target) {
                GameObject* object = game->GetGameObjectByIndex(target->actorId);
                if (object) {
                    Vector3fix targetPosition = object->obj3D_.position_;
                    Vector3fix_Add(&position, &targetPosition, &position);
                    effect.scale = object->obj3D_.GetScale();
                }
            }
        }
        if (record->targetCount) {
            float reciprocal = 1.0f / (float)(unsigned)record->targetCount;
            Vector3fixMultiplyScalar(&position, (int)(4096.0f * reciprocal), &position);
        }
        TemplateEffectTarget* target = (TemplateEffectTarget*)Combat_GetIndexedActionTarget(record, 0);
        Vector3fix offset;
        offset.x = command->offsets[0]; offset.y = command->offsets[1]; offset.z = command->offsets[2];
        int party = 0;
        if (target->actorId >= 0 && target->actorId <= 3) party = 1;
        if (!party) { offset.x *= -1; offset.z *= -1; }
        Vector3fix_Add(&position, &offset, &position);
        effect.position = position;
        int partyAgain = 0;
        if (target->actorId >= 0 && target->actorId <= 3) partyAgain = 1;
        effect.heading = partyAgain ? 0x3244 : 0;
        attachToActor = 0;
    }
    if (attachToActor) effect.actorId = actorId;
    if (command->name) strcpy(effect.name, command->name);
    effect.kind = command->kind;
    effect.detached = command->detached;
    if (effect.detached) { effect.actorId = -1; effect.scale.x = 0x800; effect.scale.y = 0x800; effect.scale.z = 0x800; }
    unsigned char* scene = (unsigned char*)BattleScene_GetActiveInstance();
    *(unsigned short*)(scene + 0x6f02) = command->templateId;
    int spawned = ObjectPool_SpawnFromTemplateKey(pool, command->templateId, &effect);
    int* slot = (int*)Combat_GetDisplayRecordSlot(*(void**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc), command->slot);
    if (slot) *slot = spawned;
    return 1;
}
#pragma force_active reset
