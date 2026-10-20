#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
struct GameResources;
struct State;
struct LoaderTaskOwner;
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" GameResources* GameResources_GetInstance();
extern "C" void QuestMessagePanel_RequestAlternateTransition(unsigned char*);
extern "C" void QuestMessagePanel_UpdateAndDrawIndicators(void*, unsigned);
extern "C" void BackgroundLoader_RemoveTasksDestroyAllocatorsAndResetGraphicsState(State*);
extern "C" unsigned GameResources_GetMaskedPrimaryFlags(unsigned*, unsigned);
extern "C" unsigned DisplayContext_GetGlobalInstance();
extern "C" void DisplayContext_IgnoreHook(void*);
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(LoaderTaskOwner*);
extern "C" void DisplayContext_IgnoreCommand(void*, int, int, int, int);
extern "C" int Event_SelectScriptEntryAndRefreshSessions(void*);
// Original: arm9/ov001 @ 0x02156108; symbol: func_ov001_02156108; size: 0xd8.
// Closes an attached message panel, requests the display transition, and activates the exit script.
extern "C" unsigned Event_CloseScenePanelAndActivateExitScript(char* self) {
    GameState* game = GameState::GetInstance();
    char* text = (char*)TextContext_GetSharedInstance();
    GameResources* resources = GameResources_GetInstance();
    if ((*(unsigned short*)(self + 0x50) & 2) || (*(unsigned short*)(self + 0x50) & 8)) {
        unsigned char* panel = *(unsigned char**)(self + 0x120);
        if (panel) {
            if (*(short*)(panel + 0xd2) >= 0) {
                QuestMessagePanel_RequestAlternateTransition(panel);
                QuestMessagePanel_UpdateAndDrawIndicators(*(void**)(self + 0x120), game->GetTickCount());
                return *(unsigned short*)(self + 10);
            }
            BackgroundLoader_RemoveTasksDestroyAllocatorsAndResetGraphicsState((State*)panel);
        }
        *(unsigned*)(text + 0x8c) = 0;
        *(void**)(self + 0x120) = 0;
    }
    if (!GameResources_GetMaskedPrimaryFlags((unsigned*)resources, 0x1000)) {
        void* display = (void*)DisplayContext_GetGlobalInstance();
        DisplayContext_IgnoreHook(display);
        BackgroundLoader_CancelEightTasksAndResetState((LoaderTaskOwner*)display);
        DisplayContext_IgnoreCommand(display, 111, 5000, 1, 1);
    }
    self[0xfe] = 0;
    Event_SelectScriptEntryAndRefreshSessions((void*)(unsigned)*(unsigned short*)(self + 0x4e));
    return 11;
}
