#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Graphics/Vector.h>
ARM
struct Object;
struct StartActionCommand { unsigned short actionId; };
struct StartActionActor { unsigned char prefix[0x20]; unsigned short actorId; };
struct StartActionDefinition { unsigned char prefix[0x18]; unsigned unknown18:5, category:7, resourceType:4, remaining18:16; };
extern "C" {
void TextureVRAM_SnapshotAllocationBounds(char*);
void Combat_AllocateLinkedCommandFromThreeHalfwordQueueRecord(char*);
char* BattleScene_ResolveCurrentActionRecord(char*);
void* Combat_GetCommandActorSnapshot(void*, int);
void __clear(void*, unsigned);
void BattleScene_PrepareCommandMovement(char*);
void* GameObject_FindBattleLinkedEntryByKey(Object*, unsigned);
void* BattleScene_FindRepeatedAttackAlternateTarget(void*, char*);
int Combat_ClassifySpecialEncounterSpecies(unsigned char*);
void* CombatScript_FindCommandGroupByActionKey(void*, int);
void InitializeOverlayAllocatorAndResourceState(char*);
void Combat_BindBasePresentationAllocatorAndTextureState(void*, int, int);
void Combat_BindActionSelectionContext(void*, unsigned);
void Combat_InitializeActionPresentation(void*, void*);
void BattleScene_StartCommandMovementAndCamera(void*);
void* ActionData_GetGlobalTables();
void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(void*, int);
void BattleScene_DispatchTargetResultsByCommandCounts(void*, unsigned char*);
int sprintf(char*, const char*, ...);
void BattleScene_AdvanceActionCommand(char*);
// Original data: arm9/ov025 @ 0x021EF974; symbol: data_ov025_021ef974.
extern unsigned char BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov025 @ 0x021EF404; symbol: data_ov025_021ef404.
extern unsigned BattleSceneStartCurrentAction_UnknownRoleInitializedBytes[];
// Original data: arm9/ov025 @ 0x021EF40C; symbol: data_ov025_021ef40c.
extern char BattleScene_StartCurrentAction_PathDataSkillActsplNsarc[];
// Original data: arm9/ov025 @ 0x021EF424; symbol: data_ov025_021ef424.
extern char BattleScene_StartCurrentAction_PathDataSkillActsklNsarc[];
// Original data: arm9/ov025 @ 0x021EF43C; symbol: data_ov025_021ef43c.
extern char BattleScene_StartCurrentAction_PathDataSkillActetcNsarc[];
}
namespace {
#pragma always_inline on
inline void ClearPendingStartState(unsigned char* state)
{
    *(unsigned*)(state + 0xc) = 0;
}
inline int IsPartyActorForActionScript(unsigned actorId)
{
    int party;
    if (actorId <= 3) party = 1;
    else party = 0;
    return party;
}
}
#pragma force_active on
// Original: arm9/ov025 @ 0x021DBE10; symbol: func_ov025_021dbe10; size: 0x2C8.
// Resets action presentation state and selects a cached or asynchronously loaded action program.
extern "C" void BattleScene_StartCurrentAction(void* scene)
{
    unsigned char* self = (unsigned char*)scene;
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char* encounter = *(unsigned char**)(self + 0x29c);
    ((SafeAllocator*)(self + 0x30))->Reset();
    TextureVRAM_SnapshotAllocationBounds((char*)self + 0x14c);
    Combat_AllocateLinkedCommandFromThreeHalfwordQueueRecord((char*)self);
    StartActionCommand* command = (StartActionCommand*)BattleScene_ResolveCurrentActionRecord((char*)self);
    if (!command) return;
    StartActionActor* actor = (StartActionActor*)Combat_GetCommandActorSnapshot(command, 0);
    if (!actor) return;
    self[0x6e4b] = 0; self[0x6e4e] = 0;
    *(short*)(self + 0x6efc) = -1;
    self[0x6efe] = 0;
    *(short*)(self + 0x6fd6) = -1;
    self[0x6fd8] = 0;
    *(short*)(self + 0x6fb8) = -1;
    self[0x6f01] = 0; self[0x6fd4] = 0;
    Vector3fix zero;
    __clear(&zero, sizeof(zero));
    *(Vector3fix*)(self + 0x6fdc) = zero;
    self[0x6fe8] = 0;
    *(Vector3fix*)(self + 0x6fec) = zero;
    self[0x6ff8] = 0; self[0x6ff9] = 0;
    self[0x7744] = 0xff; self[0x7745] = 0xff; self[0x7746] = 0xff;
    self[0x5951] &= ~4;
    ClearPendingStartState(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage);
    BattleScene_PrepareCommandMovement((char*)self);
    int clearStartFlag = 1;
    GameObject* object = game->GetCombatantByIndex(actor->actorId);
    if (object) {
        unsigned actionId = command->actionId;
        if (actionId == 0x3ae) clearStartFlag = 0;
        void* groups = GameObject_FindBattleLinkedEntryByKey((Object*)object, actionId);
        void* alternate = BattleScene_FindRepeatedAttackAlternateTarget(self, (char*)*(void**)(self + 0x29c));
        if (alternate) groups = alternate;
        if (Combat_ClassifySpecialEncounterSpecies(encounter) && actor->actorId == 0) groups = CombatScript_FindCommandGroupByActionKey(*(void**)(self + 0x5724), 0xdd);
        if (groups) {
            InitializeOverlayAllocatorAndResourceState((char*)self + 0x2a8);
            Combat_BindBasePresentationAllocatorAndTextureState(self + 0x2a8, (int)(self + 0x30), (int)(self + 0x14c));
            Combat_BindActionSelectionContext(self + 0x2a8, *(unsigned*)(self + 0x29c));
            Combat_InitializeActionPresentation(self + 0x2a8, groups);
            BattleScene_StartCommandMovementAndCamera(self);
        } else {
            StartActionDefinition* definition = (StartActionDefinition*)ActionData_FindDefinitionInPrimaryOrSecondaryTable(ActionData_GetGlobalTables(), (short)actionId);
            if (definition) {
                if (definition->category == 34) BattleScene_DispatchTargetResultsByCommandCounts(self, (unsigned char*)command);
                else {
                    char filename[80];
                    if (definition->resourceType == 2) sprintf(filename, BattleScene_StartCurrentAction_PathDataSkillActsplNsarc);
                    else if ((definition->resourceType == 1 || definition->resourceType == 4) && IsPartyActorForActionScript(actor->actorId)) sprintf(filename, BattleScene_StartCurrentAction_PathDataSkillActsklNsarc);
                    else sprintf(filename, BattleScene_StartCurrentAction_PathDataSkillActetcNsarc);
                    BattleSceneStartCurrentAction_UnknownRoleInitializedBytes[0] = loader->QueueLoadFile(filename, 0);
                    *(int*)(self + 0xeac) = 4;
                }
            }
        }
    }
    if (clearStartFlag) self[0x6fd5] = 0;
    if (*(int*)(self + 0xeac) == 1) BattleScene_AdvanceActionCommand((char*)self);
}
#pragma force_active reset
