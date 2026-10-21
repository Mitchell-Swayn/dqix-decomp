struct WindowCanvasOwner;
struct WindowCanvasRecord;
struct State;
struct Owner;
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Filesystem/BackgroundLoader.h>
ARM

extern "C" {
void* GameState_GetIndexList(GameState* state);
int Input_IsKeyMaskNewlyPressed(unsigned short* p, unsigned int mask);
void* Network_GetConnectionManager();
bool Network_IsSessionActive(int* manager);
void Window_PopCanvasesAndResetSelection(State* p, int flag);
WindowCanvasRecord* Window_GetTopTextCanvas(WindowCanvasOwner* owner);
int Window_ClassifyTouchAgainstSelectedCanvas(void*);
void Window_SetCanvasEnabled(unsigned char* p, int enabled, int key);
void Bgm_StopTemporaryPlaybackAndRestoreActiveSequence(unsigned char* p);
bool Bgm_IsTemporarySequencePendingOrPlaying(char* p);
char* BattleMenu_FindPartyCommandRecord(char*, int);
int BattleMenu_HasCommandBlockingStatus(char* p);
void GameState_AppendActiveObjectRecords(Owner* p);
void BattleMenu_ConfigureGlobalCommandSelection(char* self, int value, int option);
int BattleMenu_GetSelectedEquipmentMemberIndex(void* object);
int Field_QueuePartyMemberEquipmentRefresh(unsigned char* owner, int index, int restoreFlag, int markFlag, int deferredFlag);
void Network_QueuePartyMemberLinkedStats(int index, int flag);
extern char Main_UnknownRoleZeroInitializedStorage_Variant2[];
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov000 @ 0x0217EB28; symbol: func_ov000_0217eb28; size: 0x2ac.
// Waits for any temporary BGM to finish, then on confirm/cancel keys or a kind-2
// canvas touch dismisses the global-command message. State 0x20 unwinds the
// selection stack to state 2, refreshes the selected member's equipment (and
// network stats), pops message canvases, selects the first ready party command
// member and reopens global command selection; otherwise pops one state.
extern "C" void BattleMenu_DismissGlobalCommandMessage(char* self, int a, int b) {
    if (*(unsigned char*)(self + 0x1d7a)) {
        if (Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2))
            return;
        Bgm_StopTemporaryPlaybackAndRestoreActiveSequence((unsigned char*)Main_UnknownRoleZeroInitializedStorage_Variant2);
    }

    int pressed = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x601);
    pressed |= Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x802);
    if (!(pressed | (Window_ClassifyTouchAgainstSelectedCanvas(self + 0x188) == 2)))
        return;

    if (*(signed char*)(self + *(signed char*)(self + 0x1d68) + 0x1d60) == 0x20) {
        *(unsigned char*)(self + 0x1d7a) = 0;
        while (*(signed char*)(self + 0x1d60 + *(signed char*)(self + 0x1d68)) != 2) {
            (self + 0x1d60)[*(signed char*)(self + 0x1d68)] = 0;
            (*(signed char*)(self + 0x1d68))--;
        }

        int member = BattleMenu_GetSelectedEquipmentMemberIndex(self);
        if (Network_IsSessionActive((int*)Network_GetConnectionManager()))
            Network_QueuePartyMemberLinkedStats(member, 1);
        GameResources* resources = GameResources_GetInstance();
        BackgroundLoader::GetInstance();
        Field_QueuePartyMemberEquipmentRefresh((unsigned char*)resources, member, 1, 0, 0);

        char* record = BattleMenu_FindPartyCommandRecord(self, member);
        if (!record)
            return;
        if (BattleMenu_HasCommandBlockingStatus(record)) {
            char* marked = record + *(signed char*)(record + 0x18);
            marked[0x10] = 100;
            *(unsigned char*)(record + 0x24) &= ~4;
        }
        GameState_AppendActiveObjectRecords((Owner*)record);

        WindowCanvasRecord* canvas = Window_GetTopTextCanvas((WindowCanvasOwner*)(self + 0x188));
        while (canvas) {
            if (((unsigned char*)canvas)[0xc4] == 2)
                break;
            Window_PopCanvasesAndResetSelection((State*)(self + 0x188), 0);
            canvas = Window_GetTopTextCanvas((WindowCanvasOwner*)(self + 0x188));
        }

        unsigned char count = ((unsigned char*)GameState_GetIndexList(GameState::GetInstance()))[0xf7c];
        for (unsigned char i = 0; i < count; i++) {
            int candidate = *(signed char*)(self + i + 0x70);
            char* entry = BattleMenu_FindPartyCommandRecord(self, candidate);
            if (entry && !BattleMenu_HasCommandBlockingStatus(entry) && *(unsigned char*)(entry + 0x87)) {
                *(int*)(self + 0x17c) = candidate;
                break;
            }
        }

        BattleMenu_ConfigureGlobalCommandSelection(self, a, b);
        Window_SetCanvasEnabled((unsigned char*)(self + 0x188), 1, 1);
        Window_SetCanvasEnabled((unsigned char*)(self + 0x188), 1, 2);
        Window_SetCanvasEnabled((unsigned char*)(self + 0x188), 1, 5);
        self[0x1d6b] = -1;
        self[0x1d6f] = 0;
        return;
    }

    Window_PopCanvasesAndResetSelection((State*)(self + 0x188), 0);
    char* slot = self + *(signed char*)(self + 0x1d68);
    (slot + 0x1000)[0xd60] = 0;
    *(signed char*)(self + 0x1d68) = (signed char)(*(signed char*)(self + 0x1d68) - 1);
    BattleMenu_ConfigureGlobalCommandSelection(self, a, b);
}
