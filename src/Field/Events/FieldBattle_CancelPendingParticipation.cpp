#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
ARM

struct State;
struct Queue;
struct Object;
typedef unsigned int undefined4;
extern "C" {
unsigned int TextContext_GetSharedInstance();
int GameState_ReadProtagonistObjectIndex(GameState* state);
GameObject* GameState_GetValidObjectByIndex(GameState* state, int index);
void* ColorAnimation_GetGlobalInstance();
void* SystemState_GetGlobalFlags();
void* Zone3D_GetMainInstance();
void* Script_ReadGlobalExecutionValue();
void* Text_LookupStandardString(unsigned key);
void Text_EnqueueThreeEntryMessage(Queue* self, const char* text, unsigned char category, unsigned char flag1, unsigned char deduplicate, unsigned char flag2);
void* BattleScene_GetMenuController(unsigned char* self);
void BattleMenu_RestoreSubDisplayResources(char* owner);
undefined4 ColorAnimation_GetProgress(int param_1);
int _ffix(unsigned);
void ColorAnimation_StartTimedTransition(State* p, unsigned ticks);
int GameResources_GetSelectedScreenBrightness(char* object, int alternate);
void _Z17SetMainBrightnessP13GameResourcesii(void*, int, int);
bool SystemState_TestAnyFlags(const unsigned int* word, unsigned int mask);
void SystemState_ClearFlags(unsigned int* word, unsigned int mask);
void ComputeGrottoAndContextDependentStateFlags(int mode);
undefined4 Bgm_GetPlaybackMode(int param_1);
void Bgm_ReturnToPrimaryPlayback(Object* object);
void GameResources_ClearSecondaryFlags(int self, unsigned int mask);
void GameResources_ClearPrimaryFlags(unsigned int* word, unsigned int mask);
void Network_QueueEncounterFinalization(unsigned short first, unsigned char second);
void Field_ClearMatchingPartyEncounterIds(int target, int force);
extern char Main_UnknownRoleZeroInitializedStorage_Variant2[];
}

// Original: arm9/ov017 @ 0x021B86F8; symbol: func_ov017_021b86f8; size: 0x1d8.
// Cancels a pending field-battle participation: restores menus, fades, flags and BGM, then finalizes the encounter.
extern "C" void FieldBattle_CancelPendingParticipation(unsigned char* self, unsigned memberId, int announce, unsigned char networkArg)
{
    if (*(void**)(self + 0x6ac) == 0)
        return;
    if (memberId != *(unsigned short*)(self + 0x24))
        return;
    if (*(unsigned short*)(self + 0x6b4) != 2)
        return;

    GameState* game = GameState::GetInstance();
    TextContext_GetSharedInstance();
    GameObject* protagonist = GameState_GetValidObjectByIndex(game, GameState_ReadProtagonistObjectIndex(game));
    GameResources* resources = GameResources_GetInstance();
    void* fade = ColorAnimation_GetGlobalInstance();
    unsigned int* flags = (unsigned int*)SystemState_GetGlobalFlags();
    Zone3D_GetMainInstance();

    if (protagonist != 0) {
        if (announce != 0) {
            Text_EnqueueThreeEntryMessage((Queue*)Script_ReadGlobalExecutionValue(),
                                          (const char*)Text_LookupStandardString(0x23),
                                          0, 0, 1, 1);
        }
        BattleMenu_RestoreSubDisplayResources((char*)BattleScene_GetMenuController(*(unsigned char**)(self + 0x6ac)));
    }

    if (_ffix(ColorAnimation_GetProgress((int)fade)) > 0x1e)
        ColorAnimation_StartTimedTransition((State*)fade, 0x1e);

    if (abs(GameResources_GetSelectedScreenBrightness((char*)resources, 0)) == 0x10)
        _Z17SetMainBrightnessP13GameResourcesii(resources, 0, 0x1e);

    if (SystemState_TestAnyFlags(flags, 1)) {
        SystemState_ClearFlags(flags, 1);
        ComputeGrottoAndContextDependentStateFlags(0);
    }

    if (Bgm_GetPlaybackMode((int)Main_UnknownRoleZeroInitializedStorage_Variant2) == 2)
        Bgm_ReturnToPrimaryPlayback((Object*)Main_UnknownRoleZeroInitializedStorage_Variant2);

    SystemState_ClearFlags(flags, 0x200);
    GameResources_ClearSecondaryFlags((int)resources, 0x40);
    GameResources_ClearSecondaryFlags((int)resources, 4);
    GameResources_ClearSecondaryFlags((int)resources, 0x10);
    GameResources_ClearSecondaryFlags((int)resources, 2);
    GameResources_ClearPrimaryFlags((unsigned int*)resources, 4);

    *(unsigned short*)(self + 0x6b6) |= 0x2000;
    *(unsigned short*)(self + 0x6b4) = 3;
    Network_QueueEncounterFinalization(memberId, networkArg);
    Field_ClearMatchingPartyEncounterIds(memberId, 1);
}
